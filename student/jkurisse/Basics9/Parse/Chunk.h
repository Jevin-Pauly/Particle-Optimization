//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef CHUNK_H
#define CHUNK_H

enum ChunkType
{
	VERTS_TYPE,
	NORMS_TYPE,
	ANIM_TYPE,
	TEXTURE_TYPE,
	UV_TYPE
};

// Add functions protos
int TypeCheck(char *type);
int NameCheck(char *name);

#endif 

// ---  End of File ---------------
