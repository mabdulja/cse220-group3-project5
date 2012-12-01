//**************************************************************************************************************
// CLASS: InstrTypeRV
//
// DESCRIPTION
// See comments in InstrTypeRV.hpp.
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
#include "InstrTypeRV.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Does nothing.
//--------------------------------------------------------------------------------------------------------------
InstrTypeRV::InstrTypeRV
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// Ctor.
//
// DESCRIPTION:
// Calls the base class InstrTypeR::InstrTypeR(string const&, Register const&) ctor to allow that ctor to init
// the data members it contributes to this object. Then initialze mVariable to pVariable.
//--------------------------------------------------------------------------------------------------------------
InstrTypeRV::InstrTypeRV
    (
    std::string const& pMnemonic,
    Register const&    pRegister,
    Variable const&    pVariable
    )
    :
    InstrTypeR(pMnemonic, pRegister)
{
    mVariable = pVariable;
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//--------------------------------------------------------------------------------------------------------------
InstrTypeRV::InstrTypeRV
    (
    InstrTypeRV const& pInstr
    )
{
    Copy(pInstr);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//--------------------------------------------------------------------------------------------------------------
InstrTypeRV::~InstrTypeRV
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// Encode()
//
// DESCRIPTION:
// Calls the base class Encode() function to allow it to encode it's part of the encoding. Then we put the
// address of the variable into mEncoding.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeRV::Encode
    (
    )
{
    InstrTypeR::Encode();
    mEncoding |= mVariable.GetAddress();
}

//--------------------------------------------------------------------------------------------------------------
// GetVariable()
//
// DESCRIPTION:
// mVariable accessor function.
//--------------------------------------------------------------------------------------------------------------
Variable InstrTypeRV::GetVariable
    (
    )
    const
{
    return mVariable;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
InstrTypeRV& InstrTypeRV::operator=
    (
    InstrTypeRV const& pInstr
    )
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
// Makes this InstrTypeRV object a copy of pInstr.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeRV::Copy
    (
    InstrTypeRV const& pInstr
    )
{
    // Copy the base class (InstrTypeR) data members to 'this'.
    InstrTypeR::Copy(pInstr);                               

    // Copy the derived class (InstrTypeRV) data members to 'this'.
    SetVariable(pInstr.GetVariable());

    // Encode the instruction because the Variable has changed.
    Encode();
}

//--------------------------------------------------------------------------------------------------------------
// SetVariable()
//
// DESCRIPTION:
// mVariable mutator function.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeRV::SetVariable
    (
    Variable const& pVariable
    )
{
    mVariable = pVariable;
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================
