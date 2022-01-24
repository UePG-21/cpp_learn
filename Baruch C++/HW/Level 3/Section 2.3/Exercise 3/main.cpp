/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/13/21
 */
#include <iostream>
#include <sstream>
#include "Point.hpp"

using namespace std;

int main()
{
	double set_x;
	double set_y;

	// Ask the user to input x and y
	cout << "Please input x:" << endl;
	cin >> set_x;
	cout << "Please input y:" << endl;
	cin >> set_y;

	// Get an instance of the class Point
	Point my_point;

	// Set the coordinates
	my_point.X(set_x);
	my_point.Y(set_y);

	// Print the description with the function ToString
	cout << "Use ToString: " << my_point.ToString() << endl;

	// Print the coordinates with Get functions
	cout << "Use get function: the coordinates of the point: (" << my_point.X() << ", " << my_point.Y() << ")" << endl;

	// Print the distance between the origin
	cout << "The distance between the origin is " << my_point.Distance() << endl;
	cout << "The distance between the origin is " << my_point.Distance() << endl;

	// Print the distance between another point
	Point p;
	p.X(2.0);
	p.Y(1.0);
	cout << "The distance between (2.0, 1.0) is " << my_point.Distance(p) << endl;

	return 0;
}