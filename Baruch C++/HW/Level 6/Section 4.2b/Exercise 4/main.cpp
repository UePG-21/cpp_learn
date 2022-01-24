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
#include "Stack.hpp"
#include "ArrayException.hpp"

using namespace std;

int main()
{
	// Create an object
	Stack<int> intStack;

	// Test Stack
	try
	{
		// test Push function
		for (int i = 0; i < 10; i++)
		{
			intStack.Push(i);
		}

		// test Pop function
		for (int i = 0; i < 11; i++)
		{
			cout << intStack.Pop() << endl;
		}
	}
	catch (ArrayException& err)
	{
		cout << err.GetMessage() << endl;
	}

    return 0;
}
