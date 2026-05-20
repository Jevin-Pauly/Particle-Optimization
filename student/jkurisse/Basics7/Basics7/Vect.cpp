//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Vect.h"

// ----------------------------------
// MODIFY this file
// ----------------------------------

// ADD CODE HERE if needed:

// ---  End of File ---

bool Vect::compv(Vect v1, Vect v2)
{
	if (v1.a != v2.a)
	{
		return v1.a < v2.a;
	}
	if (v1.b != v2.b)
	{
		return v1.b < v2.b;
	}
	if (v1.c != v2.c)
	{
		return v1.c < v2.c;
	}
	return true;
}
