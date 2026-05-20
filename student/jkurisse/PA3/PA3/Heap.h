//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef HEAP_H
#define HEAP_H

#include "Used.h"
#include "Free.h"

class Heap
{
public:
	// Big four
	Heap();
	Heap(const Heap&) = delete;
	Heap& operator =(const Heap&) = delete;
	~Heap() = default;

	void privAddFreeStats(const Free *pFree);		//Add to count of Frees
	void privAddUsedStats(const Used *pUsed);		//Add to count of Useds

	void privUpdateFreeStats(const Used *pUsed);	//When count of Frees is same but size changes due to subdividing
	//void privUpdateUsedStats(Used *pUsed);

	void privSubFreeStats(const Free *pFree);		//Sub to count of Frees
	void privSubUsedStats(Used *pUsed);				//Sub to count of Useds

	void privAddCoalesceFreeStats(Free *pFree); 

	void removeFree(Free *pFree);					//Removing a Free node from Free list
	void removeUsed(Used *pUsed);					//Removing a Used node from Used list

	void updateFree(Free *pFree);					//Used when subdividing a used block into a new free
	

public:
	// allocation links
	Used	    *pUsedHead;
	Free	    *pFreeHead;

	// Next fit allocation strategy
	Free        *pNextFit;

	uint32_t    currNumUsedBlocks;   // number of current used allocations
	uint32_t    currUsedMem;         // current size of the total used memory

	uint32_t    currNumFreeBlocks;   // number of current free blocks
	uint32_t    currFreeMem;         // current size of the total free memory

	uint32_t    pad;
};

#endif 

// --- End of File ---
