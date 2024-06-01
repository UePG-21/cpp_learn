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

using namespace std;

int main()
{
    Point a(1.0, 1.0);
    Point b(2.0, 1.0);
    Point c;

    cout << "a is " << a.ToString() << endl;
    cout << "b is " << b.ToString() << endl;

    c = -a;
    cout << "-a is " << c.ToString() << endl;

    c = b * 2;
    cout << "b*2 is " << c.ToString() << endl;

    c = a + b;
    cout << "a+b is " << c.ToString() << endl;

    if (a==b)
    {
        cout << "a equals to b." << endl;
    }
    else
    {
        cout << "a doesn't equal to b." << endl;
    }

    c = a;
    cout << "a is " << a.ToString() << ". c=a, then c is " << c.ToString() << endl;

    a *= 3;
    cout << "a*=3, then a is " << a.ToString() << endl;

    return 0;
}