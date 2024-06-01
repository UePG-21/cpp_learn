/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/16/21
 */
#include <iostream>
#include <sstream>
#include "Point.hpp"
#include "Array.hpp"

using namespace std;

void test_1();  // test default constructor, Size(), SetElement() and GetElement()
void test_2();  // test constructor with argument and operator[]
void test_3();  // test copy constructor
void test_4();  // test operator=

int main()
{
    // Test all
    test_1();
    test_2();
    test_3();
    test_4();

    return 0;
}

void test_1()  // test default constructor, Size(), SetElement() and GetElement()
{
    // Create an array
    Array arr_1 = Array();
    cout << "The size of arr_1 is " << arr_1.Size() << endl;

    // Print the elements
    cout << "arr_1 is ";
    for (int i = 1; i < arr_1.Size(); i++)
    {
        cout << arr_1.GetElement(i) << ", ";
    }
    cout << endl;
}

void test_2()  // test constructor with argument and operator[]
{
    // Create an array
    Array arr_2 = Array(3);

    // Set elements
    for (int i = 0; i < arr_2.Size(); i++)
    {
        arr_2[i] = Point(i+1, i+2);
    }

    // Print the elements
    for (int i = 0; i < arr_2.Size(); i++)
    {
        cout << "The " << i+1 << "th element of arr_2 is " << arr_2[i] << endl;
    }
}

void test_3()  // test copy constructor
{
    // Create an array and copy it
    Array arr_2 = Array(3);
    Array arr_3 = Array(arr_2);

    // Print these two arrays
    cout << "arr_2 " << arr_2[0] << ", " << arr_2[1] << ", " << arr_2[2] << endl;
    cout << "arr_3 " << arr_3[0] << ", " << arr_3[1] << ", " << arr_3[2] << endl;
}

void test_4()  // test operator=
{
    // Create two arrays
    Array arr_1 = Array();
    Array arr_4 = Array(10);
    arr_4 = arr_1;

    // Print these two arrays
    cout << "arr_1 is ";
    for (int i = 1; i < arr_1.Size(); i++)
	{
		cout << arr_1.GetElement(i) << ", ";
	}
	cout << endl;

	cout << "arr_4 is ";
	for (int i = 1; i < arr_4.Size(); i++)
	{
		cout << arr_4.GetElement(i) << ", ";
	}
	cout << endl;
}