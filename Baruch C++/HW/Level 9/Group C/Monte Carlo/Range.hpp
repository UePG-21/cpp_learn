/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/08/21
 */
#ifndef Range_hpp
#define Range_hpp

#include <vector>

template <class Type>
class Range
{

private:
	Type lo;
	Type hi;

public:
	// Constructors
	Range();									// Default constructor
	Range(const Type& low, const Type& high);	// Low and high value
	Range(const Range<Type>& ran2);				// Copy constructor

	// Destructor
	virtual ~Range();

	// Modifier functions
	void low(const Type& t1);					// Sets the low value of current range
	void high(const Type& t1);					// Sets the high value of current range

	//Accessing functions
	Type low() const;							// Lowest value in range
	Type high() const;							// Highest value in the range

	Type spread() const;						// High - Low value

	// Boolean functions
	bool left(const Type& value) const;			// Is the value to the left of the range?
	bool right(const Type& value) const;		// Is the value to the right of the range?
	bool contains(const Type& value) const;		// Does range contain value?

	// Utility functions
	std::vector<Type> mesh(long nSteps) const;	// Create a discrete mesh

	// Operator overloading
	Range<Type>& operator = (const Range<Type>& ran2);
};

#ifndef Range_cpp
#include "Range.cpp"
#endif

#endif
