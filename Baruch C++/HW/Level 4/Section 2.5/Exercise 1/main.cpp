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

using namespace std;

int main()
{
    // Create objects
    Point* p_1 = new Point;  // by default constructor
    Point* p_2 = new Point(1.0, 2.0);  // by constructor
    Point* p_3 = new Point(*p_1);  // by copy constructor

    // Print
    cout << "The distance between p_1 and p_2 is " << p_1->Distance(*p_2) << endl;
    cout << "p_3 is " << *p_3 << endl;

    // delete object
    delete p_1;
    delete p_2;
    delete p_3;

    // Create an array of points
    cout << "Please input the size of the array." << endl;
    int size;
    cin >> size;

    // First create the array of points on stack, then get a compiler error.
    // Point array_point[size];

    // Then create it on heap
    Point* p = new Point[size];  // can't see other constructors than default constructor
    delete[] p;

    return 0;
}