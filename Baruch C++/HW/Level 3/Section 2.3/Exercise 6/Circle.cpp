#define _USE_MATH_DEFINES

#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.hpp"
#include "Circle.hpp"

using namespace std;

// constructor and destructor
Circle::Circle()
{
	cout << "A circle has been created by default constructor." << endl;
}

Circle::Circle(Point c, double r) : m_centre(c), m_radius(r)
{
	cout << "A circle has been created by parameter constructor." << endl;
}

Circle::Circle(const Circle& c)
{
	m_centre = c.m_centre;
	m_radius = c.m_radius;
	cout << "A circle has been created by copy constructor." << endl;
}

Circle::~Circle()
{
	cout << "A circle has been deleted by destructor." << endl;
}

// get and set
const Point& Circle::CentrePoint() const
{
	return m_centre;
}

const double& Circle::Radius() const
{
	return m_radius;
}

void Circle::CentrePoint(Point a)
{
	m_centre = a;
}

void Circle::Radius(double r)
{
	m_radius = r;
}

// calculation
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
	return 2 * m_radius * M_PI;
}

string Circle::ToString() const
{
	stringstream ss;
	ss << "The centre of the circle is " << m_centre.ToString() << ", the radius is " << m_radius;
	return ss.str();
}