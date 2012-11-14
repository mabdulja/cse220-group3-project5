//**************************************************************************************************************
// CLASS: Binary
//
// DESCRIPTION
// Provides a class that represents the binary output file. Writes the binary.
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
#ifndef BINARY_HPP
#define BINARY_HPP

#include <string>
#include "DataSegment.hpp"
#include "TextSegment.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: Binary
//==============================================================================================================
class Binary {

public:
    //==========================================================================================================
    // PUBLIC FUNCTION MEMBERS
    //==========================================================================================================

    //----------------------------------------------------------------------------------------------------------
    // Default ctor.
    //----------------------------------------------------------------------------------------------------------
    Binary
        (
        );

    //----------------------------------------------------------------------------------------------------------
    // Dtor.
    //----------------------------------------------------------------------------------------------------------
    ~Binary
        (
        );

    //----------------------------------------------------------------------------------------------------------
    // Write()
    //----------------------------------------------------------------------------------------------------------
    void Write
        (
        std::string const& pBinFname,
        DataSegment const& pDataSeg,
        TextSegment const& pTextSeg
        );

private:
    //==========================================================================================================
    // PRIVATE FUNCTION MEMBERS
    //==========================================================================================================

    //----------------------------------------------------------------------------------------------------------
    // IMPORTANT:
    //
    // By making the copy ctor and overloaded operator= functions private, this prevents other classes from
    // making copies of an object, i.e., the following code would be illegal,
    //
    // Class SomeClass {
    // public:
    //     void SomeFunction(Binary& pBin) {
    //         Binary bin2(pbin);                 -- Will not compile because copy ctor cannot be called
    //         Binary bin2 = pBin;                -- Ditto
    //         SomeOtherFunction(pBin);           -- Will not compile. Pass by-value requires copy ctor
    //     }
    //     void SomeOtherFunction(Binary pBin) {  -- pBin passed by-value. Calls copy ctor.
    //         ...
    //     }
    // };
    //
    // In general, if you wish to prevent copies of an object being made, then declare the copy ctor and
    // operator= functions private.
    //
    // Also note that the functions do not need to be implemented (look in Binary.cpp and you will not find
    // function definitions for these functions).
    //----------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------
    // Private copy ctor. Cannot be called from outside the class.
    //----------------------------------------------------------------------------------------------------------
    Binary
        (
        Binary const& pBinary
        );

    //----------------------------------------------------------------------------------------------------------
    // Private operator=(). Cannot be called from outside the class.
    //----------------------------------------------------------------------------------------------------------
    Binary& operator=
        (
        Binary const& pBinary
        );
};

#endif
