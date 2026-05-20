//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "ZipCode.h"

// ----------------------------------
// MODIFY this file
// ----------------------------------

// add code here if you want

// Just stubbed out
bool ZipCode::operator < (const ZipCode &z) const
{
	return (std::strcmp(this->s + 1, z.s + 1) < 0);
}

bool ZipCode::custom(const ZipCode &z)
{
	return z.zip == 0xBB77;
}

//bool ZipCode::custom(const ZipCode &z) const
//{
//	return z.zip == 0xBB77;
//}


// ---  End of File ---
