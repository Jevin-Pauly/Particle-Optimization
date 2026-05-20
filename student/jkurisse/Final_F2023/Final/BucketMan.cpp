//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "BucketMan.h"

// ------------------------------------------------
// Do All work in the destructor Only
// ------------------------------------------------
BucketMan::~BucketMan()
{
	//AZUL_INSERT_CODE_HERE;
	Bucket *delBucket = this->poHead;
	while (delBucket)
	{
		Bucket *tempNext = delBucket->pNext;
		delete delBucket;
		delBucket = tempNext;
	}
}

// --- End of File ---

