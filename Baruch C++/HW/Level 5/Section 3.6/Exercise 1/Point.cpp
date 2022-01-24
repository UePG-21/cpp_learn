/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/20/21
 */

#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.hpp"

using namespace std;

Point::Point() :m_x(0.0), m_y(0.0)  // default constructor
{
    // cout << "A point has been created by default constructor." << endl;
}

Point::Point(double new_x, double new_y) : m_x(new_x), m_y(new_y)  // constructor
{
    // cout << "A point has been created by constructor." << endl;
}

Point::Point(const Point& p)  // copy constructor
{
    m_x = p.m_x;
    m_y = p.m_y;
    // cout << "A point has been created by copy constructor." << endl;
}

Point::~Point()  // destructor
{
    // cout << "A point has been deleted." << endl;
}

Point& Point::operator = (const Point& p)  // assignment operator
{
    if (this == &p)  // preclude self-assignment
    {
        return *this;
    }
    m_x = p.m_x;
    m_y = p.m_y;
    return *this;
}

const double& Point::X() const
{
    return m_x;
}

const double& Point::Y() const
{
    return m_y;
}

void Point::X(double set_x)
{
    m_x = set_x;
}

void Point::Y(double set_y)
{
    m_y = set_y;
}

string Point::ToString() const
{
    stringstream ss;
    ss << "point(" << m_x << ", " << m_y << ")";
    return ss.str();
}

double Point::Distance() const
{
    return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(const Point& p) const
{
    return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}

Point Point::operator - () const  // negate the coordinates
{
    return Point(-m_x, -m_y);
}

Point Point::operator * (double factor) const  // scale the coordinates
{
    return Point(m_x * factor, m_y * factor);
}

Point Point::operator + (const Point& p) const  // add the coordinates
{
    return Point(m_x + p.m_x, m_y + p.m_y);
}

bool Point::operator == (const Point& p) const  // equally compare operator
{
    return m_x == p.m_x && m_y == p.m_y;
}

Point& Point::operator *= (double factor)  // scale the corrdinates and assign
{
    m_x *= factor;
    m_y *= factor;
    return *this;
}

// "<<" overloading
ostream& operator << (ostream& cout, const Point& p)
{
    cout << "point(" << p.m_x << ", " << p.m_y << ")";
    return cout;
}
