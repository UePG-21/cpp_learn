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
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

using namespace std;

int main()
{
    // Create objects
    Point a(1.0, 2.0);
    Point b(3.0, 4.0);
    Line l(a, b);
    Circle c(a, 5);

    // Print descriptions
    cout << "Point a is " << a << endl;
    cout << "Point b is " << b << endl;
    cout << "Line l is " << l << endl;
    cout << "Circle c is " << c << endl;

    return 0;
}