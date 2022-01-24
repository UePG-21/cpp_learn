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
#include "Circle.hpp"

using namespace std;

int main()
{
	// Create a point
	Point centre(3.0, 4.0);

	// Create a circle
	Circle c(centre, 5.0);

	// Print the description of circle c (use ToString)
	cout << "Description of circle c (use ToString): " << c.ToString() << endl;

	// Print the description of circle c (use get function)
	cout << "Description of circle c (use get function): " << "The centre of the circle is " << c.CentrePoint().ToString() << ", the radius is " << c.Radius() << endl;

	// Print the diameter of circle c
	cout << "The diameter of circle c is " << c.Diameter() << endl;

	// Print the area of circle c
	cout << "The area of circle c is " << c.Area() << endl;

	// Print the circumference of circle c
	cout << "The circumference of c is " << c.Circumference() << endl;

	return 0;
}