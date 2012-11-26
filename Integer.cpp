//**************************************************************************************************************
// CLASS: Integer
//
// DESCRIPTION
// See comments in Integer.hpp.
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
#include <cstdlib>      // For atoi() function.
#include <sstream>      // For stringstream class.
#include "Integer.hpp"
#include <cstring>
#include <string>

using namespace std;
//==============================================================================================================
// PUBLIC FUNCTIONS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Calls the base class Operand::Operand(string const&) ctor. Then converts pValue into an actual int and stores
// the converted int into the mInt data member.
//
// IMPORTANT:
// To convert the string representations of an integer into an actual int, call the C Standard Library function
// atoi() [alpha to int]. Note that atoi() expects a C string as the parameter, but pValue is a C++ std::string.
// The C++ std::string class simply encapsulates a C string, so to get the C string (really a pointer to the
// C string) encapsulated within a std::string object, call the std::string::c_str() function.
//--------------------------------------------------------------------------------------------------------------
Integer::Integer(string const& pValue) : Operand(pValue)
{
    char *newStr = pValue.c_str();
    int pInt = atoi(pValue.c_str());
    mInt = pInt;
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//--------------------------------------------------------------------------------------------------------------
// ???
Integer::Integer
    (
    Integer const& pInteger
    )
    
{
    Copy(pInteger);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//--------------------------------------------------------------------------------------------------------------
Integer::~Integer()
{

}

//--------------------------------------------------------------------------------------------------------------
// GetValue()
//
// DESCRIPTION:
// mInt accessor function.
//--------------------------------------------------------------------------------------------------------------
int32_t Integer::GetValue()
{
	return int32_t;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//-------------------------------------------------------------------------------------------------------------
Integer& Integer::operator=
    (
    Integer const& pInteger
    )
{
    if (this != &pInteger) Copy(pInteger);
    return *this;
}

//--------------------------------------------------------------------------------------------------------------
// SetValue()
//
// DESCRIPTION:
// mInt mutator function.
//--------------------------------------------------------------------------------------------------------------
void Integer::SetValue(int32_t const pValue)
{
	mInt = pValue;
}
//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes 'this' Integer a copy of pInteger.
//--------------------------------------------------------------------------------------------------------------

void Integer::Copy(Integer const& pInteger)
{
	Operand::Copy(pInteger);
	SetValue(pInteger.GetValue);
	
}
//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================
