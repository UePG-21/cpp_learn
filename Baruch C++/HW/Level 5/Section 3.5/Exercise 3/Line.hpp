/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/16/21
 */
#ifndef Line_hpp
#define Line_hpp

#include <iostream>
#include "Shape.hpp"
#include "Point.hpp"

using namespace std;

class Line :public Shape
{
    friend ostream& operator << (ostream& cout, const Line& l);
    
private:
    Point start_point;
    Point end_point;

public:
    Line();  // default constructor
    Line(const Point& a, const Point& b);  // constructor
    Line(const Line& l);  // copy constructor
    virtual ~Line();  // destructor

    // get and set
    const Point& P1() const;  // get start-point
    const Point& P2() const;  // get end-point
    void P1(const Point& a);  // set start-point
    void P2(const Point& a);  // set end-point

    // other member functions
    virtual string ToString() const;  // print description
    double Length() const;  // calculate the length

    // operator overloading
    Line& operator = (const Line& l);  // assignment operator overloading
};

#endif