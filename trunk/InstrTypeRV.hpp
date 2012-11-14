//**************************************************************************************************************
// CLASS: InstrTypeRV
//
// DESCRIPTION
// An instruction with two operands: a register and a variable. This class is derived from InstrTypeR.
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
#ifndef INSTRTYPERV_HPP
#define INSTRTYPERV_HPP

#include <string>
#include "InstrTypeR.hpp"
#include "Variable.hpp"

//==============================================================================================================
// CLASS: InstrTypeRV (derived from InstrTypeR)
//==============================================================================================================
class InstrTypeRV : public InstrTypeR {

public:
    //==========================================================================================================
    // PUBLIC FUNCTION MEMBERS:
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // Default ctor.
    //---------------------------------------------------------------------------------------------------------
    InstrTypeRV
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // Ctor.
    //---------------------------------------------------------------------------------------------------------
    InstrTypeRV
        (
        std::string const& pMnemonic,
        Register const&    pRegister,
        Variable const&    pVariable
        );

    //---------------------------------------------------------------------------------------------------------
    // Copy ctor.
    //---------------------------------------------------------------------------------------------------------
    InstrTypeRV
        (
        InstrTypeRV const& pInstr
        );

    //---------------------------------------------------------------------------------------------------------
    // Dtor.
    //---------------------------------------------------------------------------------------------------------
    virtual ~InstrTypeRV
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // Encode()
    //---------------------------------------------------------------------------------------------------------
    virtual void Encode
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // GetVariable()
    //---------------------------------------------------------------------------------------------------------
    Variable GetVariable
        (
        )
        const;

    //---------------------------------------------------------------------------------------------------------
    // operator=()
    //---------------------------------------------------------------------------------------------------------
    InstrTypeRV& operator=
        (
        InstrTypeRV const& pInstr
        );

protected:
    //==========================================================================================================
    // PROTECTED FUNCTION MEMBERS:
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // Copy()
    //---------------------------------------------------------------------------------------------------------
    void Copy
        (
        InstrTypeRV const& pInstr
        );

    //---------------------------------------------------------------------------------------------------------
    // SetVariable()
    //---------------------------------------------------------------------------------------------------------
    void SetVariable
        (
        Variable const& pVariable
        );

private:
    //==========================================================================================================
    // PRIVATE DATA MEMBERS:
    //==========================================================================================================

    // A type RV instruction has an associated Register and Variable. The register data member is inherited
    // from the base class (InstrTypeR) and this class adds the Variable data member.
    Variable mVariable;
};

#endif
