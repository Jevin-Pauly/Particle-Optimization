//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PROXY_H
#define PROXY_H

// Modify This File
struct Vadd1st;
struct Vadd2nd;
struct Vadd3rd;
struct Vadd4th;
struct Vadd5th;
struct Vadd6th;
struct Vadd7th;
struct Vadd8th;
struct Vadd9th;


class Vect2D
{
public:
	Vect2D(const Vect2D &tmp) = default;
	Vect2D &operator =( const Vect2D &tmp) = default;
	Vect2D() = default;
	~Vect2D() = default;

	Vect2D(const float inX, const float inY);

	void setX(const float inX);
	void setY(const float inY);
	void set(const float inX, const float inY);

	float getX() const;
	float getY() const;

	//-----------------------------------------------
	// Rules   this function cannot be inlined 
	//         or implemented directly
	//-----------------------------------------------
	//  Vect2D operator + (const Vect2D &tmp) const;
	//-----------------------------------------------


private:
	float x;
	float y;

	//-----------------------------------------------
	// Add friends here... if you want (hint)
	//-----------------------------------------------
	friend struct Vadd1st;
	friend struct Vadd2nd;
	friend struct Vadd3rd;
	friend struct Vadd4th;
	friend struct Vadd5th;
	friend struct Vadd6th;
	friend struct Vadd7th;
	friend struct Vadd8th;
	friend struct Vadd9th;

};

struct Vadd1st
{
	const Vect2D &v1;
	const Vect2D &v2;

	Vadd1st(const Vect2D &t1, const Vect2D &t2)
		: v1(t1), v2(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.x + v2.x, v1.y + v2.y);
	}
};

struct Vadd2nd
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;

	Vadd2nd(const Vadd1st &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D((v1.x + v2.x + v3.x), (v1.y + v2.y + v3.y));
	}
};

struct Vadd3rd
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;

	Vadd3rd(const Vadd2nd &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D((v1.x + v2.x + v3.x + v4.x), (v1.y + v2.y + v3.y + v4.y));
	}
};

struct Vadd4th
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;
	const Vect2D &v5;

	Vadd4th(const Vadd3rd &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D((v1.x + v2.x + v3.x + v4.x + v5.x), (v1.y + v2.y + v3.y + v4.y + v5.y));
	}
};

struct Vadd5th
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;
	const Vect2D &v5;
	const Vect2D &v6;

	Vadd5th(const Vadd4th &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t1.v5), v6(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D((v1.x + v2.x + v3.x + v4.x + v5.x + v6.x), (v1.y + v2.y + v3.y + v4.y + v5.y + v6.y));
	}
};

struct Vadd6th
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;
	const Vect2D &v5;
	const Vect2D &v6;
	const Vect2D &v7;

	Vadd6th(const Vadd5th &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t1.v5), v6(t1.v6), v7(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D((v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x), (v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y));
	}
};

struct Vadd7th
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;
	const Vect2D &v5;
	const Vect2D &v6;
	const Vect2D &v7;
	const Vect2D &v8;

	Vadd7th(const Vadd6th &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t1.v5), v6(t1.v6), v7(t1.v7), v8(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D((v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x + v8.x), (v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y + v8.y));
	}
};

struct Vadd8th
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;
	const Vect2D &v5;
	const Vect2D &v6;
	const Vect2D &v7;
	const Vect2D &v8;
	const Vect2D &v9;

	Vadd8th(const Vadd7th &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t1.v5), v6(t1.v6), v7(t1.v7), v8(t1.v8), v9(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D((v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x + v8.x + v9.x), (v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y + v8.y + v9.y));
	}
};

struct Vadd9th
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;
	const Vect2D &v5;
	const Vect2D &v6;
	const Vect2D &v7;
	const Vect2D &v8;
	const Vect2D &v9;
	const Vect2D &v10;

	Vadd9th(const Vadd8th &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t1.v5), v6(t1.v6), v7(t1.v7), v8(t1.v8), v9(t1.v9), v10(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D((v1.x + v2.x + v3.x + v4.x + v5.x + v6.x + v7.x + v8.x + v9.x + v10.x), (v1.y + v2.y + v3.y + v4.y + v5.y + v6.y + v7.y + v8.y + v9.y + v10.y));
	}
};
inline Vadd1st operator + (const Vect2D &t1, const Vect2D &t2) { return Vadd1st(t1, t2); };
inline Vadd2nd operator + (const Vadd1st &t1, const Vect2D &t2) { return Vadd2nd(t1, t2); };
inline Vadd3rd operator + (const Vadd2nd &t1, const Vect2D &t2) { return Vadd3rd(t1, t2); };
inline Vadd4th operator + (const Vadd3rd &t1, const Vect2D &t2) { return Vadd4th(t1, t2); };
inline Vadd5th operator + (const Vadd4th &t1, const Vect2D &t2) { return Vadd5th(t1, t2); };
inline Vadd6th operator + (const Vadd5th &t1, const Vect2D &t2) { return Vadd6th(t1, t2); };
inline Vadd7th operator + (const Vadd6th &t1, const Vect2D &t2) { return Vadd7th(t1, t2); };
inline Vadd8th operator + (const Vadd7th &t1, const Vect2D &t2) { return Vadd8th(t1, t2); };
inline Vadd9th operator + (const Vadd8th &t1, const Vect2D &t2) { return Vadd9th(t1, t2); };



#endif

// ---  End of File ---------------