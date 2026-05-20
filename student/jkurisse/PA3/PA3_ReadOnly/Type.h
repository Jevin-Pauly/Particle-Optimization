//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef TYPE_H
#define TYPE_H

//--------------------------------
//    DO NOT MODIFY this File
//--------------------------------

//  32-bits mData
//  bit(31) --> Type  1-(Free), 0-(Used)
//  bit(30) --> AboveFree  1-(True), 0-(False)
//  bit(29-0) --> memory size 0-1GB

#define SET_USED(x)  x &= 0x7FFFFFFF;
#define SET_FREE(x)  x |= 0x80000000;
#define IS_FREE(x) (x & 0x80000000)

#define CLEAR_ABOVE(x)  x &= 0xBFFFFFFF;
#define SET_ABOVE(x)  x |= 0x40000000;
#define IS_ABOVE(x)  (x & 0x40000000)

#define GET_ALLOC_SIZE(x) (x & 0x3FFFFFFF) 


#endif

// ---  End of File ---
