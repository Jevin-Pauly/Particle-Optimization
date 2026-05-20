//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Proxy.h"
#include "Work.h"

// Add Proxy here

Proxy::Proxy(int year)
	:mYear(year)
{
}

Proxy::operator int()
{
	return mYear;
}

bool Proxy::operator > (const Proxy &r)
{
	return !(this->mYear > r.mYear);
}

// ---  End of File ---

