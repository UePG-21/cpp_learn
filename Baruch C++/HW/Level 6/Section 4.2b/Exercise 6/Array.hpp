/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/20/21
 */
#ifndef Array_hpp
#define Array_hpp

#include <iostream>

using namespace std;

template <typename T>
class Array
{
private:
    int m_size;
    T* m_data;
    static int default_size;  // static data member

public:
    // constructor and destructor
    Array();  // default constructor
    Array(int size);  // constructor
    Array(const Array<T>& a);  // copy constructor
    virtual ~Array();  // destructor

    Array<T>& operator = (const Array<T>& a);  // assignment operator overloading

    // functions
    const int Size() const;  // return the size of the array
    T& GetElement(int index) const;  // get an element
    void SetElement(int index, const T& p);  // set an element

    // operator overloading
    T& operator [] (int index);  // square bracket operator overloading
    const T& operator [] (int index) const;  // make sure that this function is also available for const parameter

    // static functions
    static void DefaultSize(int i);  // set default size
    static int DefaultSize();  // get default size
};

#ifndef Array_cpp
#include "Array.cpp"
#endif

#endif
