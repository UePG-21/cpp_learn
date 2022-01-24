/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/16/21
 */
#define _USE_MATH_DEFINES

#include <iostream>
#include <sstream>
#include <cmath>
#include "Shape.hpp"
#include "Point.hpp"
#include "Circle.hpp"

using namespace std;

Circle::Circle() :Shape(), centre(0, 0), m_radius(1) {}  // default constructor

Circle::Circle(Point c, double r) :Shape(), centre(c), m_radius(r) {}  // constructor

Circle::Circle(Circle& c) :Shape(c), centre(c.centre), m_radius(c.m_radius) {}  // copy constructor

Circle::~Circle() {}  // destructor

const Point& Circle::CentrePoint() const
{
    return centre;
}

const double& Circle::Radius() const
{
    return m_radius;
}

void Circle::CentrePoint(Point a)
{
    centre = a;
}

void Circle::Radius(double r)
{
    m_radius = r;
}

double Circle::Diameter() const
{
    return 2 * m_radius;
}

double Circle::Area() const
{
    return M_PI * pow(m_radius, 2);
}

double Circle::Circumference() const
{
    return 2 * M_PI * m_radius;
}

string Circle::ToString() const
{
    std::string s = Shape::ToString();
    stringstream ss;
    ss << "circle (centre of " << centre.ToString() << " and radius of " << m_radius << ") with " << s;
	return ss.str();
}

Circle& Circle::operator = (const Circle& c)
{
    if (this == &c)  // preclude self-assignment
    {
        return *this;
    }
    Shape::operator=(c);
    centre = c.centre;
    m_radius = c.m_radius;

    cout << "Circle assignment has been called." << endl;

    return *this;
}

// "<<" overloading
ostream& operator << (ostream& cout, const Circle& c)
{
    cout << c.ToString();
    return cout;
}

void Circle::Draw() const
{
    cout << "Draw a circle (centre of " << centre.ToString() << ", radius of " << m_radius << ")" << endl;
}
