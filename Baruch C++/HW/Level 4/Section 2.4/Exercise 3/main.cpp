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
    Point p(1.0, 1.0);
	if (p == (Point)1.0) cout << "Equal!" << endl;
	else cout << "Not equal" << endl;

    return 0;
}