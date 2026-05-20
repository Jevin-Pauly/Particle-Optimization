//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"

#include "Donut.h"
#include "Hodor.h"

Donut *pA = nullptr;
Donut *pB = nullptr;
Donut *pC = nullptr;
Wylis *pWylis = nullptr;

TEST_WITH_TEARDOWN(MemoryLeak_Test_Enable, TestConfig::ALL)
{
#if MemoryLeak_Test_Enable

	// PLACE HOLDER - you don't get TESTS for your FINAL!
	CHECK(true);
	
#endif
} TEST_END


TEST_TEARDOWN(MemoryLeak_Test_Enable)
{

}


// ---  End of File ---

