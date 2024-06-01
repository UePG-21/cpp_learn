#ifndef StackException_hpp
#define StackException_hpp

#include <iostream>
#include <sstream>
#include "Point.hpp"
#include "Array.hpp"
#include "Stack.hpp"

using namespace std;

// base class
class StackException
{
public:
    virtual string GetMessage() const = 0;
};

// derived class
class StackFullException : public StackException
{
public:
    string GetMessage() const
    {
        stringstream ss;
        ss << "StackFullException";
        return ss.str();
    }
};

class StackEmptyException : public StackException
{
public:
    string GetMessage() const
    {
        stringstream ss;
        ss << "StackEmptyException";
        return ss.str();
    }
};

#endif
