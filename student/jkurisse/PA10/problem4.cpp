//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
//
// NO HEADERS... do the problem in this CPP file
//
// Do Problem 4 here:
//
// ---------------------------------------------------------------------------

#include <math.h>

struct Vect  // Vector struct for positions
{
	float x;
	float y;
	float z;
}; 
 
/***********************************************************************
*
*  Function: findMaxDistance()
*
*  Input:
*          int       nPlayers - number of players
*          Vect   *playerArray - the array of players
*  Output:
*          float     maxDist - the maxDistance between any two players 
*
***********************************************************************/

float findMaxDistance( int nPlayers, Vect *playerArray )
{
	int i,j;          // counter variables
	Vect tmpVect;   // temporary vector
	float tmpDist;    // temporary distance
	float maxDist;    // current max distance

	// initialize the distance to zero
	maxDist = 0.0f;

	for( i = 0; i < nPlayers; i++ )
	{
		for( j = 0; j < nPlayers; j++ )
		{
			// Find a vector between point i and j
			tmpVect.x = playerArray[i].x - playerArray [j].x;
			tmpVect.y = playerArray[i].y - playerArray [j].y;
			tmpVect.z = playerArray[i].z - playerArray [j].z;

			// Get its length
			tmpDist = (float)sqrt( tmpVect.x * tmpVect.x 
				+ tmpVect.y * tmpVect.y 
				+ tmpVect.z * tmpVect.z );

			// determine if it’s a new maximum length
			if( tmpDist > maxDist)
			{
				// yes so keep it
				maxDist = tmpDist;
			}

		} //for(j)
	} // for(i)

	return maxDist;

} // End of findMaxDistance()

// End of File
