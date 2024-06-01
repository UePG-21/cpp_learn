#include "european_call.h"

double EuropeanCall::d1(double S0, double r, double v)
{
    return (log(S0 / K_) + r * T_) / (v * sqrt(T_)) + v * sqrt(T_) / 2;
}
double EuropeanCall::d2(double S0, double r, double v)
{
    return (log(S0 / K_) + r * T_) / (v * sqrt(T_)) - v * sqrt(T_) / 2;
}

EuropeanCall::EuropeanCall(double K, double T)
    : K_(K), T_(T)
{
}
    
double EuropeanCall::Price(double S0, double r, double v)
{
    return S0 * cdf(this->d1(S0, r, v)) - K_ * exp(-r * T_) * cdf(this->d2(S0, r, v));
}

double EuropeanCall::Delta(double S0, double r, double v)
{
    return cdf(this->d1(S0, r, v));
}
double EuropeanCall::Gamma(double S0, double r, double v)
{
    return pdf(this->d1(S0, r, v)) / (S0 * v * sqrt(T_));
}