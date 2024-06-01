#include <iostream>
#include "mc_pricer.h"
#include "european_call.h"
#include "european_put.h"

using namespace std;

int main()
{
    // variables
    double S0 = 100.0;
    double v = 0.3;
    double r = 0.01;
    double T = 2.0;
    double K = 100.0;
    unsigned long M = 0;

    double call_price = 0.0;
    double put_price = 0.0;

    EuropeanCall call(K, T);
    EuropeanPut put(K, T);


    // Monte Carlo Pricer
    MCPricer mc;

    // 10000
    cout << "# M=10000:" << endl;
    M = 10000;
    call_price = mc.Price(call, S0, v, r, M);
    cout << "Call Price: " << call_price << endl;
    put_price = mc.Price(put, S0, v, r, M);
    cout << "Put Price: " << put_price << endl << endl;

    // 100000
    cout << "# M=100000:" << endl;
    M = 100000;
    call_price = mc.Price(call, S0, v, r, M);
    cout << "Call Price: " << call_price << endl;
    put_price = mc.Price(put, S0, v, r, M);
    cout << "Put Price: " << put_price << endl << endl;

    // 1000000
    cout << "# M=1000000:" << endl;
    M = 1000000;
    call_price = mc.Price(call, S0, v, r, M);
    cout << "Call Price: " << call_price << endl;
    put_price = mc.Price(put, S0, v, r, M);
    cout << "Put Price: " << put_price << endl;

    return 0;
}
