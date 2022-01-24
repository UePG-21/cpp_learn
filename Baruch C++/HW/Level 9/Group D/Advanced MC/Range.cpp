/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/11/21
 */
#ifndef Range_cpp
#define Range_cpp

#include "Range.hpp"
#include <vector>

// Constructors
template <class Type>
Range<Type>::Range()
{ // Default constructor.
	Type def(0); // Need this
	lo = def;
	hi = def;
}

template <class Type>
Range<Type>::Range(const Type& l, const Type& h)
{ //
	if (l < h)
	{
		lo = l;
		hi = h;
	}

	else
	{
		hi = l;
		lo = h;
	}
}

template <class Type>
Range<Type>::Range(const Range<Type>& r2)
{ // Copy constructor

	lo = r2.lo;
	hi = r2.hi;
}

template <class Type>
Range<Type>::~Range()
{ // Destructor

}

template <class Type>
void Range<Type>::low(const Type& t1)
{// The low value of the range will be set with the value t1
	lo = t1;
}

template <class Type>
void Range<Type>::high(const Type& t1)
{// The high value of the range will be set with the value t
	hi = t1;
}

template <class Type>
Type Range<Type>::low() const
{// Returns the lower bound of the range

	return lo;
}

template <class Type>
Type Range<Type>::high() const
{// Returns the higher bound of the range

	return hi;
}

template <class Type>
Type Range<Type>::spread() const
{// Returns the higher bound of the range

	return hi - lo;
}

template <class Type>
bool Range<Type>::left(const Type& val) const
{ // Check if current value is to the left of the range

	if (val < lo)
		return true;

	return false;
}

template <class Type>
bool Range<Type>::right(const Type& val) const
{ // Check if current value is to the right of the range
	if (val > hi)
		return true;

	return false;
}

template <class Type>
bool Range<Type>::contains(const Type& t) const
{// Does range contain t
	if ((lo <= t) && (hi >= t))
		return true;

	return false;
}

// Operator overloading
template <class Type>
Range<Type>& Range<Type>::operator = (const Range<Type>& r2)
{ // Assignment operator
	hi = r2.hi;
	lo = r2.lo;

	return *this;
}

// Utility functions
template <class Type>
std::vector<Type> Range<Type>::mesh(long nSteps) const
{ // Create a discrete mesh

	Type h = (hi - lo) / Type(nSteps);

	std::vector<Type> result(nSteps + 1);

	Type val = lo;

	for (long i = 0; i < nSteps + 1; i++)
	{
		result[i] = val;
		val += h;
	}

	return result;
}

#endif
