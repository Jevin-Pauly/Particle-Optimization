//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Chunk.h"

// Add code here... if desired

int TypeCheck(char *type)
{
	if (strcmp(type, "VERTS_TYPE") == 0) 
	{
		return 0;
	}	
	if (strcmp(type, "NORMS_TYPE") == 0)
	{
		return 0;
	}
	if (strcmp(type, "ANIM_TYPE") == 0)
	{
		return 0;
	}
	if (strcmp(type, "TEXTURE_TYPE") == 0)
	{
		return 0;
	}
	if (strcmp(type, "UV_TYPE") == 0)
	{
		return 0;
	}

	return -1;
}

int NameCheck(char *name)
{
	if (strlen(name) < 20 && strlen(name) > 0)
	{
		return 0;
	}

	return -1;
}

// ---  End of File ---------------

