/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/17/21
 */
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"

using namespace std;

int main()
{
    // The full namespace for Point class.
    HanlinWANG::CAD::Point a = HanlinWANG::CAD::Point(1.0, 2.0);
    HanlinWANG::CAD::Point b = HanlinWANG::CAD::Point(3.0, 4.0);
    cout << "a is " << a << ", b is " << b << endl;

    // Using declaration for using a single class (Line).
    using HanlinWANG::CAD::Line;
    Line l = Line(a, b);
    cout << "l is " << l << endl;

    // Using declaration for a complete namespace (Containers).
    using namespace HanlinWANG::Containers;
    Array arr = Array(5);
    cout << "The size of arr is " << arr.Size() << endl;

    // Create a shorter alias for the HanlinWANG::CAD namespace.
    namespace HLWCAD = HanlinWANG::CAD;
    HLWCAD::Circle c = HLWCAD::Circle(a, 5.0);
    cout << "c is " << c << endl;

    return 0;
}