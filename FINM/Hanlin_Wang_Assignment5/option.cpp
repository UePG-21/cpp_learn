#include "option.h"

Option::Option(double K, double T)
    : K_(K), T_(T)
{
}

double Option::d1(double S0, double r, double v)
{
    return (log(S0 / K_) + r * T_) / (v * sqrt(T_)) + v * sqrt(T_) / 2;
}

double Option::d2(double S0, double r, double v)
{
    return (log(S0 / K_) + r * T_) / (v * sqrt(T_)) - v * sqrt(T_) / 2;
}

double Option::GetTimeToExpiration() const
{
    return T_;
}
