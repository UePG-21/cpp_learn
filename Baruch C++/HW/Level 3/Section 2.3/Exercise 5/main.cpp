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
#include "Line.hpp"

using namespace std;

int main()
{
	// Create two points
	Point A(4.0, 1.0);
	Point B(2.0, 3.0);

	// Use these two points to create a line
	Line l = Line(A, B);

	// Print the description of line l
	cout << "Use ToString: " << l.ToString() << endl;

	// Print the coordinates using Get function
	cout << "Use get function: " << "start point is " << l.P1().ToString() << ", end point is " << l.P2().ToString() << endl;

	// Print the length of line l
	cout << "The length of l is: " << l.Length() << endl;

	return 0;
}