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
    // Create an array of pointers
    Point** p = new Point* [3];

    // Let each Point created by constructor with parameters other than default constructor
    p[0] = new Point(1.0, 2.0);
    p[1] = new Point(3.0, 4.0);
    p[2] = new Point(5.0, 6.0);

    // Print each point in array
    for (int i = 0; i < 3; i++)
    {
        cout << *p[i] << endl;
    }

    // Delete each point in array
    for (int i = 0; i < 3; i++)
    {
        delete p[i];
    }

    // Also delete the array
    delete[] p;

    return 0;
}