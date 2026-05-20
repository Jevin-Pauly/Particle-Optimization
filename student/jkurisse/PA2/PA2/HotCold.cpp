//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// Users
#include "Bloated.h"
#include "Node.h"
#include "hotcold.h"


HotCold::HotCold(const Bloated * const pBloated)
{
    pHotHead = nullptr;
    pColdHead = nullptr;

    //Get bloated head
    Node* curr = pBloated->GetListHead();
    unsigned int NodeSize = 0;


    //Finding bloatedsize
    while (curr != nullptr)
    {
        curr = curr->pNext;
        NodeSize++;
    }

    //Creating a hot and cold array of size nodesize
    HotNode* hotArray = new HotNode[NodeSize];
    ColdNode* coldArray = new ColdNode[NodeSize];             
    curr = pBloated->GetListHead();
    pColdHead = coldArray;
    pHotHead = hotArray;

    //Setting top, bottom and current
    HotNode* pointTop = hotArray;
    HotNode* pointBottom = hotArray + NodeSize - 1;
    HotNode* pointCurrent = pointTop;

    //Iterating through the array of nodes to copy data from bloated
    unsigned int x = 0;
    while (x < NodeSize)
    {  
        coldArray->copy(*curr); 
        pointCurrent->pCold = coldArray; 
        pointCurrent->key = curr->key;
        pointCurrent->pNext = (pointCurrent + 1);
        pointCurrent->pPrev = (pointCurrent - 1);
        coldArray++;
        pointCurrent++;
        curr++;
        x++;
    }

    //Set the pointers to the edges in the array of nodes to null
    pointBottom->pNext = nullptr;
    pointTop->pPrev = nullptr;

}

HotCold::~HotCold()
{
    delete[] pColdHead;
    delete[] pHotHead;
}

    

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//
// Return true if you find the node
// Return the pointer in the argument list to the HotNode and ColdNode (if found)
//----------------------------------------------------------------------------------
bool HotCold::FindKey(int key, ColdNode *&pFoundColdNode, HotNode *&pFoundHotNode)
{
	//for (HotNode* test = GetHotHead(); test != NULL; test = test->pNext)
    HotNode* test = GetHotHead();
    while (test != NULL)
	{
        if (test->key == key)
        {
            pFoundHotNode = test;
            pFoundColdNode = test->pCold;
            return true;
        }
        test = test->pNext;
	}

	return false;
}

HotNode *HotCold::GetHotHead() const
{
	return this->pHotHead;
}

// ---  End of File ---

