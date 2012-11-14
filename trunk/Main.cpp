//**************************************************************************************************************
// FILE: Main.cpp
//
// DESCRIPTION
// The K1 assembler.
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
#include <iostream>        // For cout, endl
#include "Args.hpp"
#include "Assembler.hpp"
#include "Types.hpp"

//==============================================================================================================
// Starting point.
//==============================================================================================================
int main
    (
    int   argc,
    char *argv[]
    )
{
    try {
        Args args(static_cast<uint>(argc), const_cast<char const **>(argv));
        Assembler assembler(args.GetSrcFilename(), args.GetBinFilename());
        return assembler.Run();
    } catch (int exceptCode) {
        if (exceptCode == Args::EXCEPT_ARGS) std::cout << "Invalid command line. Terminating." << std::endl;
        return -1;
    }
}
