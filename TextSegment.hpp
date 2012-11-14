//**************************************************************************************************************
// CLASS: TextSegment
//
// DESCRIPTION
// Maintains the text segment. The text segment has two data members: a Dictionary of the labels, and a Vector
// of the instructions. TextSegment is derived from Segment.
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
// Preprocess guard.
???

// Figure out what header file you have to include to use the C++ STL std::map class.
???

// Figure out what header file you have to include to use the C++ STL std::vector class.
???

#include <string>
#include "Instr.hpp"
#include "Label.hpp"
#include "Segment.hpp"
#include "Types.hpp"

//==============================================================================================================
// CLASS: TextSegment (derived from Segment)
//==============================================================================================================

// Write the class declaration.
???

...

    //----------------------------------------------------------------------------------------------------------
    // Declare a data member named mInstrs which is an object of the templated STL class vector<Instr>.
    //----------------------------------------------------------------------------------------------------------
    std::vector<Instr> mInstrs;

    //----------------------------------------------------------------------------------------------------------
    // Declare a data member named mLabels which is an object of the templated STL class map<std::string,
    // Label>.
    //----------------------------------------------------------------------------------------------------------
    std::map<std::string, Label> mLabels;
};

// End preprocessor guard.
???
