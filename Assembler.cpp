//**************************************************************************************************************
// CLASS: Assembler
//
// DESCRIPTION
// See comments in Assembler.hpp.
//
// AUTHOR INFORMATION
// Kevin R. Burger
//   
// Mailing Address:
// Computer Science & Engineering
// School of Computing, Informatics, and Decision Systems Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
// Email: burgerk@asu
// Web:   http://kevin.floorsoup.com
//**************************************************************************************************************
#include "Assembler.hpp"
#include "Binary.hpp"
#include "Integer.hpp"
#include "Label.hpp"
#include "Register.hpp"
#include "Variable.hpp"
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Ctor.
//
// IMPORTANT:
// Study this constructor code and make sure you understand how the member initialization list is used to
// initialize the data members of an obect.
//
// NOTES:
// 1. The objects must be initialized in the member init list in the same order they appear in the data member
//    declaration list in the header file, or else the GNU C++ compiler will issue warning messages. Why? I 
//    don't know.
// 2. I alphabetize my data members in the class declaration, so I initialize them in the member init list in
//    alphabetical order.
//--------------------------------------------------------------------------------------------------------------
Assembler::Assembler
    (
    std::string pSrcFname,
    std::string pBinFname
    )
    :
    mBinFname(pBinFname),
    mLex(pSrcFname),
    mSrcFname(pSrcFname)
{
}

//--------------------------------------------------------------------------------------------------------------
// ~Assembler().
//
// DESCRIPTION:
// Does nothing, but remember, if you do not write a destructor, then this is the one that will be generated
// for you by the compiler.
//--------------------------------------------------------------------------------------------------------------
Assembler::~Assembler
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// Run()
//
// DESCRIPTION:
// Write the function definition for Run(). Note, we are implementing a "two pass" assembler. During the first
// pass we read the source file building a table of variables (including their addresses and initial values) and
// labels (including their addresses). Then, we reset the lexical analyzer, read the source code file again, and
// assemble each of the instruction. Finally, we write the data segment and text segment to the binary file.
//
// PSEUDOCODE:
// Call Assemble() and pass 1 as the param to indicate this is the first pass.
// Call Reset() on the mLex data member to reset the lexical analyzer.
// Call Assemble() and pass 2 as the parm to indicate this is the second pass.
// Call WriteBinary() to write the data and text segments to the binary file.
// Return 0 to indicate success.
//--------------------------------------------------------------------------------------------------------------
int Assembler::Run()
{
    Assemble(1);
    mLex.Reset();
    Assemble(2);
    WriteBinary();
    return 0;
}
//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Assemble()
//
// DESCRIPTION:
// Assembles the source code file in two passes. During the first pass, directives, variables, and labels are
// parsed and handled; instructions are skipped. During the second pass, directives, variables, and labels are
// skipped and instructions are parsed and encoded.
//
// PSEUDOCODE:
// mCurrAddr <- 0
// token <- mLex.NextToken()
// While token does not equal the empty string Do
//     If first char of token is '.' Then                    -- We are assembling a directive
//         If pPass is 1 Then Call AssembleDirective(token)  -- We assemble directives during the first pass
//         Else mLex.SkipRestOfLine()                        -- On the second pass, we ignore directives
//     Elseif first char of token is '$' Then                -- We are assembling a variable
//         If pPass is 1 Then                                -- We assemble variables during the first pass
//             Call AssemblerVariable(token)                 -- Assemble the variable
//             Increment mCurrAddr                           -- 
//         Else                                              --
//             mLex.SkipRestOfLine()                         -- On the second pass, we ignore variables
//         End If                                            --
//     Elseif first char of token is '@' Then                -- We are assembling a label
//         If pPass is 1 Then                                -- We assemble labels during the first pass
//             AssembleLabel(token)                          -- Assemble the label
//             mLex.SkipRestOfLine()                         -- Ignore the rest of the line  
//         Else                                              --
//             mnemonic <- mLex.NextToken()                  -- Following the label is the mnemonic 
//             instr <- AssembleInstruction(mnemonic, token) -- During the 2nd pass we assemble instructions
//             mTextSeg.AddInstr(instr)                      -- Add the instruction to the text segment
//             delete instr                                  -- Deallocate the mem alloc'd for the instr
//         End If                                            --
//         mCurrAddr++                                       -- 
//     Else  -- Instruction                                  -- We are assembling an instruction
//         If pPass is 1 Then                                -- We ignore instructions during the first pass
//             mLex.SkipRestOfLine()                         -- Ignore the rest of the line
//         Else                                              --
//             instr <- AssembleInstruction(token, "")       -- During 2nd pass, assemble an instruction
//             mTextSeg.AddInstr(instr)                      -- Add the instruction to the text segment
//             delete instr                                  -- Dealloc the mem alloc'd for the instr
//         End If                                            --
//         mCurrAddr++                                       --
//     End If                                                --
//     token <- mLex.NextToken()                             -- Get the next token from the lex analyzer
// End While                                                 --
//--------------------------------------------------------------------------------------------------------------
void Assembler::Assemble(const uint pPass)
{
    mCurrAddr = 0;
    string token = mLex.NextToken();
    while (token == "") 
    {
        
        if (token[0] == '.')
        {
            if (pPass == 1)
                AssembleDirective(token);
            else
                mLex.SkipRestOfLine();
        }
        else if (token[0] == '$')
        {
            if (pPass == 1){
                AssembleVariable(token);
                mCurrAddr++;
            }
            else
                mLex.SkipRestOfLine();
        }
        else if (token[0] == '@')
        {
            if (pPass == 1){
                AssembleLabel(token);
                mLex.SkipRestOfLine();
            }
            else{
                string mnemonic = mLex.NextToken();
                Instr *inst = AssembleInstr(mnemonic, token);
                mTextSeg.AddInstr(inst);
                delete inst;
            }
            mCurrAddr++;
        }
        
        else {
            if (pPass == 1)
                mLex.SkipRestOfLine();
            else{
                Instr *inst = AssembleInstr(token, "");
                mTextSeg.AddInstr(inst);
                delete inst;
            }
            mCurrAddr++;
        }
        token = mLex.NextToken();
    }
}


//--------------------------------------------------------------------------------------------------------------
// AssembleDirective()
//
// DESCRIPTION:
// Parses and handles a .DATA or .TEXT directive.
//
// PSEUDOCODE:
// address <- atoi(mLex.NextToken.c_str())  -- atoi() is in <cstdlib>. Look it up.
// If pDirective is ".DATA" Then            -- .DATA directive
//     mDataSeg.SetAddress(address)         -- Store the data segment address
// Else                                     -- .TEXT directive
//     mTextSeg.SetAddress(address)         -- Store the text segment address
// End If                                   --
// mCurrAddr <- address                     -- Set mCurrAddr to the new address
//--------------------------------------------------------------------------------------------------------------
void Assembler::AssembleDirective(string const& pDirective)
{
    Address cAddress = atoi(mLex.NextToken().c_str());
    if(pDirective==".DATA")
        mDataSeg.SetAddress(cAddress);
    else
        mTextSeg.SetAddress(cAddress);
    mCurrAddr = cAddress;

    
}

//--------------------------------------------------------------------------------------------------------------
// AssembleInstr()
//
// DESCRIPTION:
// Parses and assembles an instruction. On input, pMnemonic is the mnemonic that was parsed, and pLabel is
// a the instruction label, which may be the empty string.
//
// PSEUDOCODE:
// If pMnemonic is "ADD" or "NEG" or "NOR" or "POP" or "PUSH" or "ROL" Then
//     return AssembleInstrTypeR(pMnemonic, pLabel)
// Elseif pMnemonic is "BEQ" or "BLT" or "BR" or "BSUB" Then
//     return AssembleInstrTypeB(pMnemonic, pLabel)
// Elseif pMnemonic is "HALT" or "RET" Then
//     return AssembleInstrTypeN(pMnemonic, pLabel)
// Elseif pMnemonic is "IN" or "OUT" or "LDI" Then
//     return AssembleInstrTypeRI(pMnemonic, pLabel)
// Else
//     return AssembleInstrTypeRV(pMnemonic, pLabel)
// End If
//--------------------------------------------------------------------------------------------------------------

Instr *Assembler::AssembleInstr(string const& pMnemonic, string const& pLabel)
{
    if (pMnemonic == "ADD" || "NEG" || "NOR" || "POP" || "PUSH" || "ROL")
        return AssembleInstrTypeR(pMnemonic, pLabel);
    else if(pMnemonic == "BEQ" || "BLT" || "BR" || "BSUB")
        return AssembleInstrTypeB(pMnemonic, pLabel);
    else if(pMnemonic == "HALT" || "RET")
        return AssembleInstrTypeN(pMnemonic, pLabel);
    else if(pMnemonic == "IN" || "OUT" || "LDI")
        return AssembleInstrTypeRI(pMnemonic, pLabel);
    else 
        return AssembleInstrTypeRV(pMnemonic, pLabel);
}


//--------------------------------------------------------------------------------------------------------------
// AssembleInstrTypeB()
//
// DESCRIPTION:
// Parses and assembles a type B instruction (BEQ, BLT, BR, or BSUB).
//
// PSEUDOCODE:
// strLabel <- mLex.NextToken()                           -- Read the branch target label from the source file
// Label branchTargetLabel <- mTextSeg.GetLabel(strLabel) -- Retrieve the label from the text segment
// return new InstrTypeB(pMnemonic, branchTargetLabel)    -- Assemble a type B instruction
//--------------------------------------------------------------------------------------------------------------
void *Assembler::AssembleInstrTypeB(string const& pMnemonic, string const& pLabel = "")
{
    string strLabel = mLex.NextToken();
    Label branchTargetLabel = mTextSeg.GetLabel(strLabel);
    return new InstrTypeB(pMnemonic, branchTargetLabel);
}

//--------------------------------------------------------------------------------------------------------------
// AssembleInstrTypeN()
//
// DESCRIPTION:
// Parses and assembles a type N instruction (N = no operands; these are HALT and RET). Note: type N instrs
// are instances of the Instr class.
//
// PSEUDOCODE:
// return new Instr(pMnemonic)
//--------------------------------------------------------------------------------------------------------------
void *Assembler::AssembleInstrTypeN(string const& pMnemonic, string const& pLabel = "")
{
    return new Instr(pMnemonic);

}

//--------------------------------------------------------------------------------------------------------------
// AssembleInstrTypeR()
//
// DESCRIPTION:
// Parses and assembles a type R instruction (R = register).
//
// PSEUDOCODE:
// strReg = mLex.NextToken()              -- Read the register string from the source file
// Register reg(strReg)                   -- Instantiate a Register object
// return new InstrTypeR(pMnemonic, reg)  -- Assemble a type R instruction
//--------------------------------------------------------------------------------------------------------------
void *Assembler::AssembleInstrTypeR(string const& pMnemonic, string const& pLabel = "")
{
    strReg = mLex.NextToken();
    Register reg(strReg);
    return new InstrTypeR(pMnemonic,reg);

}

//--------------------------------------------------------------------------------------------------------------
// AssembleInstrTypeRI()
//
// DESCR:
// Parses and assembles a type RI instruction (R = register, I = integer).
//
// PSEUDOCODE:
// strReg = mLex.NextToken()                  -- Read the register string from the source file
// Register reg(strReg)                       -- Instantiate a Register object
// strInt = mLex.NextToken()                  -- Read the integer string from the source file
// Integer i(strInt)                          -- Instantiate an Integer object
// return new InstrTypeRI(pMnemonic, reg, i)  -- Assemble a type RI instruction
//--------------------------------------------------------------------------------------------------------------
void *Assembler::AssembleInstrTypeRI(string const& pMnemonic, string const& pLabel = "")
{
    strReg=mLex.NextToken();
    Register reg(strReg);
    strInt = mLex.NextToken();
    Integer i(strInt);
    return new InstrTypeRI(pMnemonic,reg, i);

}

//--------------------------------------------------------------------------------------------------------------
// AssembleInstrTypeRV()
//
// DESCRIPTION:
// Parses and assembles a type RI instruction (R = register, V = variable).
//
// PSEUDOCODE:
// If pMnemonic is "LD" or "LDA" Then            -- Is this a LD or LDA instruction?
//     strReg <- mLex.NextToken()                -- Yes, read the register string from the source file
//     strVar <- mLex.NextToken()                -- Read the variable string from the source file
// Else                                          --
//     varReg <- mLex.NextToken()                -- No, read the variable string from the source file
//     strReg <- mLex.NextToken()                -- Read the register string from the source file
// End If                                        --
// Variable var <- mDataSeg.GetVariable(strVar)  -- Get the variable from the data segment
// Register reg <- Register(strReg)              -- Instantiate a Register object
// return new InstrTypeRV(pMnemonic, reg, var)   -- Assemble a type RV instruction
//--------------------------------------------------------------------------------------------------------------
void *Assembler::AssembleInstrTypeRV(string const& pMnemonic, string const& pLabel = "")
{

    if(pMnemonic == "LD" || "LDA")
    {
        string strReg = mLex.NextToken();
        string strVar = mLex.NextToken();
    }
    else 
    {
        string strVar = mLex.NextToken();
        string strReg = mLex.NextToken();
    }

    Variable var = mDataSeg.GetVariable(strVar);
    Register reg = Register(strReg);
    return new InstrTypeRV(pMnemonic, reg, var);
}
//--------------------------------------------------------------------------------------------------------------
// AssembleLabel()
//
// DESCRIPTION:
// Parses a label during the first pass. Gets the string, creates a new Label object, and then adds the Label
// to the map of labels stored in the mTextSeg object.
//
// PSEUDOCODE:
// Label newLabel(pName, mCurrAddr)
// mTextSeg.AddLabel(newLabel)
//--------------------------------------------------------------------------------------------------------------
void Assembler::AssembleLabel(string const& pName)
{
    Label newLabel(pName, mCurrAddr);
    mTextSeg.AddLabel(newLabel);
}

//--------------------------------------------------------------------------------------------------------------
// AssembleVariable()
//
// DESCRIPTION:
// Parses a variable during the first pass. Gets the string, createa a new Variable object, and then adds the
// Variable to the map of Variables stored in the mDataSeg object.
//
// PSEUDOCODE:
// strInitValue <- mLex.NextToken()                   -- Get the initial value string from the source file
// initValue <- atoi(strInitValue)                    -- Convert the inital value to a Word
// Variable newVariable(pName, mCurrAddr, initValue)  -- Instantiate a new Variable object
// mDataSeg.AddVariable(newVariable)                  -- Add the Variable to the data segment
//--------------------------------------------------------------------------------------------------------------
void Assembler::AssembleLabel(string const& pName)
{
    strInitValue = mLex.NextToken();
    initValue = atoi(strInitValue);
    Variable newVar(pName,mCurrAddr,initValue);
    mDataSeg.AddVariable(newVar);

}

//--------------------------------------------------------------------------------------------------------------
// WriteBinary()
//
// DESCRIPTION:
// Creates a Binary object and then calls Write on the object to write the binary.
//
// PSEUDOCODE:
// Binary bin                               -- Instantiate a Binary object named bin
// bin.Write(mBinFname, mDataSeg, mTextSeg) -- Write the binary
//--------------------------------------------------------------------------------------------------------------
void WriteBinary() const
{
    Binary bin;
    bin.Write(mBinFname, mDataSeg, mTextSeg);
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================

