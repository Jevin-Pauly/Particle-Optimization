//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Row_SIMD.h"
#include "Matrix_Row_SIMD.h"

Vect_Row_SIMD::Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}


Vect_Row_SIMD Vect_Row_SIMD::operator*(const Matrix_Row_SIMD &ma)
{
	Vect_Row_SIMD C{};

	Vect_Row_SIMD X{};
	Vect_Row_SIMD Y{};

	C._m = _mm_mul_ps(_mm_set1_ps(this->x), ma.v0._m);
	X._m = _mm_mul_ps(_mm_set1_ps(this->y), ma.v1._m);
	C._m = _mm_add_ps(C._m, X._m);

	Y._m = _mm_mul_ps(_mm_set1_ps(this->z), ma.v2._m);
	X._m = _mm_mul_ps(_mm_set1_ps(this->w), ma.v3._m);
	Y._m = _mm_add_ps(Y._m, X._m);

	C._m = _mm_add_ps(C._m, Y._m);


	return C;
}

// ---  End of File ---------------
