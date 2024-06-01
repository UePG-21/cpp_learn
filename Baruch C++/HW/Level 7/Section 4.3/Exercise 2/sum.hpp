/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/25/21
 */
#include <iostream>

using namespace std;

// Calculate the sum of a container
template <typename T>
double Sum(const T& source)
{
    typename T::const_iterator it;
    double sum = 0.0;

    for (it = source.begin(); it != source.end(); it++)
    {
        sum += (*it);
    }

    return sum;
}

// Calculate the sum between two iterators
template <typename T>
double Sum(typename T::const_iterator& start_iterator, typename T::const_iterator& end_iterator)
{
    typename T::const_iterator it;
    double sum = 0.0;

    for (it = start_iterator; it != end_iterator; it++)
    {
        sum += (*it);
    }

    return sum;
}

// Calculate the sum of map
template <typename T1, typename T2>
double Sum(const map<T1, T2>& source)
{
    typename map<T1, T2>::const_iterator it;
    double sum = 0.0;

    for (it = source.begin(); it != source.end(); it++)
    {
        sum += it->second;
    }

    return sum;
}

// Calculate the sum between two iterators of map
template <typename T1, typename T2>
double Sum(const typename map<T1, T2>::const_iterator& start_iterator, const typename map<T1, T2>::const_iterator& end_iterator)
{
    typename map<T1, T2>::const_iterator it;
    double sum = 0.0;

    for (it = start_iterator; it != end_iterator; it++)
    {
        sum += it->second;
    }

    return sum;
}
