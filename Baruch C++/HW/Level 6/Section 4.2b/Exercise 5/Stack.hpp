#ifndef Stack_hpp
#define Stack_hpp

#include "Array.hpp"

template <typename T>
class Stack
{
public:
    // constructor and destructor
    Stack();
    Stack(int size);
    Stack(const Stack<T>& source);
    ~Stack();

    // assignment operator
    Stack& operator = (const Stack<T>& source);

    // functions
    void Push(T& source);  // store the element at the current position in the embedded array
    const T& Pop();  // decrement the current position, then return the element at that positioon

private:
    int m_current;  // index
    Array<T> m_array;  // array as member
};

#ifndef Stack_cpp
#include "Stack.cpp"
#endif

#endif
