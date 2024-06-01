#include <iostream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include "Shape.hpp"

using namespace std;

Shape::Shape() : m_id(rand()) {}  // default constructor

Shape::Shape(const Shape& s) : m_id(s.m_id) {}  // copy constructor

Shape::~Shape() {}  // destructor

Shape& Shape::operator = (const Shape& s)  // assignment operator
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

void Shape::Print() const
{
    cout << ToString() << endl;
}
