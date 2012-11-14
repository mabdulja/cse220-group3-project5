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
???

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//
// DESCRIPTION:
// Call the Copy() function of this class.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// In this class, it is simply an empy function.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// GetAddress()
//
// DESCRIPTION:
// mAddress accessor function.
//-------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// GetInitValue()
//
// DESCRIPTION:
// mInitValue accessor function.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// GetName()
//
// DESCRIPTION:
// Returns the name of the variable. The name is the mOpString data member that is inherited from the Operand
// class. Call the Operand::GetString() function to get mOpString and return it.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// operator=()
// Hint: look at the other source code files to see how this is done.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// SetAddress()
//
// DESCRIPTION:
// mAddress mutator function.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// SetInitValue()
//
// DESCRIPTION:
// mInitValue mMutator function.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Setname()
//
// DESCRIPTION:
// Mutator function for the mString data member that is inherited from the Operand class. Call the Operand::
// SetString() function and pass pName as the parameter.
//--------------------------------------------------------------------------------------------------------------
???

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
???

//==============================================================================================================
// PRIVATE FUNCTIONS
//==============================================================================================================
