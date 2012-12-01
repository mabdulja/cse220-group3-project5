//**************************************************************************************************************
// CLASS: DataSegment.hpp.
//
// DESCRIPTION
// Declares a class that maintains the information in the .DATA segment. In particular, stores a std::map
// with key = std::string and value = Variable.
//
// Note that DataSegment is derived from Segment. The Segment class stores a data member which is the address
// of the segment. The DataSegment class adds a map which stores the Variables of the data segment.
//
// REFERENCES:
// 1. http://www.cplusplus.com/reference/stl/map
// 2. http://www.cprogramming.com/tutorial/stl/stlmap.html
// 3. http://www.yolinux.com/TUTORIALS/CppStlMultiMap.html
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
#ifndef DATASEGMENT_HPP
#define DATASEGMENT_HPP

#include <map>
#include <string.h>
#include "Segment.hpp"
#include "Types.hpp"
#include "Variable.hpp"

//==============================================================================================================
// CLASS: DataSegment
//
// IMPORTANT:
// Notice how to specify that DataSegment is derived from Segment. The "public" reserved word essentially means
// that the members of the derived class (DataSegment) will have the same access level (public, protected, or
// private) as the members in the Base class. For example,
//
// class Base {
// public:
//    int mPub;
// protected:
//    int mProt;
// private:
//    mPriv;
// };
//
// class Derived : public Base {
//     ...
// };
//
// void SomeFunction()    -- obj.mPub is public
// {                      -- obj.mProt is protected
//     Derived obj;       -- obj.mPriv is private
// }
//
// Compare this to protected inheritance. In this case, all public members of the base class are inherited as
// protected in the derived class. Private members of the base class remain private in the derived class.
//
// class Base {
// public:
//    int mPub;
// protected:
//    int mProt;
// private:
//    mPriv;
// };
//
// class Derived : protected Base {
//     ...
// };
//
// void SomeFunction()    -- obj.mPub is protected
// {                      -- obj.mProt is protected
//     Derived obj;       -- obj.mPriv is private
// }
//
// Lastly, there is private inheritance in which all members of the base class become private in the derived
// class.
//
// class Base {
// public:
//    int mPub;
// protected:
//    int mProt;
// private:
//    mPriv;
// };
//
// class Derived : private Base {
//     ...
// };
//
// void SomeFunction()    -- obj.mPub is private
// {                      -- obj.mProt is private
//     Derived obj;       -- obj.mPriv is private
// }
//==============================================================================================================
class DataSegment : public Segment {

public:
    //==========================================================================================================
    // PUBLIC FUNCTION MEMBERS
    //==========================================================================================================

    //----------------------------------------------------------------------------------------------------------
    // Default ctor.
    //----------------------------------------------------------------------------------------------------------
    DataSegment
        (
        Address const pAddress = 0
        );

    //----------------------------------------------------------------------------------------------------------
    // Copy ctor.
    //----------------------------------------------------------------------------------------------------------
    DataSegment
        (
        DataSegment const& pDataSegment
        );

    //----------------------------------------------------------------------------------------------------------
    // Dtor.
    //----------------------------------------------------------------------------------------------------------
    ~DataSegment
        (
        );

    //----------------------------------------------------------------------------------------------------------
    // AddVariable()
    //----------------------------------------------------------------------------------------------------------
    void AddVariable
        (
        Variable const& pVariable
        );
 
    //----------------------------------------------------------------------------------------------------------
    // GetVariable()
    //----------------------------------------------------------------------------------------------------------
    Variable GetVariable
        (
        std::string const& pName
        );

    //----------------------------------------------------------------------------------------------------------
    // GetContents()
    //----------------------------------------------------------------------------------------------------------
    Byte *GetContents
        (
        )
        const;

    //----------------------------------------------------------------------------------------------------------
    // GetSize()
    //----------------------------------------------------------------------------------------------------------
    uint32 GetSize
        (
        )
        const;

    //----------------------------------------------------------------------------------------------------------
    // operator=()
    //----------------------------------------------------------------------------------------------------------
    DataSegment& operator=
        (
        DataSegment const& pDataSegment 
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
        DataSegment const& pDataSegment
        );

private:
    //==========================================================================================================
    // PRIVATE DATA MEMBERS
    //==========================================================================================================

    // The Variables in the data segment are stored in a map. "map" is a class in the C++ Standard Template
    // Library (STL). A map is also called a "dictionary". A map maps "keys" onto "values". In our map, named
    // mVars, the key is string and the value is a Variable.

    std::map<std::string, Variable> mVars;
};

#endif
