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

	G.Remove(&E);
	G.Print("Remove E (Escape)");

	G.Remove(&C);
	G.Print("Remove C (Forte)");

	G.Remove(&A);
	G.Print("Remove A (Jetta)");

	G.Remove(&B);
	G.Print("Remove B (Accord)");

	G.Remove(&D);
	G.Print("Remove D (Outback)");

	G.AddToEnd(&A);
	G.Print("Add to End A (Jetta)");

	G.AddToEnd(&B);
	G.Print("Add to End B (Accord)");

	G.AddToEnd(&C);
	G.Print("Add to End C (Forte)");

	G.AddToEnd(&D);
	G.Print("Add to End D (output)");

	G.Remove(&A);
	G.Remove(&B);
	G.Remove(&C);
	G.Remove(&D);

	G.Print("Remove A,B,C,D");
}

// ---  End of File ---
