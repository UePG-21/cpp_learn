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
	// Create a fixed point
	const Point cp(1.5, 3.9);

	// Print the description with the function ToString
	cout << "Use ToString: " << cp.ToString() << endl;

	// Print the coordinates with Get functions
	cout << "Use get function: the coordinates of the point: (" << cp.X() << ", " << cp.Y() << ")" << endl;

	// Print the distance between the origin
	cout << "The distance between the origin is " << cp.Distance() << endl;
	cout << "The distance between the origin is " << cp.Distance() << endl;

	// Print the distance between another point
	Point p;
	p.X(2.0);
	p.Y(1.0);
	cout << "The distance between (2.0, 1.0) is " << cp.Distance(p) << endl;

	return 0;
}