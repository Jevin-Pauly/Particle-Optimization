//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "HotList.h"
#include "Hot.h"
#include "List.h"
#include "Node.h"

//---------------------------------------------------------------
// Rules:
// 
// You cannot count anywhere in your creation of the list
//     (iterate the list and create Hot objects on the fly)
// Do not use placement new or new array...
//     (create each Hot object with new individually)
// Assume you will create 1000s of Hot objects...
//     (make sure you clean it up in the destructor)
// You cannot add or change data in Hot, HotList, List, Node
//     (no need for any data changes... make it work as-is)
//
//---------------------------------------------------------------
//
// Add the constructor, destructor and find method here:
// 
//     HotList(const List *const pList);
//     ~HotList();
//     Hot *Find(unsigned int _key);
//
//---------------------------------------------------------------

HotList::HotList(const List *const pList)
	:poHead(nullptr)
{
	//AZUL_UNUSED_VAR(pList);
	//AZUL_INSERT_CODE_HERE;

	//Node *newNode = pList->poHead;
	Hot *prevHotNode = nullptr;

	for (Node *newNode = pList->poHead; newNode != nullptr; newNode = newNode->pNext)
	{
		Hot *newHotNode = new Hot();
		newHotNode->key = newNode->key;
		newHotNode->pData = newNode;

		if (!prevHotNode)
		{
			poHead = newHotNode;
			//prevHotNode = newHotNode;
		}
		else
		{
			prevHotNode->pNext = newHotNode;
			//prevHotNode = newHotNode;
		}
		prevHotNode = newHotNode;
	}


}

HotList::~HotList()
{
	//AZUL_INSERT_CODE_HERE;
	Hot *delHot = poHead;

	while (delHot)
	{
		Hot *tempNext = delHot->pNext;
		delete delHot;
		delHot = tempNext;
	}
}

Hot *HotList::Find(unsigned int _key) const
{
	//AZUL_UNUSED_VAR(_key);
	//AZUL_INSERT_CODE_HERE;
 
	//return AZUL_REPLACE_ME_STUB(nullptr);

	//Hot *iterate = poHead;

	for (Hot *iterate = poHead; iterate != nullptr; iterate = iterate->pNext)
	{
		if (iterate->key == _key)
		{
			return iterate;
		}
	}
	return nullptr;
}

// ---  End of File ---
