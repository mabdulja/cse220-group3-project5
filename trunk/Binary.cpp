//**************************************************************************************************************
// CLASS: Binary
//
// DESCRIPTION
// See comments in Binary.hpp.
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
#include <fstream>
#include "Binary.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Does nothing, but remember, every class must have at least one ctor.
//--------------------------------------------------------------------------------------------------------------
Binary::Binary
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// Does nothing, but remember, if you do not write a destructor, then this is the one that will be generated
// for you by the compiler.
//--------------------------------------------------------------------------------------------------------------
Binary::~Binary
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Binary::Write
//
// DESCRIPTION:
// Writes the binary to the file with name pBinFname. The contents of the data segment pDataSeg is written first
// followed by the contents of the text segment pTextSeg.
//
// PSEUDOCODE:
// Define bout to be an object of the class std::ofstream
// Open bout passing parameters (pBinFname.c_str(), std::ios_base::binary)
// Write "K1BIN" to bout. ( Hint: bout.write("K1BIN", 5); )
// Address initPC <- pTextSeg.GetAddress()
// Write initPC to bout ( Hint: bout.write(reinterpret_cast<char *>(&initPC), 4); )
// Write seven 0 bytes to bout.
// Write byte (0 for .DATA segment) to bout.
// Word size <- pDataSeg.GetSize()
// Write size as four bytes to bout.
// Address addr <- pDataSeg.GetAddress()
// Write addr as four bytes to bout.
// contents <- pDataSeg.GetContents()
// Write contents to bout.
// Delete contents (this dynamically allocated array was allocated in GetContents()).
// Write byte (1 for .TEXT segment) to bout.
// size <- pTextSeg.GetSize()
// Write size as four bytes to bout.
// addr <- pTextSeg.GetAddress()
// Write addr as four bytes to bout.
// contents <- pTextSeg.GetContents()
// Write contents to bout.
// Delete contents (this dynamically allocated array was allocated in GetContents()).
// Close bout.
//
// Note: ofstream::write() expects the first parameter to be a pointer to a char, i.e., to be of the data type
// char *. To typecast a pointer of one type to another type in C++ you can use the reinterpet_cast<> operator,
// e.g.,
//
// Byte *contents = mDataSeg.GetContents();
// bout.write(reinterpret_cast<char *>(contents), ...);  -- Typecast 'contents' to be of type char *.
//
// or
//
// Byte type = 0;
// bout.write(reinterpret_cast<char *>(&type), 1); 
//--------------------------------------------------------------------------------------------------------------
???

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================

