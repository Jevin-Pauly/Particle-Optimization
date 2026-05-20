//--------------------------------------------------------
// Copyrigth 2023, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include"LengthOfStrings.h"

size_t LengthOfString_1( const char  * const input)
{
	// using strlen()
	return strlen(input);
}

size_t LengthOfString_2( const char  * const input)
{
	// using char by char
	size_t count = 0;
	while (input[count] != '\0')
	{
		count += 1;
	}
	return count;
}


// ---  End of File ---

