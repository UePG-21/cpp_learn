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

#ifndef Array_cpp
#define Array_cpp

using namespace std;

template <typename T>
Array<T>::Array() :m_size(10), m_data(new T[10]) {} // default constructor

template <typename T>
Array<T>::Array(int size) :m_size(size), m_data(new T[size]) {}  // constructor

template <typename T>
Array<T>::Array(const Array<T>& a) :m_size(a.m_size), m_data(new T[m_size])  // copy constructor
{
    for (int i = 0; i < m_size; i++)  // then copy data inside
    {
        m_data[i] = a.m_data[i];
    }
}

template <typename T>
Array<T>::~Array()  // destructor
{
    delete[] m_data;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& a)  // assignment operator overloading
{
    if (this == &a)  // preclude self-assignment
    {
        return *this;
    }

    delete[] m_data;

    m_size = a.m_size;
    m_data = new T[m_size];  // create the array first
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = a.m_data[i];
    }
    return *this;
}

template <typename T>
const int Array<T>::Size() const  // return the size of the array
{
    return m_size;
}

template <typename T>
T& Array<T>::GetElement(int index) const  // get an element
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}

template <typename T>
void Array<T>::SetElement(int index, const T& p)  // set an element
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }
    m_data[index] = p;
}

template <typename T>
T& Array<T>::operator [] (int index)  // square bracket operator overloading
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}

template <typename T>
const T& Array<T>::operator [] (int index) const  // make sure that this function is also available for const parameter
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }
    return m_data[index];
}

#endif
