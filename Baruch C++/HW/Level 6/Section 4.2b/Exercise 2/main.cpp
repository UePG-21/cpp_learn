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
#include "NumericArray.hpp"
#include "ArrayException.hpp"

using namespace std;

int main()
{
	// Create two numeric arrays
	NumericArray<int> IntNumericArray1;
	for (int i = 0; i < 10; i++)
	{
		IntNumericArray1[i] = i;
	}

	NumericArray<int> IntNumericArray2;
	for (int i = 0; i < 10; i++)
	{
		IntNumericArray2[i] = i + 1;
	}

	// Print the two arrays
	cout << "IntNumericArray1 is (";
	for (int i = 0; i < 10; i++)
	{
		cout << IntNumericArray1[i] << ", ";
	}
	cout << ")" << endl;

	cout << "IntNumericArray2 is (";
	for (int i = 0; i < 10; i++)  // the size of NumericArray is 10
	{
		cout << IntNumericArray2[i] << ", ";
	}
	cout << ")" << endl;

	// Test copy constructor
	NumericArray<int> IntNumericArray3(IntNumericArray1);
	cout << "IntNumericArray3 is (";
	for (int i = 0; i < 10; i++)     //the size of NumericArray is 10
	{
		cout << IntNumericArray3[i] << ", ";
	}
	cout << ")" << endl;

	// Test = and + operator
	NumericArray<int> tmp = IntNumericArray1 + IntNumericArray2;
	NumericArray<int> IntNumericArray4(tmp);
	cout << "IntNumericArray4 is (";
	for (int i = 0; i < 10; i++)
	{
		cout << IntNumericArray4[i] << ", ";
	}
	cout << ")" << endl;

	// Test * operator
	NumericArray<int> IntNumericArray5(IntNumericArray1 * 2);
	cout << "IntNumericArray5 is (";
	for (int i = 0; i < 10; i++)
	{
		cout << IntNumericArray5[i] << ", ";
	}
	cout << ")" << endl;

	// Test dotproduct function
	cout << IntNumericArray1.DotProduct(IntNumericArray3);

    return 0;
}
