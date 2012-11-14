//**************************************************************************************************************
// CLASS: Args
//
// DESCRIPTION
// See comments in Args.hpp.
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
#include "Args.hpp"

//==============================================================================================================
// PUBLIC FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Default ctor.
//
// DESCRIPTION:
// Calls Init() to parse the command line for the arguments and options. The expected command line is:
//
// k1as srcfilename [-o binfilename]   OR   k1as [-o binfilename] srcfilename
//
// Note that in the former, pArgv[0] will be "k1as" and pArgv[1] will be the source file name and pArgc will be
// 2. If the -o option is present, it can either precede or follow the source file name. In the former, pArgv[0]
// will be "k1as", pArgv[1] will be "-o", pArgv[2] will be the binary file name, pArtv[3] will be the source
// file name, and pArgc will be 4.
//--------------------------------------------------------------------------------------------------------------
Args::Args
    (
    uint const   pArgc, 
    char const **pArgv
    )
{
    Init(pArgc, pArgv);
}

//--------------------------------------------------------------------------------------------------------------
// Copy ctor.
//--------------------------------------------------------------------------------------------------------------
Args::Args
    (
    Args const& pArgs
    )
{
    Copy(pArgs);
}

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// DESCRIPTION:
// Does nothing, but remember, if you do not write a destructor, then this is the one that will be generated
// for you by the compiler.
//--------------------------------------------------------------------------------------------------------------
Args::~Args
    (
    ) 
{
}

//--------------------------------------------------------------------------------------------------------------
// GetBinFilename()
//
// DESCRIPTION:
// mBinFilename accessor function.
//--------------------------------------------------------------------------------------------------------------
std::string Args::GetBinFilename
    (
    )
    const
{
    return mBinFilename;
}

//--------------------------------------------------------------------------------------------------------------
// GetSrcFilename()
//
// DESCRIPTION:
// mSrcFilename accessor function.
//--------------------------------------------------------------------------------------------------------------
std::string Args::GetSrcFilename
    (
    )
    const
{
    return mSrcFilename;
}

//--------------------------------------------------------------------------------------------------------------
// operator=()
//--------------------------------------------------------------------------------------------------------------
Args& Args::operator=
    (
    Args const& pArgs
    ) 
{
    if (this != &pArgs) Copy(pArgs);
    return *this;    
}

//==============================================================================================================
// PROTECTED FUNCTION MEMBERS
//==============================================================================================================

//--------------------------------------------------------------------------------------------------------------
// Copy()
//
// DESCRIPTION:
// Makes 'this' Args object a copy of pArgs.
//--------------------------------------------------------------------------------------------------------------
void Args::Copy
    (
    Args const& pArgs
    ) 
{
    SetBinFilename(pArgs.GetBinFilename());
    SetSrcFilename(pArgs.GetSrcFilename());
}

//--------------------------------------------------------------------------------------------------------------
// SetBinFilename()
//
// DESCRIPTION:
// mBinFilename mutator function.
//--------------------------------------------------------------------------------------------------------------
void Args::SetBinFilename
    (
    std::string pBinFilename
    )
{
    mBinFilename = pBinFilename;
}

//--------------------------------------------------------------------------------------------------------------
// SetSrcFilename()
//
// DESCRIPTION:
// mSrcFilename mutator function.
//--------------------------------------------------------------------------------------------------------------
void Args::SetSrcFilename
    (
    std::string pSrcFilename
    )
{
    mSrcFilename = pSrcFilename;
}

//--------------------------------------------------------------------------------------------------------------
// Init()
//
// DESCRIPTION:
// Parses the arguments to extract the source and bin file names. Note that -o option is optional. If it is not
// present, then the name of the binary file is the same as the name of the source file but without the .s
// extension, e.g., if the source file name is "foo.s" then the binary file name will be "foo". If the -o option
// is present, then the name of the binary file follows -o on the command line.
//--------------------------------------------------------------------------------------------------------------
void Args::Init
    (
    uint const   pArgc, 
    char const **pArgv
    )
{
    SetBinFilename("");
    SetSrcFilename(""); 
    for (uint i = 1; i < pArgc; i++) {
        std::string arg(pArgv[i]);
        if (arg == "-o") {
            SetBinFilename(pArgv[++i]);
        } else {
            SetSrcFilename(arg);
            size_t dot = arg.find('.');
            arg.erase(dot);
            SetBinFilename(arg);
        }
    }
    if (GetSrcFilename() == "" || GetBinFilename() == "") throw(EXCEPT_ARGS);
}

//==============================================================================================================
// PRIVATE FUNCTION MEMBERS
//==============================================================================================================
