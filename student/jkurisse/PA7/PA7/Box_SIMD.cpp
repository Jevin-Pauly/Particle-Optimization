//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Box_SIMD.h"


Box_SIMD::ColResult Box_SIMD::Collide(const Sphere_SIMD &sphere)
{
	ColResult result = Box_SIMD::ColResult::Inside;

	Vect4D_SIMD A{};
	Vect4D_SIMD temp{};

	//A = sphere.Center - this->NearBottomLeftPoint;
	A._m = _mm_sub_ps(sphere.Center._m, this->NearBottomLeftPoint._m);

	//A.Dot(this->BottomNorm)
	/*temp._m = _mm_mul_ps(A._m, this->BottomNorm._m);
	temp._m = _mm_hadd_ps(temp._m, temp._m);
	float checkBNorm = _mm_cvtss_f32(_mm_hadd_ps(temp._m, temp._m));*/

	float checkBNorm = _mm_cvtss_f32(_mm_dp_ps(A._m, this->BottomNorm._m, 0xFF));

	//A.Dot(this->LeftNorm)
	/*temp._m = _mm_mul_ps(A._m, this->LeftNorm._m);
	temp._m = _mm_hadd_ps(temp._m, temp._m); 
	float checkLNorm = _mm_cvtss_f32(_mm_hadd_ps(temp._m, temp._m));*/

	float checkLNorm = _mm_cvtss_f32(_mm_dp_ps(A._m, this->LeftNorm._m, 0xFF));

	//A.Dot(this->FrontNorm)
	/*temp._m = _mm_mul_ps(A._m, this->FrontNorm._m);
	temp._m = _mm_hadd_ps(temp._m, temp._m);
	float checkFNorm = _mm_cvtss_f32(_mm_hadd_ps(temp._m, temp._m));*/

	float checkFNorm = _mm_cvtss_f32(_mm_dp_ps(A._m, this->FrontNorm._m, 0xFF));

	if ((checkBNorm > sphere.Radius) || (checkLNorm > sphere.Radius) || (checkFNorm > sphere.Radius))
	{
		result = Box_SIMD::ColResult::Outside;
	}

	else
	{
		//Vect4D_SIMD B{};

		//Vect4D B = sphere.Center - this->FarTopRightPoint;
		A._m = _mm_sub_ps(sphere.Center._m, this->FarTopRightPoint._m);

		//B.Dot(this->BackNorm)
		/*temp._m = _mm_mul_ps(A._m, this->BackNorm._m);
		temp._m = _mm_hadd_ps(temp._m, temp._m);
		checkBNorm = _mm_cvtss_f32(_mm_hadd_ps(temp._m, temp._m));*/
		checkBNorm = _mm_cvtss_f32(_mm_dp_ps(A._m, this->BackNorm._m, 0xFF));

		//B.Dot(this->RightNorm)
		/*temp._m = _mm_mul_ps(A._m, this->RightNorm._m);
		temp._m = _mm_hadd_ps(temp._m, temp._m);
		checkLNorm = _mm_cvtss_f32(_mm_hadd_ps(temp._m, temp._m));*/

		checkLNorm = _mm_cvtss_f32(_mm_dp_ps(A._m, this->RightNorm._m, 0xFF));

		//B.Dot(this->TopNorm)
		/*temp._m = _mm_mul_ps(A._m, this->TopNorm._m);
		temp._m = _mm_hadd_ps(temp._m, temp._m);
		checkFNorm = _mm_cvtss_f32(_mm_hadd_ps(temp._m, temp._m));*/

		checkFNorm = _mm_cvtss_f32(_mm_dp_ps(A._m, this->TopNorm._m, 0xFF));


		if ((checkBNorm > sphere.Radius) || (checkLNorm > sphere.Radius) || (checkFNorm > sphere.Radius))
		{
			result = Box_SIMD::ColResult::Outside;
		}
	}

	return result;
}


// --- End of File ---
