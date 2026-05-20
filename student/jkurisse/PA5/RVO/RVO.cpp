//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "RVO.h"

// Modify This File

Vect2D::Vect2D()
	: x(3.0f), y(4.0f)
{
};

Vect2D::Vect2D(const float inX, const float inY)
	:x(inX), y(inY)
{
};


void Vect2D::setX(const float inX)
{
	this->x = inX;
};

void Vect2D::setY(const float inY)
{
	this->y = inY;
};

void Vect2D::set(const float inX, const float inY)
{
	this->x = inX;
	this->y = inY;
};

float Vect2D::getX() const
{
	return this->x;
};

float Vect2D::getY() const
{
	return this->y;
};


Vect2D Vect2D::operator + (const Vect2D &tmp) const
{
	/*Vect2D sum;
	sum.x = this->x + tmp.x;
	sum.y = this->y + tmp.y;
	return sum;*/

	return Vect2D(x + tmp.x, y + tmp.y);
};

Vect2D Vect2D::operator - (const Vect2D &tmp) const
{
	/*Vect2D sum;
	sum.x = this->x - tmp.x;
	sum.y = this->y - tmp.y;
	return sum;*/

	return Vect2D(x - tmp.x, y - tmp.y);
};

Vect2D Vect2D::operator * (const float scale) const
{
	/*Vect2D tmp;
	tmp.x = this->x * scale;
	tmp.y = this->y * scale;
	return tmp;*/

	return Vect2D(x * scale, y * scale);
};

// Assume scale != 0.0f
Vect2D Vect2D::operator / (const float scale) const
{
	/*Vect2D tmp;
	tmp.x = this->x / scale;
	tmp.y = this->y / scale;
	return tmp;*/

	return Vect2D(x / scale, y / scale);
};

// ---  End of File ---------------
