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

using namespace std;

int main()
{
    // Test list
    list<double> l;
    l.push_back(1.1);  // add element by push_back
    l.push_back(2.2);
    l.push_front(3.3);  // add element by push_front

    cout << "The first element of the list is " << l.front() << endl;  // access the first element by front()
    cout << "The last element of the list is " << l.back() << endl;  // access the last element by back()
    l.clear();

    // Test vector
    vector<double> v;
    v.reserve(3);
    v.push_back(1.1);  // add element by push_back
    v.push_back(2.2);
    v.push_back(3.3);

    cout << "The 1st element of the vector is " << v[0] << endl;  // access the element by index operator
    cout << "The 2nd element of the vector is " << v[1] << endl;
    cout << "The 3rd element of the vector is " << v[2] << endl;

    v.push_back(4.4);  // make the vector grow
    cout << "The new element added is " << v[3] << endl;
    v.clear();

    // Test map
    map<string, double> m;
    m["Hello"] = 1.1;  // add elements into the map
    m["C++"] = 2.2;
    m["World"] = 3.3;

    cout << "Hello is mapped to " << m["Hello"] << endl;  // access elements by sqare bracket operator
    cout << "C++ is mapped to " << m["C++"] << endl;
    cout << "World is mapped to " << m["World"] << endl;
    m.clear();

    return 0;
}
