/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/16/21
 */
#include <iostream>
#include <sstream>
#include "Point.hpp"
#include "Point.hpp"
#include "Line.hpp"

using namespace std;

Line::Line() :Shape(), start_point(0, 0), end_point(0, 0)  // default constructor
{
    cout << "A line has been created by default constructor." << endl;
}

Line::Line(const Point& a, const Point& b) :Shape(), start_point(a), end_point(b)  // constructor
{
    cout << "A line has been created by constructor." << endl;
}

Line::Line(const Line& l) :Shape(l), start_point(l.start_point), end_point(l.end_point)  // copy constructor
{
    cout << "A line has been created by copy constructor." << endl;
}

Line::~Line()  // destructor
{
    cout << "A line has been deleted." << endl;
}

const Point& Line::P1() const  // get start-point
{
    return start_point;
}

const Point& Line::P2() const  // get end-point
{
    return end_point;
}

void Line::P1(const Point& a)  // set start-point
{
    start_point = a;
}

void Line::P2(const Point& a)  // set end-point
{
    end_point = a;
}

string Line::ToString() const  // print description
{
    stringstream ss;
    ss << "line from " << start_point.ToString() << " to " << end_point.ToString();
    return ss.str();
}

double Line::Length() const  // calculate the length
{
    return start_point.Distance(end_point);
}

Line& Line::operator = (const Line& l)  // assignment operator overloading
{
    if (this == &l)  // preclude self-assignment
    {
        return *this;
    }
    Shape::operator=(l);
    start_point = l.start_point;
    end_point = l.end_point;

    cout << "Line assignment has been called." << endl;

    return *this;
}

// "<<" overloading
ostream& operator << (ostream& cout, const Line& l)
{
    cout << "line from " << l.start_point << " to " << l.end_point;
    return cout;
}