/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/28/21
 */
#include <iostream>
#include <string>
#include <boost/variant.hpp>
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"

using namespace std;

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType gettype()
{
    ShapeType shape;

    cout << "What kind of shape do you want to create? (P for point, L for line, C for circle)" << endl;
    char choice;
    cin >> choice;

    switch (choice)
    {
    case 'P':
        shape = Point();
        break;
    case 'L':
        shape = Line();
        break;
    case 'C':
        shape = Circle();
        break;
    default:
        cout << "No such type." << endl;
        break;
    }

    return shape;
}

int main()
{
    // Get ShapeType
    ShapeType mytype = gettype();
    cout << mytype << endl;

    // Assign the variant to a Line variable
    try
    {
        Line l = boost::get<Line>(mytype);
    }
    catch (boost::bad_get& err)
    {
        cout << "Error: " << err.what() << endl;
    }

    cout << "The shape is " << mytype << endl;

    // Create an instance of visitor
    Visitor v(1, 1);
    boost::apply_visitor(v, mytype);
    cout << "Then shift the shape." << endl;
    cout << "Now the shape is " << mytype << endl;

    return 0;
}

