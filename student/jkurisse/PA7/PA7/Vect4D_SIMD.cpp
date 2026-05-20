//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect4D_SIMD.h"


Vect4D_SIMD::Vect4D_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}


float Vect4D_SIMD::Dot(const Vect4D_SIMD &B) const
{
	//Vect4D_SIMD C{};

	//C._m = _mm_mul_ps(this->_m, B._m);
	//C._m = _mm_hadd_ps(C._m, C._m);
	return _mm_cvtss_f32(_mm_dp_ps(this->_m, B._m, 0xFF));
}

Vect4D_SIMD Vect4D_SIMD::operator - (const Vect4D_SIMD &t) const
{
	Vect4D_SIMD C{};
	C._m = _mm_sub_ps(this->_m, t._m);

	return C;
}

Vect4D_SIMD Vect4D_SIMD::operator + (const Vect4D_SIMD &t) const
{
	Vect4D_SIMD C{}; 
	C._m = _mm_add_ps(this->_m, t._m); 

	return C;
}


// ---  End of File ----


