#include "european_put.h"

EuropeanPut::EuropeanPut(double K, double T)
    : Option(K, T)
{
}

double EuropeanPut::Price(double S0, double r, double v)
{
    return K_ * exp(-r * T_) * cdf(-d2(S0, r, v)) - S0 * cdf(-d1(S0, r, v));
}

double EuropeanPut::Delta(double S0, double r, double v)
{
    return cdf(d1(S0, r, v)) - 1;
}
double EuropeanPut::Gamma(double S0, double r, double v)
{
    return pdf(d1(S0, r, v)) / (S0 * v * sqrt(T_));
}

double EuropeanPut::GetExpirationPayoff(double ST) const
{
    return (ST < K_) ? K_ - ST : 0.0;
}
