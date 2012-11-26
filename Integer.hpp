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
	Integer(std::string const& pValue = "");
	Integer(Integer const& pInteger);
	~Integer();
	int32_t GetValue() const;
	Integer& operator=(Integer const& pInteger);
	void SetValue(int32_t const pValue);
protected:
	void Copy(Integer const& pInteger);
private:
	int32_t mInt;

};

// End preprocessor guard.
#endif
