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
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	cout << intArray1.DefaultSize() << endl;    // 10. The default size of int array is 10.
	cout << intArray2.DefaultSize() << endl;    // 10. The default size of int array is 10.
	cout << doubleArray.DefaultSize() << endl;  // 10. The default size of double array is 10.

	intArray1.DefaultSize(15);                  // Set the default size of int array as 15.

	cout << intArray1.DefaultSize() << endl;    // 15. The default size of int array is 15 now.
	cout << intArray2.DefaultSize() << endl;    // 15. Although we didn't change the default size of intArray2 directly, the default size of int array is 15 now.
	cout << doubleArray.DefaultSize() << endl;  // 10. The default size of double array is remained.

    return 0;
}
