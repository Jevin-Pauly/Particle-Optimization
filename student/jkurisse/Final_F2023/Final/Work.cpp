//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Work.h"
#include "Proxy.h"

Work::Work(Name name, int yearsExperience)
{
	this->mName = name;
	this->mYears = yearsExperience;
}


Proxy Work::GetYears()
{
	return Proxy(this->mYears);
}

const char *Work::GetName()
{
	return this->StringName[(int)this->mName];
}

// ---  End of File ---

