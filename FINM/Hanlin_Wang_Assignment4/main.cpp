#include <iostream>
#include "european_call.h"
#include "european_put.h"

using namespace std;

int main()
{
    // Call
    double S0 = 100.0;
    double r = 0.05;
    double v = 0.3;
    double K = 100.0;
    double T = 1.0;

    EuropeanCall c1(K , T);
    cout << "Call price: " << c1.Price(S0, r, v) << ", Delta: "<< c1.Delta(S0, r, v) 
        << ", Gamma: " << c1.Gamma(S0, r, v) << endl;

    // Put
    S0 = 120.0;
    r = 0.1;
    v = 0.4;
    K = 120.0;
    T = 2.0;

    EuropeanPut p1(K, T);
    cout << "Put price: " << p1.Price(S0, r, v) << ", Delta: " << p1.Delta(S0, r, v) 
        << ", Gamma: " << p1.Gamma(S0, r, v) << endl;

    return 0;
}