/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/13/21
 */
#ifndef Point_hpp
#define Point_hpp

#include <iostream>
using namespace std;

// Construct a class
class Point
{
public:
	Point();  // default constructor
	Point(double new_x, double new_y);  // parameter constructor
	Point(const Point& p);  // copy constructor
	~Point();  // destructor

	void SetX(double set_x);
	void SetY(double set_y);
	double GetX();
	double GetY();
	string ToString();

	// Calculate the distance
	double DistanceOrigin();
	double Distance(Point p);

private:
	double m_x;
	double m_y;
};

#endif