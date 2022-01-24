/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/16/21
 */
#ifndef Point_hpp
#define Point_hpp

#include <iostream>

using namespace std;

class Point
{
private:
    double m_x;
    double m_y;

public:
    Point();  // default constructor
    Point(double new_x, double new_y);  // constructor
    Point(const Point& p);  // copy constructor
    // To prevent the usage of constructors are implicit conversion operators, add key words "explicit"
    explicit Point(double d);  // constructor with one argument
    ~Point();  // destructor

    // get and set
    const double& X() const;
    const double& Y() const;
    void X(double set_x);
    void Y(double set_y);
    string ToString() const;

    // calculate distance
    double Distance() const;
    double Distance(const Point& p) const;

    // operators overloading
    Point operator - () const;  // negate the coordinates
    Point operator * (double factor) const;  // scale the coordinates
    Point operator + (const Point& p) const;  // add the coordinates
    bool operator == (const Point& p) const;  // equally compare operator
    Point& operator = (const Point& p);  // assignment operator
    Point& operator *= (double factor);  // scale the corrdinates and assign
};

// "<<" overloading
ostream& operator << (ostream& cout, const Point& p);

#endif