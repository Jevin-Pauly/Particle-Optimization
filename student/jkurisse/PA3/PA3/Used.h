//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef USED_H
#define USED_H

#include "Type.h"

class Free;

class Used
{
public:
   // ---------------------------------------------------------
   // Do not reorder, change or add data fields
   //     --> any changes to the data... 0 given to the assignment
   // You can add methods if you wish
   // ---------------------------------------------------------

    Used *pNext;              // next free Type
    Used *pPrev;              // prev free Type  
    uint32_t   mData;    // size (1-bit Type, 1-bit AboveFree, 30 bits memSize)

    Used(uint32_t Size);

    Used() = default;
};

#endif 

// --- End of File ---

