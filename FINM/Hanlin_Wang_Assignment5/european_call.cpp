#include "european_call.h"

#include <iostream>
using namespace std;

EuropeanCall::EuropeanCall(double K, double T)
    : Option(K, T)
{
}

double EuropeanCall::Price(double S0, double r, double v)
{
    cout << K_ << " " << T_ << endl;
    return S0 * cdf(d1(S0, r, v)) - K_ * exp(-r * T_) * cdf(d2(S0, r, v));
}

double EuropeanCall::Delta(double S0, double r, double v)
{
    return cdf(d1(S0, r, v));
}
double EuropeanCall::Gamma(double S0, double r, double v)
{
    return pdf(d1(S0, r, v)) / (S0 * v * sqrt(T_));
}

double EuropeanCall::GetExpirationPayoff(double ST) const
{
    return (ST > K_) ? ST - K_ : 0.0;
}
