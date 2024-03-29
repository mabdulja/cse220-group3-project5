//**************************************************************************************************************
// CLASS: Lex
//
// DESCRIPTION
// Implements the lexical analyzer which returns successive tokens read from the source code file.
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
#ifndef LEX_HPP
#define LEX_HPP

#include <fstream>
#include <string.h>

#include "Types.hpp"

//==============================================================================================================
// CLASS: Lex
//==============================================================================================================
class Lex {

public:
    //==========================================================================================================
    // PUBLIC FUNCTION MEMBERS:
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // Default ctor.
    //---------------------------------------------------------------------------------------------------------
    Lex
        (
        std::string const& pSrcFname = ""
        );

    //---------------------------------------------------------------------------------------------------------
    // Dtor.
    //---------------------------------------------------------------------------------------------------------
    ~Lex
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // NextToken()
    //---------------------------------------------------------------------------------------------------------
    std::string NextToken
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // Reset()
    //---------------------------------------------------------------------------------------------------------
    void Reset
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // SkipRestOfLine()
    //---------------------------------------------------------------------------------------------------------
    void SkipRestOfLine
        (
        );

protected:
    //==========================================================================================================
    // PROTECTED DATA MEMBERS:
    //==========================================================================================================

    std::ifstream  mFin;
    std::string    mSrcFname;

private:
    //==========================================================================================================
    // PRIVATE FUNCTION MEMBERS:
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // Private copy ctor. See comments about private ctors in Binary.hpp.
    //---------------------------------------------------------------------------------------------------------
    Lex
        (
        Lex const&
        );

    //---------------------------------------------------------------------------------------------------------
    // Private operator=(). See comments about private operator=() in Binary.hpp.
    //---------------------------------------------------------------------------------------------------------
    Lex& operator=
        (
        Lex const&
        );
};

#endif
