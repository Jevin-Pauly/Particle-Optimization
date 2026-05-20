//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "answerRegistry.h"

#define QuestionAnswer(x,y)  Answer::registerAnswer(1,x,(unsigned int)y)

struct Cat
{
	Cat()
	:c0( 0xC9 ), c1(0xCA), c2(0xCB)
	{}

	unsigned char c0;
	unsigned char c1;
	unsigned char c2;
};

struct Dog
{
	Dog()
	: d0(0xDDAA), d1(0xDDBB), d2(0xDDCC)
	{}

	unsigned short d0;
	unsigned short d1;
	unsigned short d2;
};

struct Bird
{
	Bird()
	: b0(0xBB000111), b1(0xBB000222), b2(0xBB000333)
	{}

	unsigned int b0;
	unsigned int b1;
	unsigned int b2;
};

struct petStore
{
	Cat		morris;
	char	pad0;
	Dog		fido;
	char    pad1;
	char    pad2;
	Bird	poly;
};


void Students_Casting()
{
	petStore		ps;
	unsigned int	*r;
	unsigned short	*s;
	unsigned char	*p;

	p = &ps.morris.c0;
	r = &ps.poly.b0;
	s = &ps.fido.d0;

	// HERE's the rules
	// Only ps - the petStore is instantiated
	//
	// Everything is stubbed out... just fill in the questions
	// Add code to find the answer programmatically  (by writing code)

	//      question 0) what is the value of morris.c1?
	
	// example-- no work inside the Answer only Value variable
	int val;
	val = p[1];
	QuestionAnswer( 0, val );

	//      question 1)  What is the value of r[0]
	//      question 2)  What is the value of r[1]
	//      question 3)  What is the value of r[2]

	unsigned int valui; 
	valui = r[0]; 
	QuestionAnswer( 1, valui);

	valui = r[1];
	QuestionAnswer( 2, valui);

	valui = r[2];
	QuestionAnswer( 3, valui); 

	//      question 4)  What is the value of s[0]
	//      question 5)  What is the value of s[1]
	//      question 6)  What is the value of s[2]

	unsigned short valus;
	valus = s[0];
	QuestionAnswer( 4, valus);

	val = s[1];
	QuestionAnswer( 5, valus);

	val = s[2];
	QuestionAnswer( 6, valus);

	//      question 7)  What is the value of  p[0]
	//      question 8)  What is the value of  p[1]
	//      question 9)  What is the value of  p[2]
	
	val = p[0]; 
	QuestionAnswer( 7, val); 

	val = p[1];
	QuestionAnswer( 8, val); 

	val = p[2];
	QuestionAnswer( 9, val); 

// For the next set of questions (11-19)
//
// You can cast and create temp variables to help you answer questions correctly.
// 	   No need to ever loop... use casting
//   p <- the starting address of ps
//   s <- the starting address of ps
//   r <- the starting address of ps

	p = (unsigned char *)&ps;
	s = (unsigned short *)&ps;
	r = (unsigned int *)&ps;

	//      question 10)  addr of ps
	QuestionAnswer(10, p);

	//      question 11)  number of unsigned chars to d0
	//      question 12)  number of unsigned chars to c1
	//      question 13)  number of unsigned chars to b2

	int charsize = sizeof(unsigned char);
	QuestionAnswer(11, ((unsigned int)(&ps.fido.d0) - (unsigned int)(&ps.morris.c0)) / charsize);
	QuestionAnswer(12, ((unsigned int)(&ps.morris.c1) - (unsigned int)(&ps.morris.c0)) / charsize); 
	QuestionAnswer(13, ((unsigned int)(&ps.poly.b2) - (unsigned int)(&ps.morris.c0)) / charsize);

	//      question 14)  number of unsigned shorts to the first d2
	//      question 15)  number of unsigned shorts to the first c2
	//      question 16)  number of unsigned shorts to the first b1;

	int shortsize = sizeof(unsigned short);
	QuestionAnswer(14, ((unsigned int)(&ps.fido.d2) - (unsigned int)(&ps.morris.c0)) / shortsize); 
	QuestionAnswer(15, ((unsigned int)(&ps.morris.c2) - (unsigned int)(&ps.morris.c0)) / shortsize);
	QuestionAnswer(16, ((unsigned int)(&ps.poly.b1) - (unsigned int)(&ps.morris.c0)) / shortsize);

	//      question 17)  number of unsigned ints to the first d0
	//      question 18)  number of unsigned ints to the first c0
	//      question 19)  number of unsigned ints to the first b0;

	int intsize = sizeof(unsigned int);
	QuestionAnswer(17, ((unsigned int)(&ps.fido.d0) - (unsigned int)(&ps.morris.c0)) / intsize);
	QuestionAnswer(18, ((unsigned int)(&ps.morris.c0) - (unsigned int)(&ps.morris.c0)) / intsize); 
	QuestionAnswer(19, ((unsigned int)(&ps.poly.b0) - (unsigned int)(&ps.morris.c0)) / intsize); 

}

// --- End of File ---

