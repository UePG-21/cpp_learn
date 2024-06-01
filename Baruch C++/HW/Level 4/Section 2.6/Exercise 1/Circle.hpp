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
#include "Point.hpp"

using namespace std;

namespace HanlinWANG
{
    namespace CAD
    {
        class Circle
        {
        private:
            Point centre;
            double m_radius;
            
        public:
            Circle();  // default constructor
            Circle(Point c, double r);  // constructor
            Circle(const Circle& c);  // copy constructor
            ~Circle();  // destructor

            // get and set
            const Point& CentrePoint() const;
            const double& Radius() const;
            void CentrePoint(Point a);
            void Radius(double r);

            // function
            double Diameter() const;
            double Area() const;
            double Circumference() const;
            string ToString() const;

            // assignment operator
            Circle& operator = (const Circle& c);
        };

        // "<<" overloading
        ostream& operator << (ostream& cout, const Circle& c);
    }
}

#endif