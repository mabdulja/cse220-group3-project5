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
TextSegment::TextSegment(Address const pAddress) : Segment(pAddress)
                
{
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
    pInstr->Encode();
    mInstrs.push_back(*pInstr);
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
    mLabels[pLabel.GetName()] = pLabel;
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
    
    // 'offset' is the offset from the beginning of the 'contents' array where a Variable's initial
    // value will be written. The first Variable's inital value will be written at offset 0.
    uint offset = 0;
    
    // Dynamically allocate a 1D array of Bytes large enough to store all of the variables. The size()
    // function on a map object returns the number of elements in the map. Since each variable takes 4
    // bytes in the binary, we multiple the number of variables by 4 to determine the size of the array.
    Byte *contents = new Byte[mInstrs.size() * 4];
    
    // Create a constant iterator over the map mVars. The iterator is const because we are not going to
    // be modifying the Variable objects as we iterate over them. If you want to create a non-const
    // iterator then you would write,
    //
    // std::map<std::string, Variable>::iterator it = mVars.begin();
    
    std::vector<Instr>::const_iterator it = mInstrs.begin();
    
    // Iterate over each element of the map.
    while (it != mInstrs.end()) {
        
        // 'it' is a pointer to the element. (*it) dereferences 'it' and then we retrieve the value
        // of this map element by accessing the 'second' data member of the iterator. Since the map
        // values are Variables, this is a Variable object.
        Instr instr = (*it);
        
        // Get the initial value of the variable. Note: the initial value is stored in 2's complement
        // notation (to handle negative initial values) so the data type returned is int32 rather than
        // Word (Word is an unsigned data type).
        Word encoding = instr.GetEncoding();
        
        // Copy the initValue into the contents array.
        memcpy(&contents[offset], reinterpret_cast<Byte *>(&encoding), 4);
        
        // Bump offset up by 4.
        offset += 4;
        
        // Iterate to the next element of the map.
        ++it;
    }
    
    // Return the dynamically allocated array. Note that the Binary::Write() function deallocates this
    // array.
    return contents;
//*********************************************************************************************
}

//--------------------------------------------------------------------------------------------------------------
// GetLabel()
//
// DESCRIPTION:
// Retrieves the Label object with name pName from the mLabels map.
//--------------------------------------------------------------------------------------------------------------

Label TextSegment::GetLabel(const string &pName)
{
    return TextSegment::mLabels[pName];
}


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

uint32 TextSegment::GetSize() const
{
    {
        return (uint32) (9 + 4 * mInstrs.size());
    }
}

//--------------------------------------------------------------------------------------------------------------
// Overload operator=
//--------------------------------------------------------------------------------------------------------------

TextSegment& TextSegment::operator=(const TextSegment &pTextSegment)
{
    if (this != &pTextSegment) Copy(pTextSegment);
    return *this;
}

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

void TextSegment::Copy(const TextSegment &pTextSegment)
{
    Segment::Copy(pTextSegment);
    mInstrs = pTextSegment.mInstrs;
    mLabels = pTextSegment.mLabels;
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================
