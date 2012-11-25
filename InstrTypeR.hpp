//**************************************************************************************************************
// CLASS: InstrTypeR
//
// DESCRIPTION
// Declares a class that represents a type R instruction, i.e., one that has just one operand: a register. This
// class is derived from Instr.
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
#ifndef INSTRTYPER_H
#define INSTRTYPER_H

#include <string>
#include "Instr.hpp"
#include "Register.hpp"

//==============================================================================================================
// CLASS: InstrTypeR (derived from Instr)
//==============================================================================================================
// Write the class declaration
class InstrTypeR : public Instr
{
public:
	InstrTypeR();
	InstrTypeR(string const& pMnemonic, Register const& pReg);
	InstrTypeR(InstrTypeR const& pInstr);
	virtual ~InstrTypeR();
	virtual void Encode();
	Register GetRegister() const;
	InstrTypeR& operator=(InstrTypeR const& pInstr);
protected:
	void Copy(InstrTypeR const& pInstr);
	void SetRegister(Register const& pRegister);
private:
	Regiser mRegister;
	

};


// End preprocessor guard.
#endif
