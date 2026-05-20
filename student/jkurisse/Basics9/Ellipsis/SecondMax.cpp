//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// you can use stl for the sort if you wish
#include <vector>
#include <algorithm>

#include "SecondMax.h"

int SecondMax(int count, ...)
{
	// Do your magic here:
	//AZUL_UNUSED_VAR(count);

	va_list list;
	va_start(list, count);
	//First val from input
	int check = va_arg(list, int);
	int first = check;
	int second = check;

	//Read every other value
	for (int i = 1; i < count; i++)
	{
		check = va_arg(list, int);
		if (check > first)
		{
			second = first;
			first = check;
		}
		else if (check > second && check < first)
		{
			second = check;
		}
		else
		{
		}
	}
	va_end(list);

	return second;
	//return -1;
}

// ---  End of File ---------------
