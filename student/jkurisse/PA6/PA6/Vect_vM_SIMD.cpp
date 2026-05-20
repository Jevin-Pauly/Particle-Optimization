//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_vM_SIMD.h"
#include "Matrix_vM_SIMD.h"

Vect_vM_SIMD::Vect_vM_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

//------------------------------
// For No proxy:
//------------------------------

Vect_vM_SIMD Vect_vM_SIMD::operator * (const Matrix_vM_SIMD &ma) const
{
	Vect_vM_SIMD C {};

	//Multiply x vector to all of firt row of matrix
	//Multiply y, z, w vector to all of 2nd, 3rd and 4th row respectively
	//Add all the rows up to get new Vector
	C._m = _mm_mul_ps(_mm_set1_ps(this->x), ma.v0._m);
	C._m = _mm_add_ps(C._m, _mm_mul_ps(_mm_set1_ps(this->y), ma.v1._m));
	C._m = _mm_add_ps(C._m, _mm_mul_ps(_mm_set1_ps(this->z), ma.v2._m));
	C._m = _mm_add_ps(C._m, _mm_mul_ps(_mm_set1_ps(this->w), ma.v3._m));

	return C;
};


// ---  End of File ---------------


