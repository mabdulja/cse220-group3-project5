//**************************************************************************************************************
// CLASS: Instr
//
// DESCRIPTION
// Maintains an instruction with no operands. This is the superclass of all instruction classes with operands:
// InstrTypeB, InstrTypeR, InstrTypeRI, and InstrTypeRV. Also, instructions with no operands (so-called type N
// instructions) are instantiated as objects of this class.
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
#ifndef INSTR_HPP
#define INSTR_HPP

#include <string>
#include "Types.hpp"

//==============================================================================================================
// CLASS: Instr
//==============================================================================================================
class Instr {
public:
    //==========================================================================================================
    // PUBLIC CONSTANT MEMBERS
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // These are the opcode bits for each instruction.
    //---------------------------------------------------------------------------------------------------------
    static Byte const OPCODE_LD   = 0x00;  // 00000
    static Byte const OPCODE_LDI  = 0x01;  // 00001
    static Byte const OPCODE_LDA  = 0x02;  // 00010
    static Byte const OPCODE_ST   = 0x03;  // 00011
    static Byte const OPCODE_ADD  = 0x04;  // 00100
    static Byte const OPCODE_NEG  = 0x05;  // 00101
    static Byte const OPCODE_ROL  = 0x06;  // 00110
    static Byte const OPCODE_NOR  = 0x07;  // 00111
    static Byte const OPCODE_PUSH = 0x08;  // 01000
    static Byte const OPCODE_POP  = 0x09;  // 01001
    static Byte const OPCODE_BR   = 0x0A;  // 01010
    static Byte const OPCODE_BEQ  = 0x0B;  // 01011
    static Byte const OPCODE_BLT  = 0x0C;  // 01100
    static Byte const OPCODE_BSUB = 0x0D;  // 01101
    static Byte const OPCODE_RET  = 0x0E;  // 01110
    static Byte const OPCODE_IN   = 0x0F;  // 01111
    static Byte const OPCODE_OUT  = 0x10;  // 10000
    static Byte const OPCODE_HALT = 0x11;  // 10001

    //==========================================================================================================
    // PUBLIC FUNCTION MEMBERS
    //==========================================================================================================

    //---------------------------------------------------------------------------------------------------------
    // Default ctor.
    //---------------------------------------------------------------------------------------------------------
    Instr
        (
        std::string const& pMnemonic = ""  // Every instruction has a mnemonic.
        );

    //---------------------------------------------------------------------------------------------------------
    // Copy ctor.
    //---------------------------------------------------------------------------------------------------------
    Instr
        (
        Instr const& pInstr
        );

    //---------------------------------------------------------------------------------------------------------
    // Dtor.
    //
    // VERY IMPORTANT: See http://www.parashift.com/c++-faq-lite/virtual-functions.html#faq-20.7
    //
    // A destructor should be made virtual when it is possible that a pointer to a derived class is used
    // to delete an object when the compiler thinks that ptr is actually a pointer to the base class. For
    // example,
    //
    // class C {
    // public:
    //     C()  { }  -- Default ctor
    //     ~C() { }  -- Dtor
    // };
    // 
    // class D : public C {   -- A "D" is a special type of "C". We can say that a "D" IS-A "C".
    // public:                -- But the converse is not true, i.e., a "C" is not a "D".
    //     D()  { }           -- Replace "C" with "Rectangle" and "D" with "Square". A "Square"
    //     ~D() { }           -- is a "Rectangle" (true), but a "Rectangle" is NOT a "Square".
    // };
    // 
    // void SomeFunction(C *ptrC)  -- Formal param is ptr to a "C", but since a "D" is also a "C"
    // {                           -- the actual param can be either a ptr to a "C" or a ptr to a "D".
    //     delete ptrC;            -- If ptrC is a ptr to a "C" this invokes ptrC->~C(). If ptrC is
    // }                           -- a ptr to a "D" this will still invoke ptrC->~C() because the
    //                             -- base class C destructor IS NOT virtual and the compiler does
    //                             -- not know that ptrC is actually a ptr to a "D".
    // 
    // void SomeOtherFunction(D *ptrD)  -- Formal param is ptr to a "D", so the actual param can be a
    // {                                -- ptr to a "D", but it cannot be a ptr to a "C" because a "C"
    // }                                -- is NOT a "D".
    //
    // void YetAnotherFunction()
    // {
    //     C *ptrC = new C();       -- ptrC is a pointer to a C
    //     D *ptrD = new D();       -- ptrD is a pointer to a D
    //     SomeFunction(ptrC);      -- Actual param is ptr to C, formal param is ptr to C. Compiles.
    //     SomeFunction(ptrD);      -- Actual param is ptr to D, formal param is ptr to C. Compiles.
    //     ptrC = new C();          --
    //     ptrD = new D();          --
    //     SomeOtherFunction(ptrC); -- Actual param is ptr to C, formal param is ptr to D. Syntax error.
    //     SomeOtherFunction(ptrD); -- Actual param is ptr to D, formal param is ptr to D. Compiles.
    // }
    //
    // Function calls are NOT automatically polymorphic in C++ unless the desired function is declared
    // virtual (i.e., the default binding mode is stating binding; polymorphism requires dynamic binding).
    // To guarantee that ptrC->~D() is called in SomeFunction(C *ptrC) when ptrC is actually a pointer
    // to a "D", then the C class destructor MUST be declared virtual, for example,
    //
    // class C {
    // public:
    //     C()          { }  -- Default ctor
    //     virtual ~C() { }  -- A virtual dtor.
    // };
    // 
    // class D : public C {
    // public:                -- ~D() can be virtual or nonvirtual. If you expect to derive a new class
    //     D()  { }           -- from D, then make ~D() virtual.
    //     ~D() { } OR virtual ~D() { }           
    // };
    // 
    // void SomeFunction(C *ptrC)  -- Formal param is ptr to a "C", but since a "D" is also a "C"
    // {                           -- the actual param can be either a ptr to a "C" or a ptr to a "D".
    //     delete ptrC;            -- If ptrC is a ptr to a "C" this invokes ptrC->~C(). If ptrC is
    // }                           -- a ptr to a "D" this will now invoke ptrC->~D() because ~C() is virtual
    //                             -- and therefore the compiler will perform dynamic binding of the object
    //                             -- to the function call.
    //
    // To summarize: Any function (not just dtor's) in a base class which is going to be called polymorphically
    // in a derived class MUST be declared as a virtual function.
    //---------------------------------------------------------------------------------------------------------
    virtual ~Instr
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // Encode()
    //
    // DESCRIPTION: 
    // Also virtual because each of the Instr derived classes is going to override this function and we want to
    // call those overridden functions polymorphically. For example,
    //
    // void SomeFunction(Instr *pInstr)
    // {
    //     ...
    //     pInstr->Encode(); -- Call the correct polymorphic Encode() function depending on the "real" type of
    // }                     -- the object that pInstr points to, eg., Could be a ptr to an "InstrTypeR" object
    //
    // void Foo()
    // {
    //     InstrTypeR *instrR = new InstrTypeR(...);
    //     SomeFunction(instrR);                        -- Needs to call InstrTypeR::Encode()
    //     InstrTypeRI *instrRI = new InstrTypeR(...);
    //     SomeFunction(instrRI);                       -- Needs to call InstrTypeRI::Encode()
    // }
    //---------------------------------------------------------------------------------------------------------
    virtual void Encode
        (
        );

    //---------------------------------------------------------------------------------------------------------
    // GetEncoding()
    //---------------------------------------------------------------------------------------------------------
    Word GetEncoding
        (
        )
        const;

    //---------------------------------------------------------------------------------------------------------
    //  GetMnemonic()
    //---------------------------------------------------------------------------------------------------------
    std::string GetMnemonic
        (
        )
        const;

    //---------------------------------------------------------------------------------------------------------
    // operator=()
    //---------------------------------------------------------------------------------------------------------
    Instr& operator=
        (
        Instr const& pInstr
        );

    //---------------------------------------------------------------------------------------------------------
    // SetMnemonic()
    //---------------------------------------------------------------------------------------------------------
    void SetMnemonic
        (
        std::string const& pMnemonic
        );

protected:
    //==========================================================================================================
    // PROTECTED FUNCTION MEMBERS:
    //==========================================================================================================
    
    //----------------------------------------------------------------------------------------------------------
    // Copy()
    //----------------------------------------------------------------------------------------------------------
    void Copy
        (
        Instr const& pInstr
        );

    //---------------------------------------------------------------------------------------------------------
    // Returns the opcode bits for this Instr.
    //---------------------------------------------------------------------------------------------------------
    Byte GetOpcode
        (
        )
        const;

    //---------------------------------------------------------------------------------------------------------
    // SetEncoding()
    //---------------------------------------------------------------------------------------------------------
    Instr& SetEncoding
        (
        Word const pEncoding
        );

    //==========================================================================================================
    // PROTECTED DATA MEMBERS:
    //==========================================================================================================

    // Each instruction consists of a 32-bit binary encoding and a mnemonic. Derived classes of Instr add
    // additional data members, e.g., InstrTypeB has a Label data member in addition to the two you see below.

    Word        mEncoding;
    std::string mMnemonic;
};

#endif
