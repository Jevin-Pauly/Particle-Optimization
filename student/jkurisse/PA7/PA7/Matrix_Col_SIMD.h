//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Matrix_Col_SIMD_H
#define Matrix_Col_SIMD_H

#include "Vect_Col_SIMD.h"

// -----------------------------------------------------------------------
// Rules: 
//    Implement for Col Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline MM operator * (const Matrix_Col_SIMD &m, const Matrix_Col_SIMD &n)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

struct M1M;
struct M2M; 
struct M3M; 
struct M4M; 
struct M5V;

class Matrix_Col_SIMD
{
public:
	Matrix_Col_SIMD() = default;
	Matrix_Col_SIMD(const Matrix_Col_SIMD &tmp) = default;
	Matrix_Col_SIMD &operator=(const Matrix_Col_SIMD &tmp) = default;
	~Matrix_Col_SIMD() = default;

	Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
		const Vect_Col_SIMD &tV1,
		const Vect_Col_SIMD &tV2,
		const Vect_Col_SIMD &tV3);

	//Matrix_Col_SIMD operator * (const Matrix_Col_SIMD &n);
	//Vect_Col_SIMD operator * (const Vect_Col_SIMD &n);

	union
	{
		struct
		{
			Vect_Col_SIMD v0;
			Vect_Col_SIMD v1;
			Vect_Col_SIMD v2;
			Vect_Col_SIMD v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
private:
	friend struct M1M;
	friend struct M2M;
	friend struct M3M;
	friend struct M4M;
	friend struct M5V;
};

/////////////////////////////////////////////////////////////////

struct M1M
{
	const Matrix_Col_SIMD &m1;
	const Matrix_Col_SIMD &m2;

	M1M(const Matrix_Col_SIMD &t1, const Matrix_Col_SIMD &t2)
		: m1(t1), m2(t2)
	{
	};

	//operator Matrix_Col_SIMD();
};

struct M2M
{
	const Matrix_Col_SIMD &m1;
	const Matrix_Col_SIMD &m2;
	const Matrix_Col_SIMD &m3;

	M2M(const M1M &t1, const Matrix_Col_SIMD &t2)
		: m1(t1.m1), m2(t1.m2), m3(t2)
	{
	};

	//operator Matrix_Col_SIMD();
};

struct M3M
{
	const Matrix_Col_SIMD &m1;
	const Matrix_Col_SIMD &m2;
	const Matrix_Col_SIMD &m3;
	const Matrix_Col_SIMD &m4;

	M3M(const M2M &t1, const Matrix_Col_SIMD &t2)
		: m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t2)
	{
	};

	//operator Matrix_Col_SIMD();
};

struct M4M
{
	const Matrix_Col_SIMD &m1;
	const Matrix_Col_SIMD &m2;
	const Matrix_Col_SIMD &m3;
	const Matrix_Col_SIMD &m4;
	const Matrix_Col_SIMD &m5;

	M4M(const M3M &t1, const Matrix_Col_SIMD &t2)
		: m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t2)
	{
	};

	//operator Matrix_Col_SIMD();
};

struct M5V
{
	const Matrix_Col_SIMD &m1;
	const Matrix_Col_SIMD &m2;
	const Matrix_Col_SIMD &m3;
	const Matrix_Col_SIMD &m4;
	const Matrix_Col_SIMD &m5;
	const Vect_Col_SIMD &v;

	M5V(const M4M &t1, const Vect_Col_SIMD &t2)
		: m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t1.m5), v(t2)
	{
	};

	operator Vect_Col_SIMD();
};

inline M1M operator * (const Matrix_Col_SIMD &t1, const Matrix_Col_SIMD &t2) { return M1M(t1, t2); };
inline M2M operator * (const M1M &t1, const Matrix_Col_SIMD &t2)			 { return M2M(t1, t2); };
inline M3M operator * (const M2M &t1, const Matrix_Col_SIMD &t2)			 { return M3M(t1, t2); };
inline M4M operator * (const M3M &t1, const Matrix_Col_SIMD &t2)			 { return M4M(t1, t2); };
inline M5V operator * (const M4M &t1, const Vect_Col_SIMD &t2)				 { return M5V(t1, t2); };


#endif

// ---  End of File ---------------
