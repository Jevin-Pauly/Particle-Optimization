//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

// Add additional includes if you want

// Some includes that might be useful
// Allowed to use STL algorithm
#include <algorithm>
#include <numeric>

#include "LocalData.h"

// Add methods here

//Constructor to take in vect
LocalData::LocalData(const std::vector<int> &values)
    :vect(values)
{
}

//Average function
float LocalData::GetAverage() const 
{
   
    if (vect.empty()) 
    {
        return 0.0f;
    }
    // Average
    int sum = 0;
    for (int value : vect) 
    {
        sum += value;
    }

    return static_cast<float>(sum) / static_cast<float>(vect.size());
}

//Sorting numbers function
std::vector<int> LocalData::GetSortedValues() const 
{
    // Sort
    std::vector<int> sortedValues = this->vect;
    std::sort(sortedValues.begin(), sortedValues.end());
    return sortedValues;
}

// ---  End of File ---

