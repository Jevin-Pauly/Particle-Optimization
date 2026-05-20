//----------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------

#ifndef GARAGE_H
#define GARAGE_H

#include "Car.h"

class Garage
{
public:
// implement these big 4
	Garage();
	Garage(const Garage &);
	Garage & operator =(const Garage &);
	~Garage();

// add methods

	// do not add data
	Car *pHead;
};

#endif

// --- End of File ---

