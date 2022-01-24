#ifndef Stack_hpp
#define Stack_hpp

#include "Array.hpp"

template <typename T, int size>
class Stack
{
private:
    int m_current;  // index
    Array<T> m_array;  // array as member

public:
    // constructor and destructor
    Stack();
    Stack(const Stack<T, size>& source);
    ~Stack();

    // assignment operator
    Stack& operator = (const Stack<T, size>& source);

    // functions
    void Push(T& source);  // store the element at the current position in the embedded array
    const T& Pop();  // decrement the current position, then return the element at that positioon
};

#ifndef Stack_cpp
#include "Stack.cpp"
#endif

#endif
