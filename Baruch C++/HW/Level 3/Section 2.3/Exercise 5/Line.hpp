/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/13/21
 */
#ifndef Line_hpp
#define Line_hpp

#include <iostream>
#include "Point.hpp"

using namespace std;

class Line
{
public:
	Line();  // default constructor
	Line(const Point& a, const Point& b);  // parameter constructor
	Line(const Line& l);  // copy constructor
	~Line();  // destructor

	const Point& P1() const;  // get start-point
	const Point& P2() const;  // get end-point
	void P1(const Point& a);  // set start-point
	void P2(const Point& b);  // set end-point

	string ToString() const;  // return a description of the line
	
	double Length() const;  // calculate the length

private:
	Point start_point;
	Point end_point;
};

#endif