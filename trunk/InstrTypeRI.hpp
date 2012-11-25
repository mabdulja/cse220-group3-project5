//**************************************************************************************************************
// CLASS: InstrTypeRI
//
// DESCRIPTION
// A type RI instruction is one that encodes a register and an integer. All such instructions are instances of
// this class. InstrTypeRI is derived from InstrTypeR.
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


//==============================================================================================================
// CLASS: InstrTypeRI (derived from InstrTypeR)
//==============================================================================================================

#ifndef INSTRTYPERI_H
#define INSTRTYPERI_H

#include <string>
#include "Integer.hpp"
#include "InstrTypeR.hpp"
using namespace std;


//==============================================================================================================
// CLASS: InstrTypeR (derived from Instr)
//==============================================================================================================
// Write the class declaration
class InstrTypeRI : public InstrTypeR
{
public:
	InstrTypeRI();
	InstrTypeRI(string const& pMnemonic, Register const& pReg, Integer const& pInt);
	InstrTypeRI(InstrTypeRI const& pInstr);
	virtual ~InstrTypeRI();
	virtual void Encode();
	Integer GetInteger() const;
	InstrTypeRI& operator=(InstrTypeRI const& pInstr);
protected:
	void Copy(InstrTypeRI const& pInstr);
	void SetInteger(Integer const& pInteger);
private:
	Integer mInteger;


};


// End preprocessor guard.
#endif
