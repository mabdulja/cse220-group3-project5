//**************************************************************************************************************
// CLASS: TextSegment
//
// DESCRIPTION
// See comments in TextSegment.hpp.
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
#include "TextSegment.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Calls the base class Segment::Segment(Address const) ctor to initialize the mAddress data member.
//--------------------------------------------------------------------------------------------------------------
TextSegment::TextSegment(Address const pAddress)
{
    // hmm.. figure this out later...
    Segment::Segment(pAddress);
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//
// DESCRIPTION:
// Calls Copy() to make this object a copy of pSeg.
//--------------------------------------------------------------------------------------------------------------
TextSegment::TextSegment(TextSegment const& pTextSegment)
{
    Copy(pTextSegment);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// Does nothing.
//--------------------------------------------------------------------------------------------------------------
TextSegment::~TextSegment()
{
    
}

//--------------------------------------------------------------------------------------------------------------
// AddInstr()
//
// DESCRIPTION:
// Encodes the Instr parameter 'pInstr' and then appends the encoded Instr to the mInstrs vector.
//
// PSEUDOCODE:
// pInstr->Encode()            -- Note: this is a polymorphic function call. Why?
// mInstrs.push_back(*pInstr)  -- Dereferences pInstr and inserts it into the mInstrs vector.
//
// NOTES:
// The input parameter pInstr is a pointer to an Instr, but remember that Instr has several derived classes,
// in particular InstrTypeB, InstrTypeR, InstrTypeRI, and InstrTypeRV. Since a base class pointer can actually
// be a pointer to derived class object, the compiler has no way of knowing in this function if pInstr is
// really a pointer to an Instr object or maybe a pointer to an InstrTypeRV object. Therefore, when we call
// pInstr->Encode() we need to make a polymorphic call because if pInstr is a pointer to an Instr object
// then we need to call Instr::Encode() but if pInstr is really a pointer to an InstrTypeRV object then we
// need to call InstrTypeRV::Encode(). Therefore, if you look in the Instr class hierarchy, Encode() is
// declared as a "virtual" function in each class declaration.
//
// If Encode() were not virtual and pInstr was really a pointer to an InstrTypeRV object and we call
// pInstr->Encode() then the compiler would generate code to call Instr::Encode() which IS NOT THE FUNCTION
// THAT SHOULD BE CALLED.
//
// Also note (look in the TextSegment class declaration) that mInstrs is a Vector where each element is an
// Instr object. If pInstr is a pointer to an Instr object, then *pInstr is the Instr object itself (remember
// that * is the "dereference" operator in this context).
//--------------------------------------------------------------------------------------------------------------

void TextSegment::AddInstr(Instr *pInstr)
{
// TODO: do stuff here
    // DO STUFF HERE!!!
}

//--------------------------------------------------------------------------------------------------------------
// AddLabel()
//
// DESCRIPTION:
// Adds a new label pLabel to the mLabels dictionary. The key is pLabel.GetName() and the value is pLabel.
// Hint: look at DataSegment::AddVariable().
//--------------------------------------------------------------------------------------------------------------

void TextSegment::AddLabel(const Label &pLabel)
{
    TextSegment::mLabels.AddLabel(pLabel.GetName());
}


//--------------------------------------------------------------------------------------------------------------
// GetContents()
//
// DESCRIPTION:
// Dynamically allocates a Byte array large enough to store all of the instructions. mInstrs.size() is the
// number of instructions in the mInstrs vector, and since each instruction is encoded using four bytes, the
// size of the array is mInstrs.size() * 4. Hint: see the GetContents() function in the DataSegment class.
//
// PSEUDOCODE:
// uint offset <- 0
// Dynamically allocate 'contents' as Byte *.  -- Will be deallocated in Binary::Write().
// Define a constant vector iterator object named 'it' to iterate over the mInstrs vector.
// While it != mInstrs.end() Do
//     Instr instr <- *it
//     Word encoding <- instr.GetEncoding()
//     memcpy(&contents[offset], reinterpret_cast<Byte *>(&encoding), 4)  -- memcpy() is sleazy.
//     offset <- offset + 4
//     Increment it
// End While
// Return contents
//
// HINT: Look at DataSegment::GetContents(). This function is very, very similar.
//--------------------------------------------------------------------------------------------------------------
Byte *TextSegment::GetContents() const
{
    
}

//--------------------------------------------------------------------------------------------------------------
// GetLabel()
//
// DESCRIPTION:
// Retrieves the Label object with name pName from the mLabels map.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// GetSize()
//
// DESCRIPTION:
// Returns the size of the TextSegment. The size is calculated as:
//
//   1 byte                         Type of segment
// + 4 bytes                        Text segment size
// + 4 bytes                        Address of text segment
// + mInstrs.size() * 4 bytes       Encodings of each instruction
//
// PSEUDOCODE:
// See DataSegment::GetSize().
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Overload operator=
//--------------------------------------------------------------------------------------------------------------
???

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes 'this' TextSegment object a copy of pTextSegment.
//
// PSEUDOCODE:
// Call the base class (Segment) Copy() function and pass pTextSegment as the param.
// Assign pTextSegment.mInstrs to mInstrs.  -- Will invoke std::vector::operator=() on mInstrs
// Assign pTextSegment.mLabels to mLabels.  -- Will invoke std::map::operator=() on mLabels.
//--------------------------------------------------------------------------------------------------------------
???

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================
