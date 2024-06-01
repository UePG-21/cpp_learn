/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/16/21
 */
#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.hpp"
#include "Circle.hpp"

using namespace std;

namespace HanlinWANG
{
    namespace CAD
    {
        Circle::Circle()  // default constructor
        {
            cout << "A circle has been created by default constructor." << endl;
        }

        Circle::Circle(Point c, double r) : centre(c), m_radius(r)  // constructor
        {
            cout << "A circle has been created by constructor." << endl;
        }

        Circle::Circle(const Circle& c)  // copy constructor
        {
            centre = c.centre;
            m_radius = c.m_radius;
            cout << "A circle has been created by copy constructor." << endl;
        }

        Circle::~Circle()  // destructor
        {
            cout << "A circle has been deleted." << endl;
        }

        const Point& Circle::CentrePoint() const
        {
            return centre;
        }

        const double& Circle::Radius() const
        {
            return m_radius;
        }

        void Circle::CentrePoint(Point a)
        {
            centre = a;
        }

        void Circle::Radius(double r)
        {
            m_radius = r;
        }

        double Circle::Diameter() const
        {
            return 2 * m_radius;
        }

        double Circle::Area() const
        {
            return M_PI * pow(m_radius, 2);
        }

        double Circle::Circumference() const
        {
            return 2 * M_PI * m_radius;
        }

        string Circle::ToString() const
        {
            stringstream ss;
            ss << "circle with centre of " << centre.ToString() << " and radius of " << m_radius;
            return ss.str();
        }

        Circle& Circle::operator = (const Circle& c)
        {
            if (this == &c)  // preclude self-assignment
            {
                return *this;
            }
            centre = c.centre;
            m_radius = c.m_radius;
            return *this;
        }

        // "<<" overloading
        ostream& operator << (ostream& cout, const Circle& c)
        {
            cout << c.ToString();
            return cout;
        }
    }
}