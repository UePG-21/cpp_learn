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
	Point();  // constructor
	~Point();  // destructor

	void SetX(double set_x);
	void SetY(double set_y);
	double GetX();
	double GetY();
	string ToString();

private:
	double m_x;
	double m_y;
};

#endif