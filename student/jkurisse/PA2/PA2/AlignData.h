//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ALIGN_DATA_H
#define ALIGN_DATA_H

// -----------------------------------------------------------
// Add default constructor to each structure
// Initialize all variables to 0
// Do NOT rearrange any data layout...
// These are the classes used with Align::PrintMe();
// -----------------------------------------------------------

struct A
{
// Hint add the default constructor and set variables to zero
	int  a0;
	char a1;
	A()
		: a0(0), a1(0)
	{
	}
};

struct B
{
	float b0;
	float b1;
	bool  b2;
	float b3;
	B()
		: b0(0), b1(0), b2(0), b3(0)
	{
	}
};

struct C
{
	char   c0;
	double c1;
	char   c2;
	C()
		: c0(0), c1(0), c2(0)
	{
	}
};

struct D
{
	A      d0;
	double d1;
	B      d2;
	char   d3;
	C      d4;
	D()
		: d1(0), d3(0)
	{
	}
};

struct E
{
	A    a0;
	C    c0;
	char aa;
	B    b0;
	E()
		: aa(0)
	{
	}
};

#endif

// ---  End of File ---

