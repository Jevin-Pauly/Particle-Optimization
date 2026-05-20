//----------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------

#include "Car.h"
#include "Garage.h"

int main()
{
	// Do not change the main() function in any way
	Car A("Jetta");
	Car B("Accord");
	Car C("Forte");
	Car D("Outback");
	Car E("Escape");

	Garage G;

	G.AddToFront(&A);
	G.AddToFront(&B);
	G.AddToFront(&C);
	G.AddToFront(&D);
	G.AddToFront(&E);

	G.Print("Add to Front");

	G.Remove(&A);
	G.Remove(&C);
	G.Remove(&E);

	G.Print("Remove A,C,E");

	G.AddToEnd(&A);
	G.AddToEnd(&C);
	G.AddToEnd(&E);

	G.Print("Add to End");

	G.Remove(&A);
	G.Remove(&B);
	G.Remove(&C);
	G.Remove(&D);
	G.Remove(&E);

	G.Print("Remove A,B,C,D,E");
}

// ---  End of File ---
