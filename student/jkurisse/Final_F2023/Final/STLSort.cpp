//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

// Add additional includes if you want

// Some includes that might be useful
#include <algorithm>

#include "STLSort.h"

// ----------------------------------------------
// Sort the STL Vector:
//
// The list is sorted by LocalData's by average value
//    (Higher average first... last is smallest average)
// Each LocalData is also rearranged/sorted 
//    (Sorted Smallest first... last number Largest)
// 
// Mini Example:
//
//------------------------ -
//Orig:
//------------------------ -
//    2 -1  1    // avg : 0.67
//    6  3  2    // avg : 3.67
//   -1  4 -7    // avg : -1.33
//    4  2  2    // avg : 2.67
//
//------------------------ -
//Sorted :
//------------------------ -    
//    2  3  6    // avg : 3.67     { Each (localData)vector is arranged smallest to largest }
//    2  2  4    // avg : 2.67
//   -1  1  2    // avg : 0.67
//   -7 -1  4    // avg : -1.33v
//
// Assume:
//     Out is initially empty
//     In is read-only
//     Sorted list is stored in Out
//
// Little more realistic sample
//     recommendation:
//        1) test your solution with this data
//        2) then delete your test code for final submission 
//
// ----------------------------
//  Orig:
// ----------------------------
//   5 -9  1
//   6  7  1  3
//  -6 -4  3
//  -5 -2  9 -3  6
//  -3  2
//   3  8 -8  9  9  6  8  
//
//        
// -----------------------------
// Sorted :
// -----------------------------
//  -8  3  6  8  8  9  9   // avg: 5.00
//   1  3  6  7            // avg: 4.25
//  -5 -3 -2  6  9         // avg: 1.00
//  -3  2                  // avg: -0.50
//  -9  1  5               // avg: -1.00
//  -6 -4  3               // avg: -2.33
//
// Hopefully you see the obvious pattern
//
// ----------------------------------------------


//Sorting by average
bool CompareByAverage(const LocalData &lhs, const LocalData &rhs) 
{
    return lhs.GetAverage() > rhs.GetAverage();
}


void SortMe(std::vector<LocalData> &vOut, const std::vector<LocalData> &vIn)
{
	//AZUL_REPLACE_ME(vIn);
	//AZUL_REPLACE_ME(vOut);

    //Sorting based on average first
    std::vector<LocalData> sortedVector = vIn;
    std::sort(sortedVector.begin(), sortedVector.end(), CompareByAverage);

    //Sorting individual values + push into vOut
    //for (size_t i = 0; i < sortedVector.size(); ++i)
    for (LocalData &localData : sortedVector) 
    {
        //LocalData &localData = sortedVector[i];
        std::vector<int> sortedValues = localData.GetSortedValues();
        vOut.push_back(LocalData(sortedValues));
    }
}



// ---  End of File ---
