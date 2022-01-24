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
#include <boost/shared_ptr.hpp>
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"

using namespace std;

typedef boost::shared_ptr<Shape> ShapePtr;  // typedef for a shared pointer to shape
typedef Array<ShapePtr> ShapeArray;  //  a typedef for an array with shapes stored as shared pointers

int main()
{
    Point A(1, 2);
    Point B(3, 4);

    ShapePtr pp(new Point(1.1, 2.2));
    cout << "Reference Count: " << pp.use_count() << endl;

    ShapePtr pl(new Line(A, B));
    ShapePtr pc(new Circle(Point(0, 0), 5));
    {
        ShapeArray sa;
        sa.SetElement(0, pp);
        cout << "Reference Count: " << pp.use_count() << endl;

        sa.SetElement(1, pl);
        sa.SetElement(2, pc);
        cout << "The first element of ShapeArray sa is " << sa.GetElement(0)->ToString() << endl;
        cout << "The second element of ShapeArray sa is " << sa.GetElement(1)->ToString() << endl;
        cout << "The third element fo ShapeArray sa is " << sa.GetElement(2)->ToString() << endl;
    }
    cout << "Reference Count: " << pp.use_count() << endl;

    return 0;
}
