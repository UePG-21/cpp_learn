/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/20/21
 */
#ifndef ArrayException_hpp
#define ArrayException_hpp

#include <iostream>
#include <sstream>
#include "Point.hpp"
#include "Array.hpp"

using namespace std;

// base class
class ArrayException
{
public:
    virtual string GetMessage() const = 0;
};

// derived class
class OutOfBoundsException :public ArrayException
{
private:
    int m_index;

public:
    OutOfBoundsException(int x) { m_index = x; };

    string GetMessage() const
    {
        stringstream ss;
        ss << "The given index " << m_index << " is out of bounds.";
        return ss.str();
    }
};

class NotSameSizeException :public ArrayException
{
    string GetMessage() const
    {
        stringstream ss;
        ss << "These two arrays don't have the same size.";
        return ss.str();
    }
};

#endif
