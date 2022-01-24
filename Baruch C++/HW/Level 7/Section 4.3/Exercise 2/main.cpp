/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/25/21
 */
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include "sum.hpp"

using namespace std;

int main()
{
    // Test list
    list<double> l;

    for (int i = 0; i < 10; i++)
    {
        l.push_back(i+1);
    }

    cout << "The sum of all elements of the list is " << Sum<list<double>>(l) << endl;  // calculate the sum from the first to the last

    list<double>::const_iterator it1 = l.begin();
    list<double>::const_iterator it2 = l.end();

    cout << "The sum between the first and the ninth element is " << Sum<list<double>>(it1, --it2) << endl;  // calculate the sum between the first and the ninth element
    l.clear();

    // Test vector
    vector<double> v;
    v.reserve(12);

    for (int i = 0; i< 10; i++)
    {
        v.push_back(i+1);
    }

    cout << "The sum of all elements of the vector is " << Sum<vector<double>>(v) << endl;  // calculate the sum from the first to the last

    vector<double>::const_iterator it3 = v.begin();
    vector<double>::const_iterator it4 = v.end();

    cout << "The sum between the second and the last element is " << Sum<vector<double>>(++it3, it4) << endl;  // calculate the sum from the second and the last element
    v.clear();

    // Test map
    map<string, double> m;
    m["Hello"] = 1.1;
    m["C++"] = 2.2;
    m["World"] = 3.3;
    // Map will put elements by order automatically. In this case "C++" is before "Hello" and "Hello" is before "World".

    cout << "The sum of all elements of the value of the map is " << Sum<string, double>(m) << endl;  // calculate the sum from the first to the last

    map<string, double>::const_iterator it5 = m.begin();
    map<string, double>::const_iterator it6 = m.end();

    cout << "The sum between the second and the last element is " << Sum<string, double>(++it5, it6) << endl;  // calculate the sum from the second to the last element
    m.clear();

    return 0;
}

