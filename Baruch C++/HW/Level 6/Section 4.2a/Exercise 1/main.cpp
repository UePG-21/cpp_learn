/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/20/21
 */

#include <iostream>
#include "Point.hpp"
#include "Array.hpp"
#include "ArrayException.hpp"

using namespace std;

int main()
{
	// Test type array
	Array<Point> points(5);
	for (int i = 0; i < points.Size(); i++)
	{
		points.SetElement(i, Point(+i, -i));
		cout << points[i] << endl;
	}

	// Test type int
	Array<int> ints(5);
	for (int i = 0; i < ints.Size(); i++)

	{
		ints.SetElement(i, i+1);
		cout << ints[i] << endl;
	}

    return 0;
}
