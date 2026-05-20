//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef NYBLE_H
#define NYBLE_H

//----------------------------------------------------------------------------
// Feel free to add extra methods in the class
// You need to explicitly define and implement the Big four operators
// Do not add extra data in class
// Do not add code here (that goes in *.cpp)
//----------------------------------------------------------------------------


class Nyble
{
public:
	// insert your code here
	Nyble();
	Nyble(unsigned int x);
	Nyble(int x);
	Nyble(const Nyble& other);
	Nyble &operator=(const Nyble &nyble);
	~Nyble();

	//Binary
	Nyble operator+(const int data);									// Addition N + const
	friend Nyble operator+(const Nyble& nyble, unsigned char value);	//Add N + unsigned char
	friend Nyble operator+(int value, const Nyble& nyble);				//Add const + N
	friend Nyble operator+(Nyble& nyble1, Nyble& nyble2);				//Add N1 + N2
	Nyble operator+=(const Nyble &nyble);								// A += B

	operator unsigned int() const;

	//Unary
	Nyble operator~() const;											// Complement
	Nyble operator+() const;											// Addition
	Nyble operator-() const;											// Subtraction


	Nyble operator++();													// Increment pre
	Nyble operator++(int);												// Increment post

	//Shift
	Nyble operator<<(int left) const;

	unsigned char getData();

private:
        // Do not change this data
	unsigned char data;

};


//Nyble operator+(int x, const Nyble& nyble);

#endif

//---  End of File ---
