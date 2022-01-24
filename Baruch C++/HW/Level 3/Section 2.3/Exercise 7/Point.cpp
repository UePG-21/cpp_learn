/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/14/21
 */
#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.hpp"

using namespace std;

// constractor and destructor
Point::Point()
{
	cout << "A point has been created by default constructor." << endl;
}

Point::Point(double new_x, double new_y) : m_x(new_x), m_y(new_y)
{
	cout << "A point has been created by parameter constructor." << endl;
}

Point::Point(const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	cout << "A point has been created by copy constructor." << endl;
}

Point::~Point()
{
	cout << "A point has been deleted by destructor." << endl;
}

// member function
string Point::ToString() const  // the type be converted to string
{
	stringstream s;
	s << "Point(" << m_x << ", " << m_y << ")";
	return s.str();
}

double Point::Distance() const  // distance between this point and (0, 0)
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(const Point& p) const  // distance between this point and point p
{
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}