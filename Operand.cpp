//**************************************************************************************************************
// CLASS: Operand
//
// DESCRIPTION
// See comments in Operand.hpp.
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
#include "Operand.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//--------------------------------------------------------------------------------------------------------------
Operand::Operand
    (
    std::string const& pOpString
    )
    :
    mOpString(pOpString)
{
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//--------------------------------------------------------------------------------------------------------------
Operand::Operand
    (
    Operand const& pOperand
    )
{
    Copy(pOperand);
}

//--------------------------------------------------------------------------------------------------------------
// Pure virtual dtor.
//--------------------------------------------------------------------------------------------------------------
Operand::~Operand
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// GetString()
//
// DESCRIPTION:
// mOpString accessor function.
//--------------------------------------------------------------------------------------------------------------
std::string Operand::GetString
    (
    )
    const
{
    return mOpString;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
Operand& Operand::operator=
    (
    Operand const& pOperand
    )
{
    if (this != &pOperand) Copy(pOperand);
    return *this;
}

//--------------------------------------------------------------------------------------------------------------
// SetString()
//
// DESCRIPTION:
// mOpString mutator function.
//--------------------------------------------------------------------------------------------------------------
void Operand::SetString
    (
    std::string const& pOpString
    )
{
    mOpString = pOpString;
}

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes 'this' Operand a copy of pOperand.
//--------------------------------------------------------------------------------------------------------------
void Operand::Copy
    (
    Operand const& pOperand
    )
{
    SetString(pOperand.GetString());
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================

