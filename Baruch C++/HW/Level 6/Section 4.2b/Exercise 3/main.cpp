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
#include "PointArray.hpp"
#include "ArrayException.hpp"

using namespace std;

int main()
{
	// Create object
	PointArray arr(5);

	for (int i = 0; i < 5; i++)
	{
		arr.SetElement(i, Point(i, i));
	}

	// Test length function
	cout << "The length of arr is " << arr.Length() << endl;

    return 0;
}
