//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Mem.h"
#include "Heap.h"
#include "Type.h"

// To help with coalescing... not required
struct SecretPtr
{
	Free *pFree;
};

// ----------------------------------------------------
//  Initialized the Memory block:
//  Update the Heap
//  Create a free block
//  Heap structure links to free hdr
//-----------------------------------------------------
void Mem::initialize()
{
	// Add magic here
	Heap *pHeap = this->GetHeap();
	Heap *pA = pHeap + 1;
	Free *pB = (Free *)pA + 1;

	uint32_t Bottom = TotalSize + (uint32_t)pHeap;
	uint32_t Size = Bottom - (uint32_t)pB;

	Free *pFree = new(pA) Free(Size);

	//Heap Set
	pHeap->pUsedHead = nullptr;
	pHeap->pFreeHead = pFree;
	pHeap->pNextFit = pHeap->pFreeHead;

	pHeap->privAddFreeStats(pFree);
}

// ----------------------------------------------------
//  Do your Magic here:
//  Find a free block that fits
//  Change it to used (may require subdivision)
//  Correct the heap Links (used,free) headers 
//  Update stats
//  Return pointer to block
//-----------------------------------------------------
void *Mem::malloc( const uint32_t _size )
{
	//Getting HeapHead
	Heap *pHeap = this->GetHeap();

	//Use NextFit approach
	Free *findFree = pHeap->pNextFit;

	//Checking for free space
	int checklooped = 0;
	bool foundsize = false;
	while (!foundsize && checklooped < 2)
	{
		while (findFree != nullptr)
		{

			if (GET_ALLOC_SIZE(findFree->mData) >= _size)
			{
				foundsize = true;
				checklooped += 2;
				break;
			}
			findFree = findFree->pNext;
		}
		if (!foundsize)
		{
			findFree = pHeap->pFreeHead;
			checklooped += 1;
		}
	}

	//Incase no size found
	if (findFree == nullptr)
	{
		return nullptr;
	}

	SET_USED(findFree->mData);

	//Finding full size of the free that is chosen
	uint32_t originalSize = findFree->mData;
	Free *saveNext = findFree->pNext;
	Free *savePrev = findFree->pPrev;

	//Doing it before converting it to used to avoid pnext and pprev breaks
	pHeap->removeFree(findFree);

	//Creating space for used block according to size given
	Used *StartingUsed = (Used *)findFree;
	Used *pUsed = new(StartingUsed) Used(_size);


	//Calculating remaining size of the free block after the Used block has been created in it
	uint32_t remainingsize = originalSize - pUsed->mData;
	char *BlockBelow = 0;

	pHeap->privAddUsedStats(pUsed);

	//If no remaining space in free block
	if (remainingsize == 0)
	{
		/*pHeap->removeFree(findFree);*/
		pHeap->privSubFreeStats(findFree);
		Used *UserData = (Used *)pUsed + 1;
		BlockBelow = (char *)UserData + GET_ALLOC_SIZE(pUsed->mData);
	}
	//If remaining space is to small to be considered as another free block
	else if (remainingsize < sizeof(pHeap->pFreeHead))
	{
		printf("Error");
		return nullptr;
	}
	//If there is remaining space in free block
	else
	{
		pHeap->privUpdateFreeStats(pUsed);

		//Set starting point as immediately after the Used block
		Free *StartingPoint = (Free *)((char *)(pUsed)+pUsed->mData + sizeof(Free));
		Free *newFree = new(StartingPoint) Free(remainingsize - sizeof(Free));
		newFree->pNext = saveNext;
		newFree->pPrev = savePrev;

		pHeap->updateFree(newFree);

		SetSP(newFree);
		SET_FREE(newFree->mData);
		BlockBelow = (char *)newFree;
	}

	//Need to do this AFTER updating free else free block follows same list as used
	//Placing Used block as first block in the list
	pUsed->pPrev = nullptr;
	pUsed->pNext = pHeap->pUsedHead;			//Correct direction else fails test

	//Check to see if it is the first used block to update pPrev of Head otherwise
	if (pHeap->pUsedHead != 0)
	{
		pHeap->pUsedHead->pPrev = pUsed;
	}

	pHeap->pUsedHead = pUsed;


	// Set the block below as SET_ABOVE_USED
	if (BlockBelow < (char *)pHeap + TotalSize)
	{
		Used *NextBlock = (Used *)BlockBelow;
		// Set the block below as SET_ABOVE_USED
		if (NextBlock->mData != 0)
		{
			SET_ABOVE_USED(NextBlock->mData);
		}
	}
	return pUsed + 1;
}

// ----------------------------------------------------
//  Do your Magic here:
//  Return the free block to the system
//  May require Coalescing
//  Correct the heap Links (used,free) headers 
//  Update stats
//-----------------------------------------------------
void Mem::free( void * const data )
{
	assert(data != nullptr);

	bool placeaboveasfree = false;

	Heap *pHeap = this->GetHeap();

	assert(pHeap != nullptr);

	//Get Usedptr to goto the the data header
	Used *pUsed = (Used *)data;
	pUsed = pUsed - 1;


	//Remove Used from Used list and change stats
	pHeap->removeUsed(pUsed);
	pHeap->privSubUsedStats(pUsed);

	//Setting flag for ifabovefree since mData gets changed when converting to Free
	if (IS_ABOVE_FREE(pUsed->mData))
	{
		placeaboveasfree = true;
	}
	//Getting size of the used data
	uint32_t size = GET_ALLOC_SIZE(pUsed->mData);


	//Setting CheckBlock to go below the current block we are about to Free
	Used *UserData = (Used *)pUsed + 1;
	char *CheckBlock = (char *)UserData + size;


	//Creating Free block from the removed Used block
	Free *newFree = new((Free *)pUsed) Free(size);
	pHeap->currNumFreeBlocks += 1;

	//Re set the above as free bit for mData
	if (placeaboveasfree)
	{
		SET_ABOVE_FREE(newFree->mData);
	}

	//Flag to skip the iteration and joining link (worst case) if coalesce takes place
	bool skipworstcase = false;

	//CHECK IF BLOCK ABOVE IS ADJACENT  
	if (IS_ABOVE_FREE(newFree->mData))
	{
		skipworstcase = true;

		//Going above current Free block to fetch SP
		SecretPtr *A = (SecretPtr *)newFree - 1;

		pHeap->privAddCoalesceFreeStats(newFree);
		newFree = Coalesce(A->pFree, newFree);
		SET_FREE(newFree->mData);
		pHeap->updateFree(newFree);

	}


	//Checking for out of bounds
	if (CheckBlock < (char *)pHeap + TotalSize)
	{
		//Setting Above as free for block below the current newly freed block
		Free *NextBlock = (Free *)(CheckBlock);
		SET_ABOVE_FREE(NextBlock->mData);

		//CHECK IF BLOCK BELOW IS ADJACENT
		if (NextBlock != NULL)
		{
			if (IS_FREE(NextBlock->mData))
			{
				//Don't add the same memory twice if there is double coalesce
				if (skipworstcase)
				{
					pHeap->privAddCoalesceFreeStats();
				}
				else
				{
					pHeap->privAddCoalesceFreeStats(newFree);
				}
				skipworstcase = true;
				newFree = Coalesce(newFree, NextBlock);
				SET_FREE(newFree->mData);
				pHeap->updateFree(newFree);
			}
		}

	}

	//If either of the above 2 cases are met then skip worst case check
	if (skipworstcase)
	{
		return;
	}

	//WORST CASE NO ADJACENT BLOCKS
	pHeap->worstCaseFree(newFree);
	
	SetSP(newFree);
	pHeap->currFreeMem += GET_ALLOC_SIZE(newFree->mData);
} 





Free *Mem::Coalesce(Free *&Top, Free *&Bottom) const
{
	//IF BOTH FREE BLOCKS EXISTED PRIOR AND HAS LINKS
	if ((Top->pNext != 0 || Top->pPrev != 0) && (Bottom->pNext != 0 || Bottom->pPrev != 0))
	{
		Top->pNext = Bottom->pNext;
	}
	//IF ONLY BOTTOM BLOCK EXISTED PRIOR
	else if (Bottom->pPrev != 0 || Bottom->pNext)
	{
		Top->pNext = Bottom->pNext;
		if (Bottom->pNext != 0)
		{
			Bottom->pNext->pPrev = Top;
		}
		Top->pPrev = Bottom->pPrev;
	}
	//IF ONLY TOP BLOCK EXISTED PRIOR (Nothing to do here since every adjacent link points to Top anyway)
	else
	{
	}

	//Top swallows entirety of Bottom
	Top->mData = Top->mData + sizeof(Free) + Bottom->mData;

	SetSP(Top);
	SET_ABOVE_USED(Top->mData);

	return Top;
}

void *Mem::SetSP(Free *&SPBlock) const
{
	SecretPtr *A = (SecretPtr *)((char *)(SPBlock + 1) + GET_ALLOC_SIZE(SPBlock->mData) - sizeof(SecretPtr));			//Move to SP assignment function
	A->pFree = SPBlock;
	return 0;
}

// --- End of File ---
