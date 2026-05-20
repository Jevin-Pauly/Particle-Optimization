//--------------------------------------------------------
// Copyrigth 2023, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include "ComparingStrings.h"

int StringCompare_1(const char *const s1, const char *const s2)
{
	// using strcmp()
	return strcmp(s1, s2);
}

int StringCompare_2(const char *const s1, const char *const s2)
{
	// using memcmp() & strlen()
	size_t lengths1 = strlen(s1);
	size_t lengths2 = strlen(s2);
	if (lengths1 == lengths2)
	{
		return memcmp(s1, s2, lengths2);
	}
	else
	{
		return 1;
	}
}

int StringCompare_3( const char  * const s1, const char * const s2)
{
	// using char by char comparisions
	int i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return 0;
		}
		i++;
	}
	if (s1[i] > s2[i])
	{
		return 1;
	}
	else
	{
		return -1;
	}
}


// ---  End of File ---
