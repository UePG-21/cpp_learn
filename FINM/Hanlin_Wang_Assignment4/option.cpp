#include "option.h"

double cdf(double x)
{
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double pdf(double x)
{
    return exp(-0.5 * pow(x, 2)) / sqrt(2 * PI);
}

double Option::d1(double S0, double r, double v)
{
    return (log(S0 / K_) + r * T_) / (v * sqrt(T_)) + v * sqrt(T_) / 2;
}

double Option::d2(double S0, double r, double v)
{
    return (log(S0 / K_) + r * T_) / (v * sqrt(T_)) - v * sqrt(T_) / 2;
}