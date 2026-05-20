//----------------------------------------------------------------------------
// Copyrigth 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "J.h"

// ----------------------------------------------------------------------
//
// J - Project
//
// Rules: Fix the code to correctly print the predicted output
//        no memory leak
//
// ----------------------------------------------------------------------


Dog::Dog()
	:pVal(0)
{
}

Dog::Dog(int val)
{
	pVal = new int;
	*pVal = val;
}

// Do not modify this method
int Dog::GetVal(Dog &d)
{
	return *(d.pVal);
}


Dog::~Dog()
{
	delete pVal;
}

// End of File
