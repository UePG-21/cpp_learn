/*
 * @Objective: 
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/19/21
 */
#ifndef Shape_hpp
#define Shape_hpp

#include <iostream>

using namespace std;

class Shape
{
private:
    int m_id;

public:
    Shape();  // default constructor
    Shape(const Shape& s);  // copy constructor
    virtual ~Shape();  // destructor

    Shape& operator=(const Shape& s);  // assignment operator

    virtual string ToString() const;  // return id as string
    int ID() const;  // retrieve id

    virtual void Draw() const = 0;  // draw function
    void Print() const;  // print function
};

#endif