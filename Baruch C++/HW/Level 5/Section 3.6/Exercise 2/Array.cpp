/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/20/21
 */

#include <iostream>
#include "Array.hpp"
#include "ArrayException.hpp"

using namespace std;

Array::Array()  // default constructor
{
    m_size = 10;
    m_data = new Point[10];
}

Array::Array(int size)  // constructor
{
    m_size = size;
    m_data = new Point[size];
}

Array::Array(const Array& a)  // copy constructor
{
    m_size = a.m_size;
    m_data = new Point[m_size];  // create the array first
    for (int i = 0; i < m_size; i++)  // then copy data inside
    {
        m_data[i] = a.m_data[i];
    }
}

Array::~Array()  // destructor
{
    delete[] m_data;
}

Array& Array::operator = (const Array& a)  // assignment operator overloading
{
    if (this == &a)  // preclude self-assignment
    {
        return *this;
    }

    delete[] m_data;

    m_size = a.m_size;
    m_data = new Point[m_size];  // create the array first
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = a.m_data[i];
    }
    return *this;
}

const int Array::Size() const  // return the size of the array
{
    return m_size;
}

Point& Array::GetElement(int index) const  // get an element
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}

void Array::SetElement(int index, const Point& p)  // set an element
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }
    m_data[index] = p;
}

Point& Array::operator [] (int index)  // square bracket operator overloading
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}

const Point& Array::operator [] (int index) const  // make sure that this function is also available for const parameter
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}
