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

	// Ask the user to input numbers
	cout << "Please input x:" << endl;
	cin >> set_x;
	cout << "Please input y:" << endl;
	cin >> set_y;

	// Create an object of Point
	Point my_point;

	// Set the coordinates by the set functions
	my_point.SetX(set_x);
	my_point.SetY(set_y);

	// Print the description with the function ToString
	cout << "Use ToString: " << my_point.ToString() << endl;

	// Print the coordinates with Get functions
	cout << "Use get function: the coordinates of the point: (" << my_point.GetX() << ", " << my_point.GetY() << ")" << endl;

	return 0;
}