//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef DONUT_H
#define DONUT_H

class Donut
{
public:
	Donut() = delete;
	Donut(const Donut &) = delete;
	Donut &operator = (const Donut &) = delete;
	~Donut();

	Donut(const char *const name);

public:
	Donut *pNext;
	char *pName;
};

#endif

// --- End of File ---
