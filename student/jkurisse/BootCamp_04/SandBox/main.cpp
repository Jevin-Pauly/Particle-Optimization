//----------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------

#include "Card.h"
#include "Deck.h"

int main()
{
	// Do not change the main() function in any way
	Card A("A",11);
	Card B("B",55);
	Card C("C",33);
	Card D("D",77);
	Card E("E",99);
	Card F("F",44);

	Deck deck;

	deck.AddToEnd(&A);
	deck.AddToEnd(&B);
	deck.AddToEnd(&C);
	deck.AddToEnd(&D);
	deck.AddToEnd(&E);
	deck.AddToEnd(&F);

	deck.Print("Add to last (A,B,C,D,E,F)");

	deck.Sort();

	deck.Print("sorted lowest to highest");

	deck.Remove(&A);
	deck.Remove(&B);
	deck.Remove(&C);
	deck.Remove(&D);
	deck.Remove(&E);
	deck.Remove(&F);

	deck.Print("remove A,B,C,D,E,F");


	deck.AddToFront(&A);
	deck.AddToFront(&B);
	deck.AddToFront(&C);
	deck.AddToFront(&D);
	deck.AddToFront(&E);
	deck.AddToFront(&F);

	deck.Print("Add to last (A,B,C,D,E,F)");

	deck.Sort();

	deck.Print("sorted lowest to highest");

	deck.Remove(&A);
	deck.Remove(&B);
	deck.Remove(&C);
	deck.Remove(&D);
	deck.Remove(&E);
	deck.Remove(&F);

	deck.Print("remove A,B,C,D,E,F");

}

// ---  End of File ---
