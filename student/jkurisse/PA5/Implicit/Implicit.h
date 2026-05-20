//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------------------- 

#ifndef IMPLICIT_H
#define IMPLICIT_H

// ------------------------------------------------------------------------
//   Modify This File - to generate Errors to prevent implicit conversions
// ------------------------------------------------------------------------

class Vect
{
public:
	Vect();
	Vect(const Vect &tmp);
	const Vect & operator = (const Vect &tmp);
	~Vect();

	Vect(const float inX, const float inY, const float inZ);

	void setX(const float inX);
	void setY(const float inY);
	void setZ(const float inZ);

	void set(const float inX, const float inY, const float inZ);

	float getX() const;
	float getY() const;
	float getZ() const;

	Vect operator + (const Vect tmp) const;


private:
	

	template<typename X>void setX(X);
	template<typename Y>void setY(Y);
	template<typename Z>void setZ(Z);
	template <typename X, typename Y, typename Z>void set(X, Y, Z);
	template <typename X, typename Y, typename Z>Vect(X, Y, Z);


	float x;
	float y;
	float z;

};

#endif

// ---  End of File ---------------
