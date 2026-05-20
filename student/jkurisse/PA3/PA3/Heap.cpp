//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Heap.h"
#include "Mem.h"

Heap::Heap()
:	pUsedHead(nullptr),
	pFreeHead(nullptr),
	pNextFit(nullptr),
    currNumUsedBlocks(0),
    currUsedMem(0),
    currNumFreeBlocks(0),
    currFreeMem(0)
{ 
}

void Heap::privAddFreeStats(const Free *pFree)
{
    assert(pFree);

    this->currNumFreeBlocks += 1;
    this->currFreeMem += GET_ALLOC_SIZE(pFree->mData);
}

void Heap::privAddUsedStats(const Used *pUsed)
{
    assert(pUsed);

    this->currNumUsedBlocks += 1;
    this->currUsedMem += GET_ALLOC_SIZE(pUsed->mData);
}

void Heap::privUpdateFreeStats(const Used *pUsed)
{
    assert(pUsed);

    this->currFreeMem -= GET_ALLOC_SIZE(pUsed->mData) + sizeof(Free);	
}

//void Heap::privUpdateUsedStats(Used *pUsed)
//{
//}

void Heap::privSubFreeStats(const Free *pFree)
{
    assert(pFree);

    this->currNumFreeBlocks -= 1;
    this->currFreeMem -= GET_ALLOC_SIZE(pFree->mData);
}

void Heap::privSubUsedStats(Used *pUsed)
{
    assert(pUsed);

    this->currNumUsedBlocks -= 1;
    this->currUsedMem -= GET_ALLOC_SIZE(pUsed->mData);
}



void Heap::privAddCoalesceFreeStats(Free *pFree)
{
	assert(pFree);

	this->currNumFreeBlocks -= 1;
	this->currFreeMem += GET_ALLOC_SIZE(pFree->mData) + sizeof(Free);
}








void Heap::removeFree(Free *findFree)
{
	//Check if only block
	if (findFree->pNext == nullptr && findFree->pPrev == nullptr)
	{
		this->pFreeHead = nullptr;		
		this->pNextFit = nullptr;
	}
	//Check if last block
	else if (findFree->pNext == nullptr)
	{
		findFree->pPrev->pNext = nullptr;
		this->pNextFit = this->pFreeHead;
	}
	//Check if first block
	else if (findFree->pPrev == nullptr)
	{
		findFree->pNext->pPrev = nullptr;
		this->pFreeHead = findFree->pNext;		
		this->pNextFit = this->pFreeHead;

	}
	//If it is a block in between
	else
	{
		findFree->pNext->pPrev = findFree->pPrev;
		findFree->pPrev->pNext = findFree->pNext;
		this->pNextFit = findFree->pNext;
	}
}

void Heap::removeUsed(Used *pUsed)
{
	//Check if only block
	if (pUsed->pPrev == nullptr && pUsed->pNext == nullptr)
	{
		this->pUsedHead = nullptr;
	}
	//Check if first block
	else if (pUsed->pPrev == nullptr)
	{
		this->pUsedHead = pUsed->pNext;
		pUsed->pNext->pPrev = nullptr;
	}
	//Check if last block
	else if (pUsed->pNext == nullptr)
	{
		pUsed->pPrev->pNext = nullptr;
	}
	//If it is a block in between
	else
	{
		pUsed->pNext->pPrev = pUsed->pPrev;
		pUsed->pPrev->pNext = pUsed->pNext;
	}
}


void Heap::updateFree(Free *newFree)
{
	//Check if only block
	if (newFree->pNext == nullptr && newFree->pPrev == nullptr)
	{
		this->pFreeHead = newFree;			
		this->pNextFit = newFree;
	}
	//Check if last block
	else if (newFree->pNext == nullptr)
	{
		newFree->pPrev->pNext = newFree;
		this->pNextFit = newFree;
	}
	//Check if first block
	else if (newFree->pPrev == nullptr)
	{
		newFree->pNext->pPrev = newFree;
		this->pFreeHead = newFree;		
		this->pNextFit = newFree;
	}
	//If it is a block in between
	else
	{
		newFree->pNext->pPrev = newFree;
		newFree->pPrev->pNext = newFree;
		this->pNextFit = newFree;
	}
}

// --- End of File ---
 