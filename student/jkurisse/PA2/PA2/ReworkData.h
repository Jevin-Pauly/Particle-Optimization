//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef REWORK_DATA_H
#define REWORK_DATA_H

struct DataA
{
	double r;			//8 Bytes
	char a;
	char b;
	char pad0;
	char pad1;
	char pad2;
	char pad3;
	char pad4;
	char pad5;			//Total Size 16 Data A
};

struct DataB
{
	DataA da;			//16 Bytes	
	int i;				//4 Bytes
	char a;
	char b;
	char pad0;
	char pad1;			//Total Size 24 Data B
};

struct DataC
{
	int j;
	int i;
	char a;
	bool f;
	char pad0;
	char pad1;			//Total Size 12 Data C
};

struct DataD
{
	double r;
	int i;
	char a;
	char b;
	char pad0;
	char pad1;			//Total Size 16 Data D
};

struct DataE
{
	double r;			//8 Bytes
	char name[12];		//12 Bytes
	int x;				//4 Bytes
	int* p;				//4 Bytes
	char a;				//1 Byte
	char c;				//1 Byte		Total Size 32 Data E
	char pad0;
	char pad1;
};

struct Vect
{
	float vx;			//4 Bytes
	float vy;
	float vz;
	float vw;
	char a;
	char b;
	char pad0;
	char pad1;			//Total Size 20 Vect
};

struct DataF
{
	int i;
	int j;
	Vect v;				//Bytes 20
	char c;
	char b;
	char pad0;
	char pad1;			//Total Size 32 Data F
};	

struct DataG
{
	double d0;
	double d1;
	DataA a0;			//Bytes 16
	Vect  v;			//Bytes 20
	char  b0;
	char  c0;
	char pad0;
	char pad1;			//Total Size 52	Data G
};



#endif

// ---  End of File ---

