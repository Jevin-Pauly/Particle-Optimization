//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Used.h"
#include "Free.h"
#include "Type.h"

// Add magic here





Free::Free(uint32_t Size)
	:pNext(nullptr), pPrev(nullptr), mData(Size)
{
	SET_FREE(this->mData);
}

Free::Free(Free *pFree)
	:pNext(pFree->pNext), pPrev(pFree->pPrev), mData(pFree->mData)
{

}


// ---  End of File ---