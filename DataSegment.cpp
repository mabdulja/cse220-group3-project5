//**************************************************************************************************************
// CLASS: DataSegment
//
// DESCRIPTION
// See comments in DataSegment.hpp.
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
#include "DataSegment.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// IMPORTANT:
// Study this code to see how the base class ctor gets called in the member initialization list. In C++, the
// base class default ctor will be called automatically from the member initialization list, e.g., if you write
// this,
//
// DataSegment::DataSegment(Address const pAddress)
// {
// }
//
// The compiler generates this,
//
// DataSegment::DataSegment(Address const pAddress)
// : Segment()                                         -- Calls the base class default ctor automatically.
// {
// }
//
// If you wish to call a different ctor, you can, but you have to call it explicitly, AND, it has to be called
// from the member initialization list (i.e., not in the function body).
//--------------------------------------------------------------------------------------------------------------
DataSegment::DataSegment
    (
    Address const pAddress
    )
    :
    Segment(pAddress)  // Calls Segment::Segment(Address) rather than Segment::Segment()
{
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//
// IMPORTANT:
// Make sure you study this code to see how the copy constructor works for a derived class. Study DataSegment::
// Copy() as well.
//--------------------------------------------------------------------------------------------------------------
DataSegment::DataSegment
    (
    DataSegment const& pDataSegment
    )
{
    Copy(pDataSegment);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor:
//
// IMPORTANT:
// Note that the base class destructor will be called automatically, AFTER the body of this dtor is executed.
//--------------------------------------------------------------------------------------------------------------
DataSegment::~DataSegment
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// AddVariable()
//
// DESCRIPTION:
// Adds pVariable to the std::map mVars.
//
// IMPORTANT:
// See http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html for a std::map tutorial.
// The general way to insert or add a value to a std::map is to write: mapObj[key] = value;
//--------------------------------------------------------------------------------------------------------------
void DataSegment::AddVariable
    (
    Variable const& pVariable
    )
{
    mVars[pVariable.GetName()] = pVariable;
}

//--------------------------------------------------------------------------------------------------------------
// GetVariable()
//
// DESCRIPTION:
// Retrieves the Variable with name pName from the std::map mVars.
//
// IMPORTANT:
// See http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html for a std::map tutorial.
//--------------------------------------------------------------------------------------------------------------
Variable DataSegment::GetVariable
    (
    std::string const& pName
    )
{
    return mVars[pName];
}

//--------------------------------------------------------------------------------------------------------------
// GetContents()
//
// DESCRIPTION:
// Returns the contents of the data segment in the binary format it will be written to the binary file in.
// See the lab project document for a discussion of the binary format of the data segment.
//
// IMPORTANT:
// See http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html for a std::map tutorial. In particular, study how an
// "iterator" can be created to iterate over the elements of a std::map.
//--------------------------------------------------------------------------------------------------------------
Byte *DataSegment::GetContents
    (
    )
    const
{
    // 'offset' is the offset from the beginning of the 'contents' array where a Variable's initial
    // value will be written. The first Variable's inital value will be written at offset 0.
    uint offset = 0;

    // Dynamically allocate a 1D array of Bytes large enough to store all of the variables. The size()
    // function on a map object returns the number of elements in the map. Since each variable takes 4
    // bytes in the binary, we multiple the number of variables by 4 to determine the size of the array.
    Byte *contents = new Byte[mVars.size() * 4];

    // Create a constant iterator over the map mVars. The iterator is const because we are not going to
    // be modifying the Variable objects as we iterate over them. If you want to create a non-const
    // iterator then you would write,
    //
    // std::map<std::string, Variable>::iterator it = mVars.begin();    

    std::map<std::string, Variable>::const_iterator it = mVars.begin();    

    // Iterate over each element of the map.
    while (it != mVars.end()) {

        // 'it' is a pointer to the element. (*it) dereferences 'it' and then we retrieve the value
        // of this map element by accessing the 'second' data member of the iterator. Since the map
        // values are Variables, this is a Variable object.
        Variable variable = (*it).second; 

        // Get the initial value of the variable. Note: the initial value is stored in 2's complement
        // notation (to handle negative initial values) so the data type returned is int32 rather than
        // Word (Word is an unsigned data type).
        int32 initValue = variable.GetInitValue();

        // Copy the initValue into the contents array.
        memcpy(&contents[offset], reinterpret_cast<Byte *>(&initValue), 4);

        // Bump offset up by 4.
        offset += 4;

        // Iterate to the next element of the map.
        ++it;
    }

    // Return the dynamically allocated array. Note that the Binary::Write() function deallocates this
    // array.
    return contents;
}

//--------------------------------------------------------------------------------------------------------------
// GetSize()
//
// DESCRIPTION:
// Reads the number of bytes the data segment will consume when written to the binary file. Each variable is
// 4 bytes in the binary and the data segment header takes 9 bytes. Therefore the size of the data segment is
// 9 + 4 * (number of variables).
//--------------------------------------------------------------------------------------------------------------
uint32 DataSegment::GetSize
    (
    )
    const
{
    return (uint32) (9 + 4 * mVars.size());
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
DataSegment& DataSegment::operator=
    (
    DataSegment const& pDataSegment 
    )
{
    if (this != &pDataSegment) Copy(pDataSegment);
    return *this;
}

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes 'this' DataSegment object a copy of pDataSegment.
//
// IMPORTANT:
// Make sure you study this code to see how the copy constructor works for a derived class.
//--------------------------------------------------------------------------------------------------------------
void DataSegment::Copy
    (
    DataSegment const& pDataSegment
    )
{
    // Call the base class (Segment) Copy() function to copy the data members inherited from Segment.
    Segment::Copy(pDataSegment);

    // Copy the derived class (DataSegment) data members. This assignment invokes std::map:::operator=()
    // on mVars and passes pDataSegment.mVars as the parameter.
    mVars = pDataSegment.mVars;
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================

