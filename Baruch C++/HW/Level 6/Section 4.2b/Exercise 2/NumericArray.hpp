/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/21/21
 */
#ifndef NumericArray_hpp
#define NumericArray_hpp

#include <iostream>
#include "Array.hpp"
#include "NumericArray.hpp"
#include "ArrayException.hpp"

using namespace std;

template <typename T>
class NumericArray :public Array<T>
{
public:
    NumericArray();  // default constructor
    NumericArray(int size);  // constructor with a size argument
    NumericArray(const NumericArray<T>& source);  // copy constructor
    virtual ~NumericArray();  // destructor

    NumericArray<T>& operator = (const NumericArray<T>& source);  // assignment operator overloading
    NumericArray<T> operator + (const NumericArray<T>& source) const;  // + overloading
    NumericArray<T> operator * (T factor) const;  // * overloading
    T DotProduct(const NumericArray<T>& source) const;  // dot multiply
};

#ifndef NumericArray_cpp
#include "NumericArray.cpp"
#endif

#endif
