//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Free.h"
#include "Used.h"

// Add code here
Used::Used(uint32_t Size)
	:pNext(nullptr), pPrev(nullptr), mData(Size)
{
	SET_USED(this->mData);
}

// ---  End of File ---

