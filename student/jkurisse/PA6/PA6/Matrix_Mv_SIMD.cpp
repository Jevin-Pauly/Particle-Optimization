//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Mv_SIMD.h"
#include "Matrix_Mv_SIMD.h"

Matrix_Mv_SIMD::Matrix_Mv_SIMD(const Vect_Mv_SIMD &tV0,
							   const Vect_Mv_SIMD &tV1,
							   const Vect_Mv_SIMD &tV2,
							   const Vect_Mv_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Vect_Mv_SIMD Matrix_Mv_SIMD::operator * (const Vect_Mv_SIMD &v) const
{
	Vect_Mv_SIMD C{};
	//Vect_Mv_SIMD D{};
	//Multiply firt row of matrix to vect, 2nd row of matrix to vect
	//Horizontal add them
	//Repeat for 3rd and 4th row (+ Horizontal add)
	//Final Horizontal add to conjoin the 1st ,2nd, 3rd and 4th result

	//C._m = _mm_mul_ps(v._m, this->v0._m);
	//C._m = _mm_hadd_ps(C._m, _mm_mul_ps(v._m, this->v1._m));
	//C._m = _mm_hadd_ps(C._m, C._m);

	//D._m = _mm_mul_ps(v._m, this->v2._m);
	//D._m = _mm_hadd_ps(D._m, _mm_mul_ps(v._m, this->v3._m));
	//D._m = _mm_hadd_ps(D._m, D._m);

	//C._m = _mm_hadd_ps(C._m, D._m);
	C._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(v._m, this->v0._m), _mm_mul_ps(v._m, this->v1._m)), _mm_hadd_ps(_mm_mul_ps(v._m, this->v2._m), _mm_mul_ps(v._m, this->v3._m)));

	/*C.z = D.x;
	C.w = D.y;*/

	return C;
}


// ---  End of File ---------------
