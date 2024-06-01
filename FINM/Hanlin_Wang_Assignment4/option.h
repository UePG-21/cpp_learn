#ifndef OPTION_H
#define OPTION_H

#include <cmath>

const double PI = atan(1.0) * 4;

double cdf(double x);

double pdf(double x);

class Option
{
protected:
    double K_;
    double T_;

protected:
    double d1(double S0, double r, double v);
    double d2(double S0, double r, double v);

public:
    virtual double Price(double S0, double r, double v) = 0;
    virtual double Delta(double S0, double r, double v) = 0;
    virtual double Gamma(double S0, double r, double v) = 0;
};

#endif