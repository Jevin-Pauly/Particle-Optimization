//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef WORK_H
#define WORK_H

class Work
{
public:
	enum class Name
	{
		Ed,
		Sara
	};

public:
	friend struct Proxy;
	Work(Name name, int yearsExperience);
	Proxy GetYears();
	const char *GetName();

private:
	const char *StringName[2]
	{
		"Ed",
		"Sara"
	};

private:
	int  mYears;
	Name mName;

};

#endif

// ---  End of File ---
