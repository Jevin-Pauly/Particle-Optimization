//----------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------

#include "Car.h"
#include "Garage.h"

int main()
{
	// Do not change the main() function in any way
	Car *pA = new Car("A");
	Car *pB = new Car("B");
	Car *pC = new Car("C");

	Garage *pG0 = new Garage();

	pG0->AddToEnd(pA);
	pG0->AddToEnd(pB);
	pG0->AddToEnd(pC);

	pG0->Print("pG0");

	// Deep Copy
	Garage *pG1 = new Garage(*pG0);

	// addresses should all be different
	// pG0 != pG1
	// pG0: car A  != pG1: car A
	// pG0: car B  != pG1: car B
	// pG0: car C  != pG1: car C
	pG1->Print("pG1");

	Car *pD = new Car("D");
	Car *pE = new Car("E");
	Car *pF = new Car("F");

	Garage *pG2 = new Garage();
	pG2->AddToEnd(pD);
	pG2->AddToEnd(pE);
	pG2->AddToEnd(pF);

	pG2->Print("pG2");

	// Deep assignment
	*pG0 = *pG2;

	// pG0 != pG2
	// pG0: car D  != pG2: car D
	// pG0: car E  != pG2: car E
	// pG0: car F  != pG2: car F
	pG0->Print("*pG0 = *pG1");

	delete pG2;
	delete pG1;
	delete pG0;
}

// ---  End of File ---
