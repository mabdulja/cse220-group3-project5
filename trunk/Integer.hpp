//**************************************************************************************************************
// CLASS: Integer
//
// DESCRIPTION
// Declares a class that represents Integer operands in assembly language instructions. This class is derived
// from Operand.
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
// Preprocessor guard.
#ifndef INTEGER_H
#define INTEGER_H

#include "Operand.hpp"

//==============================================================================================================
// CLASS: Integer (derived from Operand)
//==============================================================================================================

// Write the class declaration.
class Integer : public Operand
{
public:
	Integer(string const& pValue = "")
	Integer(Integer const& pInteger);
	~Integer();
	int32 GetValue() const;
	Integer& operator=(Integer const& pInteger);
	void SetValue(int32 const pValue);
protected:
	void Copy(Integer const& pInteger);
private:
	int32 mInt;

};

// End preprocessor guard.
#endif
