//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef FREE_H
#define FREE_H

#include "Type.h"

class Used;

class Free
{
public:

    // ---------------------------------------------------------
    // Do not reorder, change or add data fields
    //     --> any changes to the data... 0 given to the assignment
    // You can add methods if you wish
    // ---------------------------------------------------------

    Free *pNext;              // next free Type
    Free *pPrev;              // prev free Type  
    uint32_t   mData;    // size (1-bit Type, 1-bit AboveFree, 30 bits memSize)
                   
    Free(uint32_t Size);
    Free(Free *pFree);

    Free() = default;                      
};

#endif 

// --- End of File ---
