//**************************************************************************************************************
// CLASS: Instr
//
// DESCRIPTION
// See comments in Instr.hpp.
//
// AUTHOR INFORMATION
// Kevin R. Burger [KRB]
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
#include "Instr.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Initializes the mMnemonic data member in the member init list.
//--------------------------------------------------------------------------------------------------------------
Instr::Instr
    (
    std::string const& pMnemonic
    )
    :
    mMnemonic(pMnemonic)
{
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//--------------------------------------------------------------------------------------------------------------
Instr::Instr
    (
    Instr const& pInstr
    )
{
    Copy(pInstr);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//--------------------------------------------------------------------------------------------------------------
Instr::~Instr
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// Encode()
//
// DESCRIPTION:
// When an Instr is encoded, we place the opcode bits in the most significant five bits of mEncoding.
//
// IMPORTANT:
// Note that this function is called by the Encode() function of derived classes. See InstrTypeB::Encode()
// for example.
//--------------------------------------------------------------------------------------------------------------
void Instr::Encode
    (
    )
{
    mEncoding = GetOpcode() << 27;
}

//--------------------------------------------------------------------------------------------------------------
// GetEncoding()
//
// DESCRIPTION:
// mEncoding accessor function.
//--------------------------------------------------------------------------------------------------------------
Word Instr::GetEncoding
    (
    )
    const
{
    return mEncoding;
}

//--------------------------------------------------------------------------------------------------------------
// GetMnemonic()
//
// DESCRIPTION:
// mMnemonic accessor function.
//--------------------------------------------------------------------------------------------------------------
std::string Instr::GetMnemonic
    (
    )
    const
{
    return mMnemonic;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
Instr& Instr::operator=
    (
    Instr const& pInstr
    )
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

//--------------------------------------------------------------------------------------------------------------
// SetMnemonic()
//
// DESCRIPTION:
// mMnemonic mutator function.
//--------------------------------------------------------------------------------------------------------------
void Instr::SetMnemonic
    (
    std::string const& pMnemonic
    )
{
    mMnemonic = pMnemonic;
}

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes this Instr a copy of pInstr.
//--------------------------------------------------------------------------------------------------------------
void Instr::Copy
    (
    Instr const& pInstr
    )
{
    
    SetMnemonic(pInstr.mMnemonic);
    SetEncoding(pInstr.mEncoding);
}

//--------------------------------------------------------------------------------------------------------------
// GetOpcode()
//
// DESCRIPTION:
// Returns the opcode bits corresponding to the mnemonic.
//--------------------------------------------------------------------------------------------------------------
Byte Instr::GetOpcode
    (
    )
    const
{
    if (mMnemonic == "ADD")       return OPCODE_ADD;
    else if (mMnemonic == "BEQ")  return OPCODE_BEQ;
    else if (mMnemonic == "BLT")  return OPCODE_BLT;
    else if (mMnemonic == "BR")   return OPCODE_BR;
    else if (mMnemonic == "BSUB") return OPCODE_BSUB;
    else if (mMnemonic == "HALT") return OPCODE_HALT;
    else if (mMnemonic == "IN")   return OPCODE_IN;
    else if (mMnemonic == "LD")   return OPCODE_LD;
    else if (mMnemonic == "LDA")  return OPCODE_LDA;
    else if (mMnemonic == "LDI")  return OPCODE_LDI;
    else if (mMnemonic == "NEG")  return OPCODE_NEG;
    else if (mMnemonic == "NOR")  return OPCODE_NOR;
    else if (mMnemonic == "OUT")  return OPCODE_OUT;
    else if (mMnemonic == "POP")  return OPCODE_POP;
    else if (mMnemonic == "PUSH") return OPCODE_PUSH;
    else if (mMnemonic == "RET")  return OPCODE_RET;
    else if (mMnemonic == "ROL")  return OPCODE_ROL;
    else if (mMnemonic == "ST")   return OPCODE_ST;
    else return 0xFF;
}

//--------------------------------------------------------------------------------------------------------------
// SetEncoding()
//
// DESCRIPTION:
// mEncoding mutator function.
//--------------------------------------------------------------------------------------------------------------
Instr& Instr::SetEncoding
    (
    Word const pEncoding
    )
{
    mEncoding = pEncoding;
    return *this;
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================

