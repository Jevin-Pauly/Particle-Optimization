//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "BucketMan.h"
#include "Bucket.h"

// ------------------------------------------------
// Do All work in the destructor Only
// ------------------------------------------------
Bucket::~Bucket()
{
	//AZUL_INSERT_CODE_HERE;
	Item *delItem = this->poHead;
	while (delItem)
	{
		Item *tempNext = delItem->pNext;
		delete delItem;
		delItem = tempNext;
	}
}

// --- End of File ---

