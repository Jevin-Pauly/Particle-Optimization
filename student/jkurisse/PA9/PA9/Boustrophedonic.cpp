//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Boustrophedonic.h"

void Boustropehedic::Remove(Node *&pHead, int row, int col)
{
	if (pHead == nullptr)
	{
		return;
	}
	Node *pNode = pHead;

	//Node, column and row tracker
	int nodeNum = 0;
	int colNum = 0;
	int rowNum = 0;

	//Column counter
	while (pNode != 0)
	{
		colNum += 1;
		pNode = pNode->pEast;
	}

	//Row counter
	//Use right flag to see if we can keep moving right (else move south once then left)
	bool right = 1;
	pNode = pHead;
	int i;
	while (pNode != nullptr)
	{		
		if (right)
		{
			i = 1;
			//Since only one node is being removed from complete Cow List
			//Using column length to get to the end (to jump to next row)
			while (i < colNum)
			{
				pNode = pNode->pEast;
				i += 1;
			}
			nodeNum += colNum;
			pNode = pNode->pSouth;
			right = 0;
			rowNum += 1;
		}
		else
		{
			i = 1;
			while (i < colNum)
			{
				pNode = pNode->pWest;
				i += 1;
			}
			nodeNum += colNum;
			pNode = pNode->pSouth;
			right = 1;
			rowNum += 1;
		}
	}

	right = 1;
	pNode = pHead;
	Node *Center = nullptr;
	Node *North = nullptr;
	Node *South = nullptr;
	Node *East = nullptr;
	Node *West = nullptr;

	int rowCheck = 0;
	int colCheck = 0;
	while (pNode != nullptr)
	{
		//Finding node to be removed and surrounding nodes (each of these ifs should hit atmost one time)
		if (rowCheck == row && colCheck == col)
		{
			Center = pNode;
		}
		if (rowCheck == row - 1 && colCheck == col)
		{
			North = pNode;
		}
		if (rowCheck == row + 1 && colCheck == col)
		{
			South = pNode;
		}
		if (rowCheck == row && colCheck == col - 1)
		{
			West = pNode;
		}
		if (rowCheck == row && colCheck == col + 1)
		{
			East = pNode;
		}

		//Moving to next node (normal traversal)
		if (right)
		{
			if (pNode->pEast != nullptr)
			{
				pNode = pNode->pEast;
				colCheck++;
			}
			else
			{
				pNode = pNode->pSouth;
				right = 0;
				rowCheck++;
			}
		}
		else
		{
			if (pNode->pWest != nullptr)
			{
				pNode = pNode->pWest;
				colCheck--;
			}
			else
			{
				pNode = pNode->pSouth;
				right = 1;
				rowCheck++;
			}
		}
	}

	//Relink all the surrounding nodes
	if (North != nullptr)
	{
		if (North->pSouth != nullptr)
		{
			North->pSouth = South;
		}
	}
	if (South != nullptr)
	{
		if (South->pNorth != nullptr)
		{
			South->pNorth = North;
		}
	}
	if (East != nullptr)
	{
		if (East->pWest != nullptr)
		{
			East->pWest = West;
		}
	}
	if (West != nullptr)
	{
		if (West->pEast != nullptr)
		{
			West->pEast = East;
		}
	}

	//Check if pHead is removed, then shift pHead
	if (Center == pHead)
	{
		if (pHead->pEast)
		{
			pHead = pHead->pEast;
		}
		else
		{
			pHead = pHead->pSouth;
		}
	}
	delete Center;
}

// ---  End of File ---

