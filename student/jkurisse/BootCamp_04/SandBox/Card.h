//----------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------

#ifndef CARD_H
#define CARD_H

class Card
{
public:

	// do not add data
	Card *pNext;
	Card *pPrev;
	const char *pName;
	int key;
};

#endif

// --- End of File ---

