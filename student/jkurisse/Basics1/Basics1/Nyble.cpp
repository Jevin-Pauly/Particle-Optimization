//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Nyble.h"

//Main 4
Nyble::Nyble()
{
	this->data = 0;
}

Nyble& Nyble::operator=(const Nyble& nyble)
{
	if (this != &nyble)
	{
		this->data = nyble.data;
	}
	return *this;
}

Nyble::Nyble(unsigned int x)
{
	x = x & 0x0F;
	this->data = static_cast<unsigned char>(x);
	//this->data &= 0xF0;
	//static_cast<unsigned char>(this->data);
}

Nyble::Nyble(int x)
{
	x = x & 0x0F;
	this->data = static_cast<unsigned char>(x);
	//this->data &= 0xF0;
	//static_cast<unsigned char>(this->data);
}

Nyble::Nyble(const Nyble& other)
{
	this->data = other.data;
}

Nyble::~Nyble()
{
}



//Binary
Nyble Nyble::operator+(const int x)															//Add N + const
{	
	Nyble total;
	total.data = static_cast<unsigned char>((this->data + x) & 0x0F);
	return total.data;
}

Nyble operator+(const Nyble& nyble, unsigned char value) {									//Add N + unsigned char
	Nyble result;
	result.data = static_cast<unsigned char>((nyble.data + value) & 0x0F);
	return result;
}

Nyble operator+(int value, const Nyble& nyble) {											//Add const + N
	Nyble result;
	result.data = static_cast<unsigned char>((nyble.data + value) & 0x0F);
	return result;
}

Nyble operator+(Nyble& nyble1, Nyble& nyble2)												//Add N1 + N2
{
	Nyble result;
	result.data = static_cast<unsigned char>((nyble1.data + nyble2.data) & 0x0F);
	return result;
}

Nyble Nyble::operator+=(const Nyble &nyble)													//Add A(this) += B((nyble)
{
	this->data = static_cast<unsigned char>((this->data + nyble.data) & 0x0F);
	return *this;
}


Nyble::operator unsigned int() const {
	return static_cast<unsigned int>(data) - 3;
}



//Unary
Nyble Nyble:: operator+() const
{
	Nyble result;
	result.data = static_cast<unsigned char>((this->data + 3) & 0x0F);
	return result;
}

Nyble Nyble:: operator-() const
{
	Nyble result;
	result.data = static_cast<unsigned char>((this->data - 3) & 0x0F);
	return result;
}

Nyble Nyble:: operator~() const
{	
	Nyble result;
	result.data = static_cast<unsigned char>(~this->data & 0x0F);
	return result;
}


//Increment
Nyble Nyble:: operator++()
{
	//Nyble result;
	//result.data = static_cast<unsigned char>((this->data++) & 0x0F);
	this->data = static_cast<unsigned char>((this->data + 1) & 0x0F);
	return *this;
}

Nyble Nyble::operator++(int)
{
	Nyble prev(*this);
	//this->data = static_cast<unsigned char>(++this->data);
	++(*this);
	return prev;
}

//Shift
Nyble Nyble::operator<<(int left) const
{
	Nyble shifted;
	shifted.data = static_cast<unsigned char>((this->data << left) | (this->data >> (4 - left)));
	shifted.data = static_cast<unsigned char>(shifted.data & 0x0F);
	return shifted;
}




unsigned char Nyble::getData()
{
	return this->data;
}


//---  End of File ---
