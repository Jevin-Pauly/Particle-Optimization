//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Monkey.h"

int Monkey::numStringsCreated = 0;
int Monkey::numStringsDestroyed = 0;

Monkey::Monkey()
{
	x = 878;
	y = 979;
	pStatus = new char[strlen("This string was initialized by a default constructor!")+1];
	size_t strl = strlen("This string was initialized by a default constructor!") + 1;
	memcpy(pStatus, "This string was initialized by a default constructor!", strl);
	numStringsCreated++;
}
Monkey& Monkey::operator=(const Monkey &monkey)
{
	if (this != &monkey)
	{
		delete pStatus;
		numStringsDestroyed++;
		x = monkey.x;
		y = monkey.y;
		pStatus = new char[strlen(monkey.pStatus) + 1];
		size_t strl = strlen(monkey.pStatus) + 1;
		memcpy(pStatus, monkey.pStatus, strl);
		numStringsCreated++;
	}
	return *this;
}

Monkey::Monkey(const Monkey &monkey)
{
	x = monkey.x;
	y = monkey.y;
	pStatus = new char[strlen(monkey.pStatus)+1];
	size_t strl = strlen(monkey.pStatus) + 1;
	memcpy(pStatus, monkey.pStatus, strl);
	numStringsCreated++;
}

Monkey::~Monkey()
{
	delete pStatus;
	numStringsDestroyed++;
}

Monkey::Monkey(int xx, int yy)
{
	x = xx;
	y = yy;
	pStatus = new char[strlen("ThIs tring was initilizxd by a clever user!")+1];
	size_t strl = strlen("ThIs tring was initilizxd by a clever user!") + 1;
	memcpy(pStatus, "ThIs tring was initilizxd by a clever user!", strl);
	numStringsCreated++;
}

Monkey::Monkey(int xx)
{
	x = xx;
	y = 575;
	pStatus = new char[strlen("ThIs tring was initilizxd by a clever user!")+1];
	size_t strl = strlen("ThIs tring was initilizxd by a clever user!") + 1;
	memcpy(pStatus, "ThIs tring was initilizxd by a clever user!", strl);
	numStringsCreated++;
}

int Monkey::getX()
{
	return this->x;
}

int Monkey::getY()
{
	return this->y;
}

char *Monkey::getStatus()
{
	return this->pStatus;
};

void Monkey::printStatus()
{
	Trace::out("Monkey (Status): %s\n", this->pStatus);
}


//---  End of File ---
