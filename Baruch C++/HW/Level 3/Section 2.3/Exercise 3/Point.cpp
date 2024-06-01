/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/13/21
 */
#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.hpp"

using namespace std;

// constractor
Point::Point()
{
	cout << "An object has been created by default constructor." << endl;
}

Point::Point(double new_x, double new_y) : m_x(new_x), m_y(new_y)
{
	cout << "An object has been created by parameter constructor." << endl;
}

Point::Point(const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	cout << "An object has been created by copy constructor." << endl;
}

// destructor
Point::~Point()
{
	cout << "An object has been deleted by destructor." << endl;
}

// member function
void Point::X(double set_x)
{
	m_x = set_x;
}

void Point::Y(double set_y)
{
	m_y = set_y;
}

double Point::X()
{
	return m_x;
}

double Point::Y()
{
	return m_y;
}

string Point::ToString()  // the type be converted to string
{
	stringstream s;
	s << "Point(" << m_x << ", " << m_y << ")";
	return s.str();
}

double Point::Distance()  // distance between this point and (0, 0)
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(const Point& p)  // distance between this point and point p
{
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}