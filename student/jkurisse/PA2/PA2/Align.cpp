//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "Align.h"

//-------------------------------------------------------------
// PrintME()
//
// Write your alignment printing function here
//-------------------------------------------------------------

Align::Info Align::PrintME(void *pData, int StructSize, char *pString)
{
	// Use Trace::out2(...) to display the data layout and padding

        // NOTE:   out2() NOT out()
        //         it won't be graded without out2()

	// Mimic the KeenanSampleOutput_Debug.txt

        // EXACtLY or the grading system will give a 0
	unsigned char* data = static_cast<unsigned char*>(pData);
	
	Info info;
	info.NumBytesOfPadding = 0;
	info.NumTotalBytes = StructSize;

	Trace::out2("%s:\n", pString);
	for (int i = 0; i < StructSize; i++)
	{
		//To print 0x00, 0x04...
		if (i % 4 == 0) 
		{
			Trace::out2("  0x%02X: ", i);
			//printf ("  0x%02X: ", i);
		}

		//To print 00 or AA
		Trace::out2("%02X ", data[i]);
		//printf ("%02X ", data[i]);

		if ((i + 1) % 4 == 0 && (i + 1) != StructSize) 
		{
			Trace::out2("\n");
		}

		//Add to padding if data[i] is padding
		if (data[i] != 00)
		{
			info.NumBytesOfPadding++;
		}
	}

	if (info.NumBytesOfPadding > 0) 
	{
		Trace::out2("\n");
		Trace::out2("------------------------\n");
		Trace::out2("size: %d padding: %d\n", StructSize, info.NumBytesOfPadding);
		Trace::out2("\n");
	}

	return info;
}

// ---  End of File ---

