//**************************************************************************************************************
// CLASS: Assembler
//
// DESCRIPTION
// Main class for the K1 assembler.
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
// Write the preprocessor guard.
#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "DataSegment.hpp"
#include "Instr.hpp"
#include "InstrTypeB.hpp"
#include "InstrTypeR.hpp"
#include "InstrTypeRI.hpp"
#include "InstrTypeRV.hpp"
#include "Lex.hpp"
#include "TextSegment.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: Assembler
//==============================================================================================================

// Write the class declaration for Assembler.
using namespace std;

class Assembler
{
public:
	Assembler(string &, string &);
	~Assembler()
	int Run();

protected:
	void Assemble(const int pPass); //it said uint in the instructions is that a typo or do we have a uint type somewhere in the program?
	void AssembleDirective(string const& pPass); 
	Instr *AssembleInstr(string const& mLabel, string const& = "");
	Instr *AssembleInstrTypeB(string const& mLabel, string const& = "");
	Instr *AssembleInstrTypeN(string const& mLabel, string const& = "");
	Instr *AssembleInstrTypeR(string const& mLabel, string const& = "");
	Instr *AssembleInstrTypeRI(string const& mLabel, string const& = "");
	Instr *AssembleInstrTypeRV(string const& mLabel, string const& = "");
	void AssembleLabel(string const& pName);
	void AssembleVariable(string const& pName);
	void WriteBinary() const;
private:
	Assembler();
	Assembler(Assembler const& pAssembler);
	Assembler& operator=(Assembler const& pAssembler);

	string mBinFname;
	Address mCurrAddr;
	DataSegment mDataSeg;
	Lex mLex;
	string mSrcFname;
	TextSegment mTextSeg;


};

// End the preprocessor guard.
#endif 
