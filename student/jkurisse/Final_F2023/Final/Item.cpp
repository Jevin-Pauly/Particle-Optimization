//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Bucket.h"
#include "Item.h"

// ------------------------------------------------
// Do All work in the destructor Only
// ------------------------------------------------
Item::~Item()
{
	//AZUL_INSERT_CODE_HERE;
	delete poData;
}

// --- End of File ---

