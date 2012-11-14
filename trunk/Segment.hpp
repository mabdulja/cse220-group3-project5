//**************************************************************************************************************
// CLASS: Segment
//
// DESCRIPTION
// Base for the DataSegment and TextSegment derived classes. This is an abstract class, and objects of this
// class cannot be instantiated.
//
// In C++ a class is made abstract by declaring at least one "pure virtual" function, e.g.,
//
// class AbstractClass {
// public:
//     AbstractClass();                -- The default ctor. Not virtual (ctors cannot be virtual).
//     virtual ~AbstractClass() = 0;   -- A pure virtual function. Makes this an abstract class.
//     virtual SomeFunction();         -- A virtual function. Must be overridden in a derived class.
//     ...
// };
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
#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Types.hpp"

//==============================================================================================================
// CLASS: Segment
//==============================================================================================================
class Segment {

public:
    //==========================================================================================================
    // PUBLIC FUNCTION MEMBERS
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // Default ctor.
    //---------------------------------------------------------------------------------------------------------
    Segment
        (
        Address const pAddress = 0
        );

    //---------------------------------------------------------------------------------------------------------
    // Copy ctor.
    //---------------------------------------------------------------------------------------------------------
    Segment
        (
        Segment const& pSegment
        );

    //----------------------------------------------------------------------------------------------------------
    // Dtor.
    //
    // IMPORTANT:
    // See comments in the source header. Read about abstract classes and pure virtual functions in your text
    // book.
    //----------------------------------------------------------------------------------------------------------
   virtual ~Segment
        (
        )
        = 0;  // Makes this an abstract class

    //----------------------------------------------------------------------------------------------------------
    // GetAddress()
    //----------------------------------------------------------------------------------------------------------
    Address GetAddress
        (
        )
        const;

    //----------------------------------------------------------------------------------------------------------
    // GetContents()
    //
    // IMPORTANT:
    // Another virtual function. Must be overridden (implemented) in a derived class or that derived class will
    // also be abstract. This function does not need to be pure (one pure virtual function is sufficient to make
    // a class abstract, and the destructor has already been declared pure virtual, but I go all out).
    //----------------------------------------------------------------------------------------------------------
    virtual Byte *GetContents
        (
        )
        const
        = 0;

    //----------------------------------------------------------------------------------------------------------
    // GetSize()
    //
    // IMPORTANT:
    // Another virtual function. Must be overridden (implemented) in a derived class or that derived class will
    // also be abstract. This function does not need to be pure (one pure virtual function is sufficient to make
    // a class abstract, and the destructor has already been declared pure virtual, but I go all out).
    //----------------------------------------------------------------------------------------------------------
    virtual uint32 GetSize
        (
        )
        const
        = 0;

    //----------------------------------------------------------------------------------------------------------
    // operator=()
    //----------------------------------------------------------------------------------------------------------
    Segment& operator=
        (
        Segment const& pSegment
        );

    //----------------------------------------------------------------------------------------------------------
    // SetAddress()
    //----------------------------------------------------------------------------------------------------------
    void SetAddress
        (
        Address const pAddress
        );

protected:
    //==========================================================================================================
    // PROTECTED FUNCTION MEMBERS
    //==========================================================================================================

    //----------------------------------------------------------------------------------------------------------
    // Copy()
    //----------------------------------------------------------------------------------------------------------
    void Copy
        (
        Segment const& pSegment
        );

private:
    //==========================================================================================================
    // PRIVATE DATA MEMBERS
    //==========================================================================================================

    // A segment is stored at an address. This data member is inherited by the DataSegment and TextSegment
    // classes. Therefore, each DataSegment and TextSegment is stored at an address.
    Address mAddress;    
};

#endif
