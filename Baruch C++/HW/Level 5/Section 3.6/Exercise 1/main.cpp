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

using namespace std;

int main()
{
    try
    {
        Array arr = Array();
        for (int i = 1; i < arr.Size(); i++)
        {
            arr.SetElement(i, Point(+i, -i));
        }
        arr.GetElement(10);
        // arr.SetElement(11, Point(1.0, 2.0))

        cout << arr[0] << endl;
        // cout << arr[-1] << endl;
    }
    catch (int err)
    {
        if (err == -1)
        {
            cout << "ERROR: The input index is out of the bound of the array." << endl;
        }
    }
    catch (...)
    {
        cout << "An unhandled excecption has occurred." << endl;
    }

    return 0;
}
