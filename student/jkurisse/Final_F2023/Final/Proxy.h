//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef PROXY_H
#define PROXY_H

struct Proxy
{
	Proxy(int year);

	Proxy() = default;
	Proxy(const Proxy &in) = default;
	Proxy &operator = (const Proxy &in) = default;
	~Proxy() = default;

	operator int();
	bool operator > (const Proxy &r);

	//Data
	int mYear;
};

#endif

// ---  End of File ---

