/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/28/21
 */
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
#include <iostream>

using namespace std;

typedef boost::tuple<string, double, double> Person;  // set the name, age and height

void Print(const Person& p)
{
    cout << "Name: " << p.get<0>() << ", " << "Age: " << p.get<1>() << "; " << "Height: " << p.get<2>() << endl;
}

int main()
{
    // Create several persons
    Person A(string("Wang"), 21, 178.2);
    Person B(string("Han"), 22, 177.3);
    Person C(string("Lin"), 23, 176.4);

    // Print them
    Print(A);
    Print(B);
    Print(C);

    // Increment the age of C
    C.get<1>() += 1;
    cout << "After increment the age of Lin, his age comes to " << C.get<1>() << " years old." << endl;

    return 0;
}
