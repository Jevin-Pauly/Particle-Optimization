//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// Users
#include "Bloated.h"
#include "Node.h"
#include "JediHotCold.h"
#include "JediRedirect.h"

JediHotCold::JediHotCold(const Bloated * const pBloated)
{
    pHotHead = nullptr;
    pColdHead = nullptr;
    pRedirectHead = nullptr;                    

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
    JediHotNode* hotArray = new JediHotNode[NodeSize];
    JediRedirect* redirectArray = new JediRedirect[NodeSize];     
    JediColdNode* coldArray = new JediColdNode[NodeSize];
    curr = pBloated->GetListHead();
    pColdHead = coldArray;
    pHotHead = hotArray;
    pRedirectHead = redirectArray;                            

    //Setting current
    JediHotNode* pointCurrent = hotArray;

    //Iterating through the array of nodes to copy data from bloated
    unsigned int x = 0;
    while (x < NodeSize)
    {
        unsigned int i = 0;
        while (i < JediHotNode::KeyMax)
        {
            coldArray->copy(*curr);
            redirectArray->pCold[i] = coldArray;
            pointCurrent->key[i] = curr->key;
            i++;
            coldArray++;
            curr++;
            x++;
        }
        pointCurrent->pRedirect = redirectArray; 
        pointCurrent->pNext = (pointCurrent + 1);
        pointCurrent->pPrev = (pointCurrent - 1);
        pointCurrent++;
        redirectArray++;
    }
    pointCurrent[0].pPrev = nullptr;
    pointCurrent->pNext = nullptr;
}

JediHotCold::~JediHotCold()
{
    delete[] pColdHead;
    delete[] pRedirectHead;
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
bool JediHotCold::FindKey(int key, JediColdNode *&pFoundColdNode, JediHotNode *&pFoundHotNode)
{
    JediHotNode* test = GetHotHead();
    while (test != NULL)
    {
        int i = 0;
        while (i < JediHotNode::KeyMax)
        {
            if (test->key[i] == key)
            {
                pFoundHotNode = test; 
                pFoundColdNode = test->pRedirect->pCold[i];
                return true;
            }
            i++;
        }
        test = test->pNext; 
    }

    return false;
}

JediHotNode *JediHotCold::GetHotHead() const
{
	return this->pHotHead;
}

// ---  End of File ---

