//**************************************************************************************************************
// CLASS: InstrTypeRI
//
// DESCRIPTION
// See comments in InstrTypeRI.hpp.
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
#include "InstrTypeRI.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Does nothing.
//--------------------------------------------------------------------------------------------------------------
InstrTypeRI::InstrTypeRI()
{
    
}

//--------------------------------------------------------------------------------------------------------------
// Another ctor.
//
// DESCRIPTION:
// Call the base class InstrTypeR::InstrTypeR(string const&, Register const&) ctor to let it initialize the
// mMnemonic and mRegister data members that were inherited from Instr and InstrTypeR. Then initialize mInteger
// to pInteger (either in the ctor body or the member init list).
//--------------------------------------------------------------------------------------------------------------
InstrTypeRI::InstrTypeRI(string const& pMnemonic, Register const& pReg, Integer const& pInt):
InstrTypeR(pMnemonic, pReg)
{
    InstrTypeRI::mInteger = pInt;
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//
// DESCRIPTION:
// Calls Copy() and passess pInstr to make this object a copy of pInstr.
//--------------------------------------------------------------------------------------------------------------
InstrTypeRI::InstrTypeRI(InstrTypeRI const& pInstr)
{
    InstrTypeRI::Copy(pInstr);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// Does nothing.
//--------------------------------------------------------------------------------------------------------------
InstrTypeRI::~InstrTypeRI()
{
    
}

//--------------------------------------------------------------------------------------------------------------
// Encode()
//
// DESCRIPTION:
// When an InstrTypeRI is encoded, we first call the base class InstrTypeR::Encode() function to allow it to
// place the register bit in position 26 (note that InstrTypeR::Encode() calls Instr::Encode() to allow that
// function to encode the opcode bits). Then we place the integer bits into the encoding.
//
// PSEUDOCODE:
// Call InstrTypeR::Encode()
// Put the immediate into the proper bit positions of mEncoding.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeRI::Encode
(
)
{
    InstrTypeR::Encode();
    mEncoding |= mInteger.GetValue();
}

//--------------------------------------------------------------------------------------------------------------
// GetInteger()
//
// DESCRIPTION:
// mInteger accessor function.
//--------------------------------------------------------------------------------------------------------------
Integer InstrTypeRI::GetInteger() const
{
    return InstrTypeRI::mInteger;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
InstrTypeRI& InstrTypeRI::operator=(InstrTypeRI const& pInstr)
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes this InstrTypeRI a copy of pInstr.
//
// PSEUDOCODE:
// Call the base class Copy() function and pass pInstr as the param
// Copy the mInteger data member of pInteger to this object's mInteger data member
// Call Encode() to encode the instruction
//--------------------------------------------------------------------------------------------------------------
void InstrTypeRI::Copy
(
 InstrTypeRI const& pInstr
 )
{
    // Copy the base class (Instr) data members to 'this'.
    InstrTypeRI::Copy(pInstr);
    
    // Copy the derived class (InstrTypeR) data members to 'this'.
    SetRegister(pInstr.GetRegister());
    
    // Encode because the register has changed.
    Encode();
}

//--------------------------------------------------------------------------------------------------------------
// SetInteger()
//
// DESCRIPTION:
// mInteger mutator function.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeRI::SetInteger(const Integer &pInteger)
{
    InstrTypeRI::mInteger = pInteger;
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================
