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
    Point a(1.0, 2.0);
    Point b(3.0, 4.0);
    Line l(a, b);
    Circle c(a, 5.0);

    Shape* p;

    p = &a;
    cout << p->ToString() << endl;
    p = &l;
    cout << p->ToString() << endl;
    p = &c;
    cout << p->ToString() << endl;

    return 0;
}