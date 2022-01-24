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
	try
	{
		Array arr = Array();
		for (int i = 1; i < arr.Size(); i++)
		{
			arr.SetElement(i, Point(+i, -i));
		}
		arr.GetElement(10);
		// arr.SetElement(1, Point(2.0, 3.0));

		cout << arr[0] << endl;
		// cout << arr[-1] << endl;
	}
	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}
	catch (...)
	{
		cout << "An unhandled exception has occurred." << endl;
	}

    return 0;
}
