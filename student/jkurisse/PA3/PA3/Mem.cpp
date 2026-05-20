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
	while (findFree != nullptr)					
	{
		
		if (GET_ALLOC_SIZE(findFree->mData) >= _size)
		{
			break;
		}
		findFree = findFree->pNext;
	}

	//Incase no size found
	if (findFree == nullptr)		//Need to fill later
	{
		printf("error");
	}

	SET_USED(findFree->mData);

	//Finding full size of the free that is chosen
	uint32_t originalSize = findFree->mData;

	//Creating space for used block according to size given
	Used *pUsed = new((Used *)findFree) Used(_size);


	//Placing Used block as first block in the list
	pUsed->pPrev = nullptr;
	pUsed->pNext = pHeap->pUsedHead;

	//Check to see if it is the first used block to update pPrev of Head otherwise
	if (pHeap->pUsedHead != 0)
	{
		pHeap->pUsedHead->pPrev = pUsed;
	}
	pHeap->pUsedHead = pUsed;



	//Calculating remaining size of the free block after the Used block has been created in it
	uint32_t remainingsize = originalSize - pUsed->mData;


	pHeap->privAddUsedStats(pUsed);



	//If no remaining space in free block
	if (remainingsize == 0)
	{
		pHeap->removeFree(findFree); 
		pHeap->privSubFreeStats(findFree);
	}
	//If remaining space is to small to be considered as another free block
	else if (remainingsize < sizeof(pHeap->pFreeHead))
	{
		printf("Error");			//Need to fill this up later
	}
	//If there is remaining space in free block
	else
	{
		pHeap->privUpdateFreeStats(pUsed); 

		//Set starting point as immediately after the Used block
		Free *StartingPoint = (Free *)((char *)(pUsed) + pUsed->mData + sizeof(Free));
		Free *newFree = new(StartingPoint) Free(remainingsize);
		newFree->mData = remainingsize - sizeof(Free);
		newFree->pNext = findFree->pNext;
		newFree->pPrev = findFree->pPrev;														//Need to put this in a function

		pHeap->updateFree(newFree);

		SecretPtr *A = (SecretPtr *)((char *)(newFree) + GET_ALLOC_SIZE(newFree->mData) - sizeof(SecretPtr));		//Need to create SecretPtr assignment function
		A->pFree = newFree;
		SET_FREE(newFree->mData);
		
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

	Heap *pHeap = this->GetHeap(); 

	assert(pHeap != nullptr);

	//Get Usedptr to goto the the data header
	Used *pUsed = (Used *)data; 
	pUsed = pUsed - 1;

	
	//Remove Used from Used list and change stats
	pHeap->removeUsed(pUsed);
	pHeap->privSubUsedStats(pUsed);
	

	//Getting size of the used data
	uint32_t size = GET_ALLOC_SIZE(pUsed->mData);


	//Setting CheckBlock to go below the current block we are about to Free
	Used *UserData = (Used *)pUsed + 1; 
	char *CheckBlock = (char *)UserData + size; 


	//Creating Free block from the removed Used block
	Free *newFree = new((Free *)pUsed) Free(size); 
	pHeap->currNumFreeBlocks += 1;
	 

	//Checking for out of bounds
	if (CheckBlock < (char *)pHeap + TotalSize)
	{

		bool skipworstcase = false;

		//CHECK IF BLOCK ABOVE IS ADJACENT  
		if (IS_ABOVE(pUsed->mData))
		{
			skipworstcase = true;

			//Going above current Free block to fetch SP
			SecretPtr *A = (SecretPtr *)newFree - 1;		

			newFree = Coalesce(A->pFree, newFree);		
			pHeap->privAddCoalesceFreeStats(newFree);
			SET_FREE(newFree->mData);
			pHeap->updateFree(newFree);

		}

		//CHECK IF BLOCK BELOW IS ADJACENT
		Free *NextBlock = (Free *)(CheckBlock);			//Correct
		if (IS_FREE(NextBlock->mData))
		{
			skipworstcase = true;

			pHeap->privAddCoalesceFreeStats(newFree);
			newFree = Coalesce(newFree, NextBlock);
			SET_FREE(newFree->mData);
			pHeap->updateFree(newFree);
		}

		//If either of the above 2 cases are met then skip worst case check
		if (skipworstcase)
		{
			return;
		}
	}

	//WORST CASE NO ADJACENT BLOCKS
	Free *Search = pHeap->pFreeHead; 
	//If no other blocks
	if (Search == 0)									//Need to move this entire check to a function
	{
		newFree->pNext = 0;
		newFree->pPrev = 0;
		pHeap->pFreeHead = newFree;
		pHeap->pNextFit = pHeap->pFreeHead;
	}
	//If current Free should be first block
	else if (newFree < Search)
	{
		newFree->pNext = Search;
		newFree->pPrev = 0;
		Search->pPrev = newFree;
		pHeap->pFreeHead = newFree;
		pHeap->pNextFit = pHeap->pFreeHead;
	}
	else
	{
		while (Search->pNext != nullptr)
		{
			//If current Free is between two blocks
			if (newFree > Search && newFree < Search->pNext)
			{
				newFree->pNext = Search->pNext;
				newFree->pPrev = Search;
				Search->pNext = newFree;
				newFree->pNext->pPrev = newFree;
				break;
			}
			Search = Search->pNext;
		}
		//If current Free should be last block
		if (Search->pNext == nullptr)
		{
			Search->pNext = newFree;
			newFree->pPrev = Search;
			newFree->pNext = nullptr;
		}
	}
	pHeap->currFreeMem += GET_ALLOC_SIZE(newFree->mData);
} 


Free* Mem::Coalesce(Free *&Top, Free *&Bottom)				
{
	Top->pNext = Bottom->pNext;
	if (Bottom->pNext != nullptr)
	{
		Bottom->pNext->pPrev = Top;
	}
	Top->mData = Top->mData + sizeof(Free) + Bottom->mData;

	SecretPtr *A = (SecretPtr *)((char *)(Top + 1) + GET_ALLOC_SIZE(Top->mData) - sizeof(SecretPtr));			//Move to SP assignment function
	A->pFree = Top;

	return Top;
}

// --- End of File ---
