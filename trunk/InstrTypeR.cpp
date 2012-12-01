//**************************************************************************************************************
// CLASS: InstrTypeR
//
// DESCRIPTION
// See comments in InstrTyprR.hpp.
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
#include "InstrTypeR.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Does nothing.
//--------------------------------------------------------------------------------------------------------------
InstrTypeR::InstrTypeR()
{
    
}

//--------------------------------------------------------------------------------------------------------------
// Another ctor.
//
// DESCRIPTION:
// Since InstrTypeR is derived from Instr, then we call the base class ctor Instr::Instr(string const&) in the
// member init list to let it initialize the mMnemonic data member. Then we initialize mRegister to pRegister
// (either in the ctor body or in the member init list).
//
// HINT:
// See InstrTypeB::InstrTypeB(std::string const&, Label const&) for how to call the base class ctor.
//--------------------------------------------------------------------------------------------------------------
InstrTypeR::InstrTypeR(std::string const& pMnemonic, Register const& pReg):
Instr(pMnemonic), mRegister(pReg)
{
    
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//
// DESCRIPTION:
// Calls Copy() and passes pInstr to make this object a copy of pInstr.
//--------------------------------------------------------------------------------------------------------------
InstrTypeR::InstrTypeR(InstrTypeR const& pInstr)
{
    Copy(pInstr);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// Does nothing.
//--------------------------------------------------------------------------------------------------------------
InstrTypeR::~InstrTypeR()
{
    
    
}

//--------------------------------------------------------------------------------------------------------------
// Encode()
//
// DESCRIPTION:
// When an InstrTypeR is encoded, we first call the base class Instr::Encode() function to allow it to place 
// the opcode bits in the most significant five bits of mEncoding. Then we place the register number in bit
// position 26 of the encoding.
//
// IMPORTANT:
// Study the relationship between this function and Instr::Encode().
//--------------------------------------------------------------------------------------------------------------
void InstrTypeR::Encode
    (
    )
{
    Instr::Encode();
    mEncoding |= mRegister.GetEncoding() << 26;
}

//--------------------------------------------------------------------------------------------------------------
// GetRegister()
//
// DESCRIPTION:
// mRegister accessor function.
//--------------------------------------------------------------------------------------------------------------
Register InstrTypeR::GetRegister() const
{
    return mRegister;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
InstrTypeR& InstrTypeR::operator=(InstrTypeR const& pInstr)
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes 'this' InstrTypeR object a copy of pInstr.
//
// IMPORTANT:
// Note how we call the base class (Instr) Copy() function to allow it to copy the mEncoding and mMnemonic data
// members that are inherited fomr the base class. Then we copy the register from pInstr into our mRegister data
// member. Finally, we encode the instruction so the mEncoding data member will have the correct bits in the
// proper positions.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeR::Copy
    (
    InstrTypeR const& pInstr
    )
{
    // Copy the base class (Instr) data members to 'this'.
    Instr::Copy(pInstr);                               

    // Copy the derived class (InstrTypeR) data members to 'this'.
    SetRegister(pInstr.GetRegister());

    // Encode because the register has changed.
    Encode();
}

//--------------------------------------------------------------------------------------------------------------
// SetRegister()
//
// DESCRIPTION:
// mRegister mutator function.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeR::SetRegister(const Register &pRegister)
{
    mRegister = pRegister;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================

