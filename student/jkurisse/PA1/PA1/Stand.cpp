//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Stand.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------

// Methods

Stand::Stand()
{
	poHead = NULL;
	numCurrentOrders = 0;
	numPeakOrders = 0;
}

Stand::Stand(const Stand &)
{
}


Stand &Stand::operator = (const Stand &)
{
	return *this;
}

Stand::~Stand()
{
	while (poHead != NULL)
	{
		Order* temp = poHead->pNext;
		delete poHead;
		poHead = temp;
	}
}

int Stand::GetCurrOrders() const
{
	return numCurrentOrders;
}

int Stand::GetPeakOrders() const
{
	return numPeakOrders;
}

void Stand::Remove(const Name name)
{
	for (Order* temp = poHead; temp != NULL; temp = temp->pNext)
	{
		if (temp->name == name)
		{
			if (temp == poHead)
			{
				poHead = temp->pNext;
			}
			if (temp->pNext != NULL)
			{
				temp->pNext->pPrev = temp->pPrev;
				if (temp->pPrev != NULL)
				{
					temp->pPrev->pNext = temp->pNext;
				}
			}
			else
			{
				if (temp->pPrev == NULL)
				{
					delete temp;
					numCurrentOrders--;
					return;
				}
				temp->pPrev->pNext = NULL;
			}
			delete temp;
			numCurrentOrders--;
			return;
		}
	}
}

void Stand::Add(Order * const pOrder)
{
	if (poHead == NULL)
	{
		poHead = pOrder;
	}
	else
	{
		Order* last = poHead;
		while (last->pNext != NULL)
		{
			last = last->pNext;
		}
		last->pNext = pOrder;
		pOrder->pPrev = last;
	}
	numCurrentOrders++;
	if (numPeakOrders < numCurrentOrders)
	{
		numPeakOrders++;
	}
}

//---  End of File ---
