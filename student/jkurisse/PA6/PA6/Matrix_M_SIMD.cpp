//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"

Matrix_M_SIMD::Matrix_M_SIMD(const Vect_M_SIMD &tV0,
							 const Vect_M_SIMD &tV1,
							 const Vect_M_SIMD &tV2,
							 const Vect_M_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Matrix_M_SIMD Matrix_M_SIMD::operator * (const Matrix_M_SIMD &mb) const
{
	Matrix_M_SIMD A{};
	
	//Multiplying first row of mb with x (first element of first row of this), 
	//then second row of mb with y (second element of first row of this),
	//then third row of mb with z (third element of first row of this),
	//then fourth row of mb with w (fourth element of first row of this),
	//add all the rows up to get A's first row
	//repeat for the rest

	/*A.v0._m = _mm_mul_ps(_mm_set1_ps(this->v0.x), mb.v0._m); 
	A.v0._m = _mm_add_ps(A.v0._m, _mm_mul_ps(_mm_set1_ps(this->v0.y), mb.v1._m)); 
	A.v0._m = _mm_add_ps(A.v0._m, _mm_mul_ps(_mm_set1_ps(this->v0.z), mb.v2._m)); 
	A.v0._m = _mm_add_ps(A.v0._m, _mm_mul_ps(_mm_set1_ps(this->v0.w), mb.v3._m)); */

	A.v0._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->v0.x), mb.v0._m), _mm_mul_ps(_mm_set1_ps(this->v0.y), mb.v1._m)), _mm_mul_ps(_mm_set1_ps(this->v0.z), mb.v2._m)), _mm_mul_ps(_mm_set1_ps(this->v0.w), mb.v3._m));

	/*A.v1._m = _mm_mul_ps(_mm_set1_ps(this->v1.x), mb.v0._m);
	A.v1._m = _mm_add_ps(A.v1._m, _mm_mul_ps(_mm_set1_ps(this->v1.y), mb.v1._m));
	A.v1._m = _mm_add_ps(A.v1._m, _mm_mul_ps(_mm_set1_ps(this->v1.z), mb.v2._m));
	A.v1._m = _mm_add_ps(A.v1._m, _mm_mul_ps(_mm_set1_ps(this->v1.w), mb.v3._m));*/

	A.v1._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->v1.x), mb.v0._m), _mm_mul_ps(_mm_set1_ps(this->v1.y), mb.v1._m)), _mm_mul_ps(_mm_set1_ps(this->v1.z), mb.v2._m)), _mm_mul_ps(_mm_set1_ps(this->v1.w), mb.v3._m));

	/*A.v2._m = _mm_mul_ps(_mm_set1_ps(this->v2.x), mb.v0._m);
	A.v2._m = _mm_add_ps(A.v2._m, _mm_mul_ps(_mm_set1_ps(this->v2.y), mb.v1._m));
	A.v2._m = _mm_add_ps(A.v2._m, _mm_mul_ps(_mm_set1_ps(this->v2.z), mb.v2._m));
	A.v2._m = _mm_add_ps(A.v2._m, _mm_mul_ps(_mm_set1_ps(this->v2.w), mb.v3._m));*/

	A.v2._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->v2.x), mb.v0._m), _mm_mul_ps(_mm_set1_ps(this->v2.y), mb.v1._m)), _mm_mul_ps(_mm_set1_ps(this->v2.z), mb.v2._m)), _mm_mul_ps(_mm_set1_ps(this->v2.w), mb.v3._m));

	/*A.v3._m = _mm_mul_ps(_mm_set1_ps(this->v3.x), mb.v0._m);
	A.v3._m = _mm_add_ps(A.v3._m, _mm_mul_ps(_mm_set1_ps(this->v3.y), mb.v1._m));
	A.v3._m = _mm_add_ps(A.v3._m, _mm_mul_ps(_mm_set1_ps(this->v3.z), mb.v2._m));
	A.v3._m = _mm_add_ps(A.v3._m, _mm_mul_ps(_mm_set1_ps(this->v3.w), mb.v3._m));*/

	A.v3._m = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_set1_ps(this->v3.x), mb.v0._m), _mm_mul_ps(_mm_set1_ps(this->v3.y), mb.v1._m)), _mm_mul_ps(_mm_set1_ps(this->v3.z), mb.v2._m)), _mm_mul_ps(_mm_set1_ps(this->v3.w), mb.v3._m));


	return A;
}


// ---  End of File ---------------
