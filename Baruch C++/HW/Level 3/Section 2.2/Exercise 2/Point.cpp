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

// default constractor
Point::Point()
{}

// destructor
Point::~Point()
{}

// member function
void Point::SetX(double set_x)
{
	m_x = set_x;
}

void Point::SetY(double set_y)
{
	m_y = set_y;
}

double Point::GetX()
{
	return m_x;
}

double Point::GetY()
{
	return m_y;
}

string Point::ToString()  // the type be converted to string
{
	stringstream s;
	s << "Point(" << m_x << ", " << m_y << ")";
	return s.str();
}

double Point::DistanceOrigin()  // distance between this point and (0, 0)
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(Point p)
{
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}