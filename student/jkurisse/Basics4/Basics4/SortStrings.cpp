//--------------------------------------------------------
// Copyrigth 2023, Ed Keenan, all rights reserved.
//--------------------------------------------------------

#include "SortStrings.h"

int compStrings(const void *a, const void *b)
{
	return strcmp(*(const char **)a, *(const char **)b);  /////
}

int compWordLength(const void *a, const void *b)
{
	int diff = (int)(strlen(*(const char **)a) - strlen(*(const char **)b));
	if (diff == 0)
	{
		return strcmp(*(const char **)a, *(const char **)b);
	}
	return diff;
}



void ReorderAlphabetical(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on alphabetical order, (a begin, z end)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) YOU need to use qsort() - might be a good function to know


	char *nexttok = NULL;
	char *stringcopy = _strdup(inString);

	char *words[10];
	size_t count = 0;

	// Calculate the total length of input
	size_t totalLength = strlen(inString) + 1;

	char *tok = strtok_s(stringcopy, " ", &nexttok);
	while (tok != nullptr)
	{
		size_t wlength = strlen(tok);
		words[count] = new char[wlength + 1];
		strcpy_s(words[count], wlength + 1, tok);
		count += 1;
		tok = strtok_s(nullptr, " ", &nexttok);
	}


	qsort(words, count, sizeof(char *), compStrings);

	//Create copy of outString
	size_t addlength = 0;
	outString[0] = '\0';

	int i = 0;
	while (i < (int)count)
	{
		// Checking buffer space
		if (addlength < totalLength)
		{
			//Add space if not first word
			if (addlength > 0)
			{
				addlength += 1;
				strcat_s(outString, addlength + 1, " ");
			}
			addlength += strlen(words[i]);
			strcat_s(outString, addlength + 1, words[i]);
		}
		else
		{
			printf("Error");
		}
		i++;
	}

	free(stringcopy);
	for (i = 0; i < (int)count; i++)
	{
		free(words[i]);
	}
}



void ReorderWordLength(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on their word length order, (short, longest)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) You need to use qsort() - might be a good function to know

	char *nexttok = nullptr;
	char *stringcopy = _strdup(inString);

	char *words[10];
	size_t count = 0;

	// Calculate the total length of input
	size_t totalLength = strlen(inString) + 1;

	char *tok = strtok_s(stringcopy, " ", &nexttok);

	while (tok != nullptr)
	{
		size_t wlength = strlen(tok);
		words[count] = new char[wlength + 1];
		strcpy_s(words[count], wlength + 1, tok);
		count += 1;
		tok = strtok_s(nullptr, " ", &nexttok);
	}

	//Perform sort
	qsort(words, count, sizeof(char *), compWordLength);

	//Create copy of outString
	size_t addlength = 0;
	outString[0] = '\0';

	int i = 0;
	while (i < (int)count)
	{
		// Checking buffer space
		if (addlength < totalLength)
		{
			//Add space if not first word
			if (addlength > 0)
			{
				addlength += 1;
				strcat_s(outString, addlength + 1, " ");
			}
			addlength += strlen(words[i]);
			strcat_s(outString, addlength + 1, words[i]);
		}
		else
		{
			printf("Error");
		}
		i++;
	}

	//Free
	free(stringcopy);
	for (i = 0; i < (int)count; i++)
	{
		free(words[i]);
	}
}


// ---  End of File ---
