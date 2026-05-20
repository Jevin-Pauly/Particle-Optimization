//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef F_H
#define F_H

// MODIFY this file

// There should be two classes defined in this header
//     Generalized template class
//     Full class specification class 
//
// Generalized: Cut & Paste from E.h for the general class template
//     Then add a second full specialization class
//
// Write a full class specialization for float
//     in this class when you push() a float it pushes the data twice
//     in this class when you pop() it pops a singe element off the stack
//     top() and empty() behave the same.

#include <vector>

template <typename T>
class StackF
{
public:
	// Write the following functions

	// push element
	void push(T const &data);

	//void push(char const &data);


	// pop element
	void pop();

	// return top element
	T top() const;

	// return whether the stack is empty
	bool empty() const;

private:
	std::vector<T> elems;     // elements
};


template<typename T>
void StackF<T>::push(T const &data)
{
	elems.push_back(data);
}

template<typename T>
void StackF<T>::pop()
{
	elems.pop_back();
}

template<typename T>
T StackF<T>::top() const
{
	return elems[elems.size() - 1];
}

template<typename T>
bool StackF<T>::empty() const
{
	if (elems.size() != 0)
	{
		return false;
	}
	return true;
}

template <>
class StackF<float>
{
public:
	void push(float const &data);
	void pop();
	float top() const;
	bool empty() const;
private:
	std::vector<float> elems;     // elements
};

void StackF<float>::push(float const &data)
{
	elems.push_back(data);
	elems.push_back(data);
}

void StackF<float>::pop()
{
	elems.pop_back(); 
}

float StackF<float>::top() const
{
	return elems[elems.size() - 1];
}

bool StackF<float>::empty() const
{
	if (elems.size() != 0)
	{
		return false;
	}
	return true;
}
#endif

// ---  End of File ---------------
