//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "HotDog.h"

// -----------------------------------------------
// AZUL_REPLACE_ME_STUB
// this is place holder for compiling purposes
// Delete each AZUL_REPLACE_ME_STUB line
// Replace with your own code
// -----------------------------------------------

// Methods

HotDog::HotDog()
{
	this->condiments = static_cast<unsigned int>(Condiments::Plain);
	this->pNext = nullptr;
	this->pPrev = nullptr;
} 

HotDog::HotDog(const HotDog &copy)
{
	this->condiments = copy.condiments;
	this->pNext = nullptr;
	this->pPrev = nullptr;
}


HotDog &HotDog::operator = (const HotDog &copy)
{
	if (this != &copy)
	{
		this->condiments = copy.condiments;
	}
	return *this;
} 

HotDog::~HotDog()
{
	
} 

void HotDog::Minus(const Condiments condiment)
{
	// Only use bit-wise operations
	this->condiments = static_cast<unsigned int>(static_cast<uint8_t>(this->condiments) & ~(static_cast<uint8_t>(condiment)));
}

void HotDog::Add(const Condiments condiment)
{
	// Only use bit-wise operations
	this->condiments = static_cast<unsigned int>(static_cast<uint8_t>(this->condiments) | static_cast<uint8_t>(condiment));
}

// ---  End of File ---------------

