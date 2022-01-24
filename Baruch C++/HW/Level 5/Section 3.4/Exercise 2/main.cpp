/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/19/21
 */
#include <iostream>
#include <sstream>
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace std;

int main()
{
    Shape s;  // Create shape
    Point p(10, 20);  // Create point
    Line l(Point(1, 2), Point(3, 4));  // Create line

    cout << s.ToString() << endl;  // Print shape
    cout << p.ToString() << endl;  // Print point
    cout << l.ToString() << endl;  // Print line

    cout << "Shape ID: " << s.ID() << endl;  // ID of the shape.
    cout << "Point ID: " << p.ID() << endl;  // ID of the point. It works.
    cout << "Line ID: " << l.ID() << endl;  // ID of the line. It works.

    Shape* sp;  // Create pointer to a shape variable.
    sp = &p;  // Point in a shape variable. Possible?
    cout << sp->ToString() << endl;  // The ID of point p

    // Create and copy Point p to new point.
    Point p2;
    p2 = p;
    cout << p2 << ", " << p2.ID() << endl;  // The ID will not be copied if you do not call the base class assignment is not called

    return 0;
}