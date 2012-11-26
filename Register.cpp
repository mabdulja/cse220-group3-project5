//**************************************************************************************************************
// CLASS: Register
//
// DESCRIPTION
// See comments in Register.hpp.
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
#include "Register.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Call the base class Operand::Operand(string const&) ctor to store the name of the register in the mOpString
// data member inherited from Operand.
//--------------------------------------------------------------------------------------------------------------
//???
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
//
// DESCRIPTION:
// Calls Copy().
//--------------------------------------------------------------------------------------------------------------
//???
Register::Register
	(
	Register const& pRegister
	)

{
	Copy(pRegister);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// Does nothing.
//--------------------------------------------------------------------------------------------------------------
//???
Register::~Register
	(
	)

{
}

//--------------------------------------------------------------------------------------------------------------
// GetEncoding()
//
// DESCRIPTION:
// If the name of this register is "%A" we return 0, otherwise we return 1.
//--------------------------------------------------------------------------------------------------------------
//???
Byte Register::GetEncoding() const
{
	if (Register::GetName() == "%A")
		return 0;
	else
		return 1;
}


//--------------------------------------------------------------------------------------------------------------
// GetName()
//
// DESCRIPTION:
// Operand::mOpString accessor function. Returns the name of the register which will be either "%A" or "%B".
//
// PSEUDOCODE:
// Call the Operand::GetString() function and return what it returns.
//--------------------------------------------------------------------------------------------------------------
//???
std::string Register::GetName() const
{
    return Operand::GetString();

}



//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
//???
Register& Register::operator=(Register const& pRegister)
{
    if (this != &pRegister) Copy(pRegister);
    return *this;
}

//--------------------------------------------------------------------------------------------------------------
// SetName()
//
// DESCRIPTION:
// Operand::mOpString mutator function.
//
// PSEUDOCODE:
// Call the Operand::SetString() function and pass pName as the param.
//--------------------------------------------------------------------------------------------------------------
//???
void Register::SetName(const std::string &pName)
{
	Operand::SetString(pName);
}


//==============================================================================================================
// PROTECTED FUNCTIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes 'this' Register a copy of pRegister. Since Register has no data members, we simply call Operand::Copy()
//
// PSEUDOCODE:
// Call Operand::Copy() and pass pRegister as the param.
//--------------------------------------------------------------------------------------------------------------
//???
void Register::Copy
{
	Operand::Copy(pRegister)
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
