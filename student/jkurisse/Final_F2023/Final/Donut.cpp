//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Donut.h"

Donut::Donut(const char *const name)
{
	unsigned int size = strlen(name) + 1;
	this->pName = new char[size];
	strcpy_s(this->pName, size, name);
	this->pNext = nullptr;
}


Donut::~Donut()
{
	delete[] pName;
}
// --- End of File ---
