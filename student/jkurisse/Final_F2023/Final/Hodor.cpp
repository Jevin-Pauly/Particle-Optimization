//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Hodor.h"

Hodor::Hodor()
	:pHead(nullptr)
{
	//this->pHead = nullptr;
}

void Hodor::Add(Donut *const pNode)
{
	if(pHead != nullptr)
	{
		pNode->pNext = this->pHead;
	}
	this->pHead = pNode;
}

Hodor::~Hodor()
{
	Donut *delDonut = this->pHead;
	while (delDonut)
	{
		Donut *tempNext = delDonut->pNext;
		delete delDonut;
		delDonut = tempNext;
	}
}

void Hodor::Print()
{
	Trace::out("Evil: %x\n", this->evil);
	Donut *pTmp = this->pHead;
	while(pTmp != nullptr)
	{
		Trace::out("\t%s\n", pTmp->pName);
		pTmp = pTmp->pNext;
	}
}

// --- End of File ---
