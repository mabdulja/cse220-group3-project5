//**************************************************************************************************************
// CLASS: Register
//
// DESCRIPTION
// Decalres a class that represents a register operand in an instruction. Register is derived from Operand, i.e.
// a Register is a type of Operand.
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
#ifndef REGISTER_HPP
#define REGISTER_HPP

#include "Operand.hpp"

//==============================================================================================================
// CLASS: Register (derived from Operand)
//==============================================================================================================
class Register : public Operand {

public:
    //==========================================================================================================
    // PUBLIC FUNCTION MEMBERS
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // Default ctor.
    //---------------------------------------------------------------------------------------------------------
    Register
        (
        std::string const& pName = ""
        );

    //---------------------------------------------------------------------------------------------------------
    // Copy ctor.
    //---------------------------------------------------------------------------------------------------------
    Register
        (
        Register const& pRegister
        );

    //---------------------------------------------------------------------------------------------------------
    // Dtor.
    //---------------------------------------------------------------------------------------------------------
    ~Register
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // GetEncoding()
    //---------------------------------------------------------------------------------------------------------
    Byte GetEncoding
        (
        )
        const;

    //---------------------------------------------------------------------------------------------------------
    // GetName()
    //---------------------------------------------------------------------------------------------------------
    std::string GetName
        (
        )
        const;

    //---------------------------------------------------------------------------------------------------------
    // operator=()
    //---------------------------------------------------------------------------------------------------------
    Register& operator=
        (
        Register const& pRegister
        );

    //---------------------------------------------------------------------------------------------------------
    // SetName()
    //---------------------------------------------------------------------------------------------------------
    void SetName
        (
        std::string const& pName
        );

protected:
    //==========================================================================================================
    // PROTECTED FUNCTION MEMBERS
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // Copy()
    //---------------------------------------------------------------------------------------------------------
    void Copy
        (
        Register const& pRegister
        );
};

#endif