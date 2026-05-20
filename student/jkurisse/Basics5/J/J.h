//----------------------------------------------------------------------------
// Copyrigth 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef J_H
#define J_H

class Dog
{
public:
	int *pVal;

	Dog(int val);

	static int GetVal(Dog &d);
	Dog();

	~Dog();
};

#endif

// End of File
