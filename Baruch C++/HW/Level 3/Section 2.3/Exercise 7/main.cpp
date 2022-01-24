/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/14/21
 */
#include <iostream>
#include <sstream>
#include "Point.hpp"

using namespace std;

int main()
{
	// Create a point
	Point my_point(2.0, 1.0);

	// Print the description of my_point
	cout << "Use ToString: " << my_point.ToString() << endl;

	// Print the coordinates using Get function
	cout << "Use get function: " << "x is " << my_point.X() << ", y is " << my_point.Y() << endl;

	// Print the distance between the origin
	cout << "The distance between the origin is " << my_point.Distance() << endl;

	// Print the distance between another point
	Point p(1.0, 2.0);
	cout << "The distance between (1.0, 2.0) is " << my_point.Distance(p) << endl;
	
	return 0;
}