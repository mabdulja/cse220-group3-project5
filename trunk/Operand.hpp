//**************************************************************************************************************
// CLASS: Operand
//
// DESCRIPTION
// Operand represents an operand in an assembly language instruction. It is the base class of the Integer,
// Label, Register, and Variable classes.
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
// Preprocessor guard.
#ifndef OPERAND_H
#define OPERAND_H


#include <string>
#include "Types.hpp"

//==============================================================================================================
// CLASS: Operand
//==============================================================================================================

// Write the class declaration
abstract class Operand
{
public:
	Operand(string const& pOpString = "");
	Operand(Operand const& pOperand);
	//pure virtual ~Operand();
	string GetString() const;
	Operand& operator=(Operand const& pOperand);
	void SetString(string const& pOpString);
protected:
	void Copy(Operand const& pOperand);
private:
	string mOpString;

};

// End preprocessor guard.
#endif
