//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef MATRIX_H
#define MATRIX_H

// includes
#include "Enum.h"

// forward declare
class Vect4D;

// class
class Matrix
{
public:

	// local enumerations
	enum class MatrixRow
	{
		MATRIX_ROW_0,
		MATRIX_ROW_1,
		MATRIX_ROW_2,
		MATRIX_ROW_3
	};

	Matrix() = default;
	Matrix(const Matrix &) = default;	
	Matrix &operator = (const Matrix &) = default;
	~Matrix() = default;

	void set( MatrixRow row, Vect4D *t );
	void get( MatrixRow row, Vect4D *vOut );

	

	void setIdentMatrix();
	void setTransMatrix(Vect4D *t );
	void setScaleMatrix(float *s );
	void setRotZMatrix( float Z_Radians );

	float &operator[]( Index e);
	
	Matrix operator*( Matrix &t );
	Matrix operator*( float s );

	float Determinant();
	
	Matrix GetAdjugate();
	Matrix& operator/=(float t);
	
	void Inverse( Matrix &out );
	
public:
	// ROW 0
	float m0;
	float m1;
	float m2;
	float m3;

	// ROW 1
	float m4;
	float m5;
	float m6;
	float m7;

	// ROW 2
	float m8;
	float m9;
	float m10;
	float m11;

	// ROW 3
	float m12;
	float m13;
	float m14;
	float m15;
};

#endif  

// --- End of File ---
