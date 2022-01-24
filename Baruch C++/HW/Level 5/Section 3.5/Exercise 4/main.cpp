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
    Shape* shapes[10];
    shapes[0] = new Line;
    shapes[1] = new Point;
    shapes[2] = new Point(1.0, 2.0);
    shapes[3] = new Point(2.0, 3.0);
    shapes[4] = new Point(3.0, 4.0);
    shapes[5] = new Point(4.0, 5.0);
    shapes[6] = new Point(5.0, 6.0);
    shapes[7] = new Point(6.0, 7.0);
    shapes[8] = new Circle(Point(7.0, 8.0), 9.0);
    shapes[9] = new Line(Point(3.1, 4.2), Point(8.5, 7.5));
    
    for (int i = 0; i != 10; i++) shapes[i]->Draw();
    for (int i = 0; i != 10; i++) delete shapes[i];

    return 0;
}