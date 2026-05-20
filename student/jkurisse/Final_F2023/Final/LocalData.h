//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef LOCAL_DATA_H
#define LOCAL_DATA_H

#include <vector>

struct LocalData
{
	LocalData() = default;
	LocalData(const LocalData &) = default;
	LocalData &operator = (const LocalData &) = default;
	~LocalData() = default;

	// Add methods here:
	LocalData(const std::vector<int> &values);
	float GetAverage() const;
	std::vector<int> GetSortedValues() const;

	// ------------------------------------------
	// Data:  (do not add or modify the data)
	// ------------------------------------------
	std::vector<int> vect;

};

#endif

// ---  End of File ---
