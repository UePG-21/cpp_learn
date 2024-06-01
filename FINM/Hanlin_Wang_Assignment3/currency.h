#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>

using namespace std;

class Currency
{
private:
    string symbol_;
    double rate_;

public:
    Currency() = default;  // change #11: using default implementations
    Currency(string symbol, double rate);
    Currency(const Currency& other) = default;  // change #11: using default implementations
    ~Currency();

    Currency& operator=(const Currency& other) = default;  // change #11: using default implementations

    string GetSymbol();
    void SetSymbol(string symbol);
    double GetRate();
    void SetRate(double rate);
};

#endif