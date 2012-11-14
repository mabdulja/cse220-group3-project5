//**************************************************************************************************************
// CLASS: InstrTypeB
//
// DESCRIPTION
// See comments in InstrTypeB.hpp.
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
#include "InstrTypeB.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//--------------------------------------------------------------------------------------------------------------
InstrTypeB::InstrTypeB
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// Another ctor.
//
// IMPORATANT: Notice how the base class constructor is called in the member init list.
//--------------------------------------------------------------------------------------------------------------
InstrTypeB::InstrTypeB
    (
    std::string const& pMnemonic,
    Label const&       pLabel
    )
    :
    Instr(pMnemonic),  // Calls Instr::Instr(string const&) ctor
    mLabel(pLabel)
{
    Encode();
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//--------------------------------------------------------------------------------------------------------------
InstrTypeB::InstrTypeB
    (
    InstrTypeB const& pInstr
    )
{
    Copy(pInstr);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//--------------------------------------------------------------------------------------------------------------
InstrTypeB::~InstrTypeB
    (
    )
{
}

//--------------------------------------------------------------------------------------------------------------
// Encode()
//
// DESCRIPTION:
// When a type B instruction is encoded, we first call the base class Encode() function to encode the opcode
// bits. Then we encode the branch target label's address.
//
// IMPORTANT:
// To call a base class overridden function, write baseclassname::functioname(params), e.g.,
//
// class Base {
// public:
//     ...
//     Function(int pX) { ... }
//     ...
// };
// 
// class Derived : public Base {
// public:
//     ...
//     Function(int pX)
//     {
//         Base::Function(pX);                  -- Call the Base class Function()
//         ... do the rest of your thing here
//     }
//     ...
// };
//--------------------------------------------------------------------------------------------------------------
void InstrTypeB::Encode
    (
    )
{
    Instr::Encode();
    mEncoding |= mLabel.GetAddress();
}

//--------------------------------------------------------------------------------------------------------------
// GetLabel()
//
// DESCRIPTION:
// mLabel accessor function.
//--------------------------------------------------------------------------------------------------------------
Label InstrTypeB::GetLabel
    (
    )
    const
{
    return mLabel;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
InstrTypeB& InstrTypeB::operator=
    (
    InstrTypeB const& pInstr
    )
{
    if (this != &pInstr) Copy(pInstr);
    return *this;
}

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes this InstrTypeB object a copy of pInstr.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeB::Copy
    (
    InstrTypeB const& pInstr
    )
{
    Instr::Copy(pInstr);          // Copy the base class (Instr) data members to 'this'.
    SetLabel(pInstr.GetLabel());  // Copy the derived class (InstrTypeB) data members to 'this'.
    Encode();                     // Encode to put address of new label into mEncoding.
}

//--------------------------------------------------------------------------------------------------------------
// SetLabel()
//
// DESCRIPTION:
// mLabel mutator function.
//--------------------------------------------------------------------------------------------------------------
void InstrTypeB::SetLabel
    (
    Label const& pLabel
    )
{
    mLabel = pLabel;
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================

