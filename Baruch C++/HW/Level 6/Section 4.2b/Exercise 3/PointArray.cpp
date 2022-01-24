/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/22/21
 */
#ifndef PointArray_cpp
#define PointArray_cpp

#include "Point.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"
#include "PointArray.hpp"

PointArray::PointArray() : Array<Point>() {}  // default constructor

PointArray::PointArray(int size) : Array<Point>(size) {}  // constructor

PointArray::PointArray(const PointArray &source) : Array<Point>(source) {}  // copy constructor

PointArray::~PointArray() {}  // destructor

PointArray& PointArray::operator = (const PointArray& source)  // assignment operator overloading
{
    if (this == &source)
    {
        return *this;
    }

    Array<Point>::operator = (source);
    return *this;
}

double PointArray::Length() const  // length function
{
    double len = 0;
    for (int i = 0; i < (*this).Size() - 1; i++)
    {
        double s = 0;
        s = (*this)[i].Distance((*this)[i + 1]);
        len += s;
    }

    return len;
}

#endif
