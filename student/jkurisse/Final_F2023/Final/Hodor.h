//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef HODOR_H
#define HODOR_H

#include "Wylis.h"

class Hodor : public Wylis
{
public:
	Hodor();
	Hodor(const Hodor &) = delete;
	Hodor &operator = (const Hodor &) = delete;
	~Hodor();

	virtual void Add(Donut *const pNode);
	virtual void Print();

public:
	Donut *pHead;
};

#endif

// --- End of File ---
