/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/22/21
 */
#ifndef PointArray_hpp
#define PointArray_hpp

#include "Array.hpp"

using namespace std;

class PointArray : public Array<Point>
{
public:
    PointArray();  // default constructor
    PointArray(int size);  // constructor
    PointArray(const PointArray& source);  // copy constructor
    virtual ~PointArray();  // destructor

    PointArray& operator = (const PointArray& source);  // assignment operator overloading

    double Length() const;  // length function
};

#endif
