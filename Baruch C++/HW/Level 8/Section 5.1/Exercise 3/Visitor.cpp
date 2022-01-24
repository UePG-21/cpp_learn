/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/28/21
 */
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"

Visitor::Visitor() {}  // default constructor

Visitor::Visitor(double x, double y) : m_dx(x), m_dy(y) {}  // constructor

Visitor::Visitor(const Visitor& source) : m_dx(source.m_dx), m_dy(source.m_dy) {}  // copy constructor

Visitor::~Visitor() {}  // destructor

void Visitor::operator () (Point& p) const  // shift a point
{
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);
}

void Visitor::operator () (Line& l) const  // shift a line
{
    Point a = l.P1();
    a.X(a.X() + m_dx);
    a.Y(a.Y() + m_dy);
    l.P1(a);

    Point b = l.P1();
    b.X(b.X() + m_dx);
    b.Y(b.Y() + m_dy);
    l.P1(b);
}

void Visitor::operator () (Circle& c) const  // shift a circle
{
    Point a = c.CentrePoint();
    a.X(a.X() + m_dx);
    a.Y(a.Y() + m_dy);
    c.CentrePoint(a);
}

