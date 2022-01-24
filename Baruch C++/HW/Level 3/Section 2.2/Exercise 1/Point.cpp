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
#include "Point.hpp"

using namespace std;

// default constructor
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