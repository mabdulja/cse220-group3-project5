//**************************************************************************************************************
// CLASS: TextSegment
//
// DESCRIPTION
// Maintains the text segment. The text segment has two data members: a Dictionary of the labels, and a Vector
// of the instructions. TextSegment is derived from Segment.
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
// Preprocess guard.
#ifndef TEXTSEGMENT_H
#define TEXTSEGMENT_H

// Figure out what header file you have to include to use the C++ STL std::map class.
using namespace std;
#include <map>
#include <vector>

// Figure out what header file you have to include to use the C++ STL std::vector class.


#include <string.h>
#include "Instr.hpp"
#include "Label.hpp"
#include "Segment.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: TextSegment (derived from Segment)
//==============================================================================================================

// Write the class declaration.

class TextSegment : public Segment
{
public:
	TextSegment(Address const pAddress= 0);
	TextSegment(TextSegment const& pTextSegment);
	~TextSegment();
	void AddInstr(Instr *pInstr);
	void AddLabel(Label const& pLabel);
	Byte *GetContents() const;
	Label GetLabel(string const& pName);
	uint32 GetSize() const;
	TextSegment& operator=(TextSegment const& pTextSegment);
protected:
	void Copy(TextSegment const& pTextSegment);
private:
	//----------------------------------------------------------------------------------------------------------
    // Declare a data member named mInstrs which is an object of the templated STL class vector<Instr>.
    //----------------------------------------------------------------------------------------------------------
    std::vector<Instr> mInstrs;

    //----------------------------------------------------------------------------------------------------------
    // Declare a data member named mLabels which is an object of the templated STL class map<std::string,
    // Label>.
    //----------------------------------------------------------------------------------------------------------
    std::map<std::string, Label> mLabels;
};

// End preprocessor guard.
#endif
