/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/28/21
 */
#ifndef Visitor_hpp
#define Visitor_hpp

#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace std;

class Visitor : public boost::static_visitor<void>
{
private:
    double m_dx;
    double m_dy;

public:
    Visitor();  // default constructor
    Visitor(double x, double y);  // constructor
    Visitor(const Visitor& source);  // copy constructor
    ~Visitor();  // destructor

    // operator overloading
    void operator () (Point& p) const;  // shift a point
    void operator () (Line& l) const;  // shift a line
    void operator () (Circle& c) const;  // shift a circle
};

#endif
