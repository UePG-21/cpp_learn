#ifndef Array_hpp
#define Array_hpp

#include <iostream>
#include "Point.hpp"

using namespace std;

namespace HanlinWANG
{
    namespace Containers
    {
        class Array
        {
        private:
            int m_size;
            CAD::Point* m_data;

        public:
            // constructor and destructor
            Array();  // default constructor
            Array(int size);  // constructor
            Array(const Array& a);  // copy constructor
            ~Array();  // destructor

            // functions
            const int Size() const;  // return the size of the array
            CAD::Point& GetElement(int index) const;  // get an element
            void SetElement(int index, const CAD::Point& p);  // set an element
            
            // operator overloading
            Array& operator = (const Array& a);  // assignment operator overloading
            CAD::Point& operator [] (int index);  // square bracket operator overloading
            const CAD::Point& operator [] (int index) const;  // make sure that this function is also available for const parameter
        };
    }
}

#endif