//**************************************************************************************************************
// CLASS: Variable
//
// DESCRIPTION
// See comments in Variable.hpp.
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
#include "Variable.hpp"

//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Def ctor.
//
// DESCRIPTION:
// Write a member initialization list to call the Operand class constructor and pass pName as the parameter, to
// initialize mAddress to pAddress, and to initialize mInitValue to pInitValue. The body of the constructor is
// empty.
//--------------------------------------------------------------------------------------------------------------
Variable::Variable(std::string const& pName, Address const pAddress, Word const pInitValue) : Operand(pName), mAddress(pAddress), mInitValue(pInitValue)
{
    
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//
// DESCRIPTION:
// Call the Copy() function of this class.
//--------------------------------------------------------------------------------------------------------------
Variable::Variable(Variable const& pVariable)
{
    Copy(pVariable);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// In this class, it is simply an empy function.
//--------------------------------------------------------------------------------------------------------------
Variable::~Variable()
{
    
}

//--------------------------------------------------------------------------------------------------------------
// GetAddress()
//
// DESCRIPTION:
// mAddress accessor function.
//-------------------------------------------------------------------------------------------------------------
Address Variable::GetAddress() const
{
    return mAddress;
}

//--------------------------------------------------------------------------------------------------------------
// GetInitValue()
//
// DESCRIPTION:
// mInitValue accessor function.
//--------------------------------------------------------------------------------------------------------------
int32 Variable::GetInitValue() const
{
    return mInitValue;
}

//--------------------------------------------------------------------------------------------------------------
// GetName()
//
// DESCRIPTION:
// Returns the name of the variable. The name is the mOpString data member that is inherited from the Operand
// class. Call the Operand::GetString() function to get mOpString and return it.
//--------------------------------------------------------------------------------------------------------------
std::string Variable::GetName() const
{
    return Operand::GetString();
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
// Hint: look at the other source code files to see how this is done.
//--------------------------------------------------------------------------------------------------------------
Variable& Variable::operator=(Variable const& pVariable)
{
    if (this != &pVariable) Copy(pVariable);
    return *this;
}

//--------------------------------------------------------------------------------------------------------------
// SetAddress()
//
// DESCRIPTION:
// mAddress mutator function.
//--------------------------------------------------------------------------------------------------------------
void Variable::SetAddress(const Address pAddress)
{
    mAddress = pAddress;
}

//--------------------------------------------------------------------------------------------------------------
// SetInitValue()
//
// DESCRIPTION:
// mInitValue mMutator function.
//--------------------------------------------------------------------------------------------------------------
void Variable::SetInitValue(const int32 pInitValue)
{
    mInitValue = pInitValue;
}

//--------------------------------------------------------------------------------------------------------------
// Setname()
//
// DESCRIPTION:
// Mutator function for the mString data member that is inherited from the Operand class. Call the Operand::
// SetString() function and pass pName as the parameter.
//--------------------------------------------------------------------------------------------------------------
void Variable::SetName(const std::string &pName)
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
// Makes 'this' Variable a copy of pVariable.
//
// PSEUDOCODE:
// Call Operand::Copy(pVariable). This copies the mOpString data member of pVariable to this object's mOpString
// Call SetAddress() with pVariable.GetAddress() as the parameter.
// Call SetInitValue() with pVariable.GetInitValue() as the parameter.
//--------------------------------------------------------------------------------------------------------------
void Variable::Copy(Variable const& pVariable)
{
    Operand::Copy(pVariable);
    mAddress = pVariable.mAddress;
    mInitValue = pVariable.mInitValue;
}

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
