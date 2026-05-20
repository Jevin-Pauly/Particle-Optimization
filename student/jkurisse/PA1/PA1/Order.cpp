//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Order.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------

// Methods

Order::Order()
{
	this->name = Name::Unknown;
	poHead = NULL;
}

Order::Order(const Order &copy)
{
	this->name = copy.name;
	poHead = NULL;
	pNext = NULL;
	pPrev = NULL;

	HotDog *copydog = copy.poHead;
	

	for (HotDog* prev = copydog->pPrev;copydog != NULL; copydog = copydog->pNext)
	{
		HotDog *addnew = new HotDog(*copydog);
		addnew->pPrev = prev;
		if (prev != NULL)
		{
			prev->pNext = addnew;
		}
		prev = addnew;
		if (!this->poHead)
		{
			this->poHead = addnew;
		}
	}
}


Order &Order::operator = (const Order &copy)
{
	if (this != &copy)
	{
		this->name = copy.name;
		this->poHead = NULL;
		this->pNext = NULL;
		this->pPrev = NULL;

		HotDog* copydog = copy.poHead;
		HotDog* prev = copydog->pPrev;

		for (; copydog != NULL; copydog = copydog->pNext)
		{
			HotDog* addnew = new HotDog(*copydog);
			addnew->pPrev = prev;
			if (prev != NULL)
			{
				prev->pNext = addnew;
			}
			prev = addnew;
			if (!this->poHead)
			{
				this->poHead = addnew;
			}
		}
	}
	return *this;
}

Order::~Order()
{
	for (HotDog* temp = poHead; poHead != NULL; poHead = temp)
	{
		temp = poHead->pNext;
		delete poHead;
	}
}

Order::Order(Name name)
{
	this->name = name;
	poHead = NULL;
	pNext = NULL;
	pPrev = NULL;
}

void Order::Add(HotDog *p)
{
	if (poHead == NULL)
	{
		poHead = p;
	}
	else
	{
		poHead->pPrev = p;
		p->pNext = poHead;
		poHead = p;
	}
}

void Order::Remove(HotDog *p)
{
	if (p != NULL)
	{
		if (poHead == p)
		{
			poHead = poHead->pNext;
		}
		if (p->pPrev != NULL)
		{
			p->pPrev->pNext = p->pNext;
		}
		if (p->pNext != NULL)
		{
			p->pNext->pPrev = p->pPrev;
		}
		delete p;
	}
}

void Order::SetName(Name _name)
{
	this->name = _name;
}




//---  End of File ---
