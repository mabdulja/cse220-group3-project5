//**************************************************************************************************************
// CLASS: Lex
//
// DESCRIPTION
// See comments in Lex.hpp.
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
#include <iostream>
#include "Lex.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Ctor.
//
// DESCRIPTION:
// Opens the file with name pSrcFname for reading.
//
// PSEUDOCODE:
// Call mFin.open() and pass pSrcFname.c_str() as the paramter. See the comment in Integer.cpp about the
// std::string::c_str() function.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// Closes mFin.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// NextToken()
//
// DESCRIPTION:
// Returns the next token (i.e., string) from the source file.
//
// PSEUDOCODE:
// Define variable comment as a Bool
// Define object token as a string
// Do
//     Read from mFin into token using the >> operator
//     If the read fails (mFin will be false) then return the empty string
//     Set comment to false.
//     If the first character of token is ';' Then
//         Call SkipRestOfLine()
//         Set comment to true
//     End If
// While comment is true
// Return token
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Reset()
//
// DESCRIPTION:
// Closes the source code file and then reopens it.
//
// PSEUDOCODE:
// Call close() on mFin to close the file.
// Call open() on mFin to reopen the file for reading.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// SkipRestOfLine()
//
// DESCRITPION:
// Reads and discards all characters until '\n' is read.
//
// PSEUDOCODE:
// Define an object named ignore as a string
// Call getline(mFin, ignore, '\n') to read and throw away all chars on the line until the newline is reached.
//--------------------------------------------------------------------------------------------------------------
???

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================
