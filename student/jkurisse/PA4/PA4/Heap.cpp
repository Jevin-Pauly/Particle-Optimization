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

void Heap::privSubUsedStats(const Used *pUsed)
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


void Heap::privAddCoalesceFreeStats()
{
	this->currNumFreeBlocks -= 1;
	this->currFreeMem += sizeof(Free);
}








void Heap::removeFree(const Free *findFree)
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

void Heap::removeUsed(const Used *pUsed)
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
		if (newFree->mData > pFreeHead->mData)
		{
			this->pNextFit = newFree;
		}
	}
	//If it is a block in between
	else
	{
		newFree->pNext->pPrev = newFree;
		newFree->pPrev->pNext = newFree;
		this->pNextFit = newFree;
	}
}

void Heap::worstCaseFree(Free *newFree)
{
	Free *Search = this->pFreeHead;
	//If no other blocks
	if (Search == 0)
	{
		newFree->pNext = 0;
		newFree->pPrev = 0;
		this->pFreeHead = newFree;
		this->pNextFit = this->pFreeHead;
	}
	//If current Free should be first block
	else if (newFree < Search)
	{
		newFree->pNext = Search;
		newFree->pPrev = 0;
		Search->pPrev = newFree;
		if (newFree->mData > Search->mData)
		{
			this->pNextFit = this->pFreeHead;
		}
		this->pFreeHead = newFree;
	}
	else if (newFree > Search)
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
	else
	{
	}
}
// --- End of File ---
