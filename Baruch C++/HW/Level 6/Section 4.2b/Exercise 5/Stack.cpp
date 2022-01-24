/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/22/21
 */
#ifndef Stack_cpp
#define Stack_cpp

#include "Point.hpp"
#include "Array.hpp"
#include "Stack.hpp"
#include "StackException.hpp"

// constructor and destructor
template <typename T>
Stack<T>::Stack() : m_current(0), m_array() {}

template <typename T>
Stack<T>::Stack(int size) : m_current(0), m_array(size) {}

template <typename T>
Stack<T>::Stack(const Stack<T>& source) : m_current(source.m_current), m_array(source.m_array) {}

template <typename T>
Stack<T>::~Stack() {}

// assignment operator
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source)
{
    m_current = source.m_current;
    m_array = source.m_array;
}

// functions
template <typename T>
void Stack<T>::Push(T& source)
{
    try
    {
        m_array[m_current++] = source;
    }
    catch (ArrayException& err)
    {
        throw StackFullException();
    }
}

template <typename T>
const T& Stack<T>::Pop()
{
    try
    {
        return m_array[--m_current];
    }
    catch (ArrayException& err)
    {
        m_current = 0;
        throw StackEmptyException();
    }
}

#endif
