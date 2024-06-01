#ifndef OPTION_H
#define OPTION_H

#include <cmath>
#include "utils.h"

class Option
{
protected:
    double K_;
    double T_;

protected:
    double d1(double S0, double r, double v);
    double d2(double S0, double r, double v);

public:
    Option(double K, double T);

    virtual double Price(double S0, double r, double v) = 0;
    virtual double Delta(double S0, double r, double v) = 0;
    virtual double Gamma(double S0, double r, double v) = 0;
    virtual double GetExpirationPayoff(double ST) const = 0;
    double GetTimeToExpiration() const;
};

#endif
