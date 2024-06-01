#include <iostream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include "Shape.hpp"

using namespace std;

Shape::Shape() :m_id(rand())  // default constructor
{
    cout << "A shape has been created by default constructor." << endl;
}

Shape::Shape(const Shape& s) :m_id(s.m_id)  // copy constructor
{
    cout << "A shape has been created by copy constructor." << endl;
}

Shape::~Shape()  // destructor
{
    cout << "A shape has been deleted by destructor."  << endl;
}

Shape& Shape::operator=(const Shape& s)  // assignment operator
{
    if (this == &s)  //preclude self-assignment
    {
        return *this;
    }
    m_id = s.m_id;

    return *this;
}

string Shape::ToString() const  // return id as string
{
    stringstream ss;
    ss << "ID: " << m_id;
    return ss.str();
}

int Shape::ID() const  // retrieve id
{
    return m_id;
}