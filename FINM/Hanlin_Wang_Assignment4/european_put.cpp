#include "european_put.h"

double EuropeanPut::d1(double S0, double r, double v)
{
    return (log(S0 / K_) + r * T_) / (v * sqrt(T_)) + v * sqrt(T_) / 2;
}
double EuropeanPut::d2(double S0, double r, double v)
{
    return (log(S0 / K_) + r * T_) / (v * sqrt(T_)) - v * sqrt(T_) / 2;
}

EuropeanPut::EuropeanPut(double K, double T)
    : K_(K), T_(T)
{
}
    
double EuropeanPut::Price(double S0, double r, double v)
{
    return K_ * exp(-r * T_) * cdf(-this->d2(S0, r, v)) - S0 * cdf(-this->d1(S0, r, v));
}

double EuropeanPut::Delta(double S0, double r, double v)
{
    return cdf(this->d1(S0, r, v)) - 1;
}
double EuropeanPut::Gamma(double S0, double r, double v)
{
    return pdf(this->d1(S0, r, v)) / (S0 * v * sqrt(T_));
}