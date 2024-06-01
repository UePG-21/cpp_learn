/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/20/21
 */
#ifndef Array_hpp
#define Array_hpp

#include <iostream>
#include "Point.hpp"

using namespace std;

class Array
{
private:
    int m_size;
    Point* m_data;

public:
    // constructor and destructor
    Array();  // default constructor
    Array(int size);  // constructor
    Array(const Array& a);  // copy constructor
    ~Array();  // destructor

    Array& operator = (const Array& a);  // assignment operator overloading

    // functions
    const int Size() const;  // return the size of the array
    Point& GetElement(int index) const;  // get an element
    void SetElement(int index, const Point& p);  // set an element

    // operator overloading
    Point& operator [] (int index);  // square bracket operator overloading
    const Point& operator [] (int index) const;  // make sure that this function is also available for const parameter
};

#endif
