//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef WYLIS_H
#define WYLIS_H

#include "Donut.h"

class Wylis
{
public:
	Wylis();
	Wylis(const Wylis &) = delete;
	Wylis &operator = (const Wylis &) = delete;
	~Wylis();

	virtual void Print() = 0;
	virtual void Add(Donut *const pTmp) = 0;

public:
	bool evil;
};

#endif

// --- End of File ---
