//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// Add functions and includes as needed

#include "Chunk.h"

int main(int argc, char *argv[])
{
	if (argc != 6)
	{
		return -1;
	}
	if ((strcmp(argv[2], "-t") == 0 || strcmp(argv[2], "-T") == 0) &&
		(strcmp(argv[4], "-n") == 0 || strcmp(argv[4], "-N") == 0))
	{
		if (TypeCheck(argv[3]) == 0 && NameCheck(argv[5]) == 0)
		{
			return 0;
		}
	}
	if ((strcmp(argv[2], "-n") == 0 || strcmp(argv[2], "-N") == 0) &&
		(strcmp(argv[4], "-t") == 0 || strcmp(argv[4], "-T") == 0))
	{
		if (NameCheck(argv[3]) == 0 && TypeCheck(argv[5]) == 0)
		{
			return 0;
		}
	}

	return -1;
}

// ---  End of File ---------------
