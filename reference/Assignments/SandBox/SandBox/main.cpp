//----------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------

#include "A.h"

// -------------------------------------------------------------------
// Here is a quick demo... 
//
// 1) To start Visual Studio and launch this project
//   Double click the solution file  SandBox.sln
//
// 2) When you close Visual Studio
//   Run the CleanMe.bat to remove all the temporary files
//
// Environment:
//    A) Open the Solution Explorer:  <View> <Solution Explorer>
//       Double click on main.cpp  (its an IDE...you'll figure it out)
//    B) Open the Output window: <View> <Output>
//       Show you how to print to the output window
//
// Output Window 
//    defaults printing too many things
//    <Right click in output window>
//          disable Exception Messages
//          disable Step Filtering Messages
//          disable Module Load Messages
//          disable Module Unload Messages
//          disable Process Exit Messages
//          disable Thread Exit Messages
//     ENABLE Program Output (Messages)
//
// Confused or don't understand the code... PIAZZA my friend
//   Ask there, read a book, look online
//   You need to learn and explore... no more spoon feeding (tm)
//
// Enjoy - Ed
// -------------------------------------------------------------------

int main()
{
	Trace::out("Hello World\n");

	Trace::out("Trace::out() information:\n");
	Trace::out("    This is formatted string in the output window \n");
	Trace::out("    Same format as printf() --- look it up \n");
	Trace::out("\n");

	Trace::out("Formatted output\n");
	float x = 56.5f;
	int a = 1235;
	Trace::out("    int data: %d, float data: %f \n", a, x);
	Trace::out("\n");

	Trace::out("Default constructor: Jane\n");
	A Jane;
	Trace::out("\n");

	Trace::out("Default constructor: Nancy\n");
	A Nancy;
	Trace::out("\n");

	Trace::out("Assignment operator:  Nancy = Jane\n");
	Nancy = Jane;
	Trace::out("\n");

	Trace::out("Declared on the heap\n");
	A *pA = new A();  // <---  If you call _new_ ... you need a corresponding _delete_ otherwise leak
	Trace::out("    pA(%p)->ao: %d \n", pA, pA->a0);
	delete pA;   // <--- here is the delete.
	// try commenting out the delete line... the leak will be found

	Trace::out("\n");
	Trace::out("See prints as the main() ends...\n");
	Trace::out("   These are the destructors:\n");
	Trace::out("\n");
}

// ---  End of File ---
