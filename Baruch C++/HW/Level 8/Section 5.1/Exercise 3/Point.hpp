/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/20/21
 */

#ifndef Point_hpp
#define Point_hpp

#include <iostream>
#include "Shape.hpp"

using namespace std;

class Point : public Shape
{
    friend ostream& operator << (ostream& cout, const Point& p);

private:
    double m_x;
    double m_y;

public:
    Point();  // default constructor
    Point(double new_x, double new_y);  // constructor
    Point(const Point& p);  // copy constructor
    virtual ~Point();  // destructor

    Point& operator = (const Point& p);  // assignment operator

    // get and set
    const double& X() const;
    const double& Y() const;
    void X(double set_x);
    void Y(double set_y);
    virtual string ToString() const;

    // calculate distance
    double Distance() const;
    double Distance(const Point& p) const;

    // operators overloading
    Point operator - () const;  // negate the coordinates
    Point operator * (double factor) const;  // scale the coordinates
    Point operator + (const Point& p) const;  // add the coordinates
    bool operator == (const Point& p) const;  // equally compare operator
    Point& operator *= (double factor);  // scale the corrdinates and assign

    virtual void Draw() const;
};

#endif
