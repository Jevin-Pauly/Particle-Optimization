//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"

Matrix_Col_SIMD::Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
	const Vect_Col_SIMD &tV1,
	const Vect_Col_SIMD &tV2,
	const Vect_Col_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}


M5V::operator Vect_Col_SIMD()
{
	/*Vect_Col_SIMD r1{};
	Vect_Col_SIMD r2{};
	Vect_Col_SIMD r3{};
	Vect_Col_SIMD r4{};*/
	Vect_Col_SIMD final{};

	final._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(v._m, this->m5.v0._m), _mm_mul_ps(v._m, this->m5.v1._m)),					_mm_hadd_ps(_mm_mul_ps(v._m, this->m5.v2._m), _mm_mul_ps(v._m, this->m5.v3._m)));

	final._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(final._m, this->m4.v0._m), _mm_mul_ps(final._m, this->m4.v1._m)),			_mm_hadd_ps(_mm_mul_ps(final._m, this->m4.v2._m), _mm_mul_ps(final._m, this->m4.v3._m)));

	final._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(final._m, this->m3.v0._m), _mm_mul_ps(final._m, this->m3.v1._m)),			_mm_hadd_ps(_mm_mul_ps(final._m, this->m3.v2._m), _mm_mul_ps(final._m, this->m3.v3._m)));
	 
	final._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(final._m, this->m2.v0._m), _mm_mul_ps(final._m, this->m2.v1._m)),			_mm_hadd_ps(_mm_mul_ps(final._m, this->m2.v2._m), _mm_mul_ps(final._m, this->m2.v3._m)));

	final._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(final._m, this->m1.v0._m), _mm_mul_ps(final._m, this->m1.v1._m)),			_mm_hadd_ps(_mm_mul_ps(final._m, this->m1.v2._m), _mm_mul_ps(final._m, this->m1.v3._m)));

	return final;
}


// ---  End of File ---------------
