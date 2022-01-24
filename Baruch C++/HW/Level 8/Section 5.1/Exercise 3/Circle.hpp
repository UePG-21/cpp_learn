/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/16/21
 */
#ifndef Circle_hpp
#define Circle_hpp

#include <iostream>
#include "Shape.hpp"
#include "Point.hpp"

using namespace std;

class Circle : public Shape
{
private:
    Point centre;
    double m_radius;

public:
    Circle();  // default constructor
    Circle(const Point c, const double r);  // constructor
    Circle(const Circle& c);  // copy constructor
    virtual ~Circle();  // destructor

    // get and set
    const Point& CentrePoint() const;
    const double& Radius() const;
    void CentrePoint(Point a);
    void Radius(double r);

    // function
    double Diameter() const;
    double Area() const;
    double Circumference() const;
    virtual string ToString() const;

    // assignment operator
    Circle& operator = (const Circle& c);

    // draw function
    virtual void Draw() const;
};

// "<<" overloading
ostream& operator << (ostream& cout, const Circle& c);

#endif
