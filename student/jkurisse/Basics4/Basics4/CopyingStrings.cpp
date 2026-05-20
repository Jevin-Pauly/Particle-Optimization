//--------------------------------------------------------
// Copyrigth 2023, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include "CopyingStrings.h"

char *StringCopy_1( char * const dest, const char * const input)
{
	// using strcpy()
	AZUL_REPLACE_ME(dest);
	AZUL_REPLACE_ME(input);
	rsize_t length = strlen(input) + 1;
	strcpy_s(dest, length, input);
	return dest;
}

char *StringCopy_2( char  * const dest, const char * const input)
{
	// using memcpy() and strlen()
	AZUL_REPLACE_ME(dest);
	AZUL_REPLACE_ME(input);
	rsize_t length = strlen(input) + 1;
	memcpy(dest, input, length);
	return dest;
}

char *StringCopy_3( char  * const dest, const char * const input)
{
	// using char by char copies
	AZUL_REPLACE_ME(dest);
	AZUL_REPLACE_ME(input);
	int i = 0;
	while (input[i] != '\0')
	{
		dest[i] = input[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}


// ---  End of File ---
