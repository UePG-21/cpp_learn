/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/14/21
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

	void X(double set_x) { m_x = set_x; };
	void Y(double set_y) { m_y = set_y; };
	const double& X() const;
	const double& Y() const;
	string ToString() const;

	// Calculate the distance
	double Distance() const;
	double Distance(const Point& p) const;

private:
	double m_x;
	double m_y;
};

// normal inline for the getters
inline const double& Point::X() const
{
	return m_x;
}

inline const double& Point::Y() const
{
	return m_y;
}

#endif