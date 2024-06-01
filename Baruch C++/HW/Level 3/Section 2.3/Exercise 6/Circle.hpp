#ifndef Circle_hpp
#define Circle_hpp

#include <iostream>
#include "Point.hpp"

using namespace std;

class Circle
{
public:
	Circle();  // default constructor
	Circle(Point c, double r);  // parameter constructor
	Circle(const Circle& c);  // copy constructor
	~Circle();  // destructor

	// get and set
	const Point& CentrePoint() const;
	const double& Radius() const;
	void CentrePoint(Point a);
	void Radius(double r);

	// calculation
	double Diameter() const;
	double Area() const;
	double Circumference() const;
	string ToString() const;

private:
	Point m_centre;
	double m_radius;
};

#endif