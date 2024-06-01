/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/26/21
 */
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include <string>
#include "countif.hpp"

using namespace std;

int main()
{
    // Create a list
    list<double> l;

    for (int i = 1; i < 11; i++)
    {
        l.push_back(i);
    }

    // Count elements less than 4 by function
    cout << count_if(l.begin(), l.end(), lessThan) << endl;

    // Count elements less than 6 by function object
    cout << count_if(l.begin(), l.end(), LessThan(6));

    return 0;
}
