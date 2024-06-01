/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/21/21
 */
#ifndef NumericArray_cpp
#define NumericArray_cpp

#include <iostream>
#include "Array.hpp"
#include "NumericArray.hpp"
#include "ArrayException.hpp"

using namespace std;

template <typename T>
NumericArray<T>::NumericArray() :Array<T>() {}  // default constructor

template <typename T>
NumericArray<T>::NumericArray(int size) :Array<T>(size) {}  // constructor

template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source) :Array<T>(source) {}  // copy constructor

template <typename T>
NumericArray<T>::~NumericArray() {}  // destructor

template <typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)  // assignment operator overloading
{
	if (this == &source)  // preclude self-assignment
	{
		return *this;
	}

	Array<T>::operator = (source);
	return *this;
}

template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& source) const  // + overloading
{
	if (this->Size() != source.Size())
    {
        throw NotSameSizeException();
    }

	NumericArray<T> sum(this->Size());
	for (int i = 0; i < this->Size(); i++)
	{
		sum[i] = (*this)[i] + source[i];
	}

	return sum;
}

template <typename T>
NumericArray<T> NumericArray<T>::operator*(T factor) const  // * overloading
{
	NumericArray<T> tmp(this->Size());
	for (int i = 0; i < this->Size(); i++)
	{
		tmp[i] = (*this)[i] * factor;
	}
	return tmp;
}

template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& source) const  // dot multiply
{
	if (this->Size() != source.Size())
	{
		throw NotSameSizeException();
	}

	T sum = 0;
	for (int i = 0; i < this->Size(); i++)
	{
		sum += (*this)[i] * source[i];
	}
	return sum;
}


#endif
