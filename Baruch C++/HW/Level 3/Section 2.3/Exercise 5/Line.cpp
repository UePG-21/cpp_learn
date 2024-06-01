/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/13/21
 */
#include <iostream>
#include "Line.hpp"
#include "Point.hpp"
#include <sstream>

using namespace std;

// constructor
Line::Line()
{
	Point start_point(0, 0);
	Point end_point(0, 0);
	cout << "A line has been created by default constructor." << endl;
}

Line::Line(const Point& a, const Point& b) : start_point(a), end_point(b)
{
	cout << "A line has been created by parameter constructor." << endl;
}

Line::Line(const Line& l)
{
	cout << "A line has been created by copy constructor." << endl;
}

Line::~Line()
{
	cout << "A line has been deleted by destructor." << endl;
}

// member function
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

void Line::P2(const Point& b)  // set end-point
{
	end_point = b;
}

string Line::ToString() const  // return a description of the line
{
	stringstream ss;
	ss << "Line is " << start_point.ToString() << " to " << end_point.ToString();
	return ss.str();
}

double Line::Length() const  // calculate the length
{
	return start_point.Distance(end_point);
}