#ifndef EUROPEAN_PUT_H
#define EUROPEAN_PUT_H

#include "option.h"

class EuropeanPut : public Option
{
public:
    EuropeanPut(double K, double T);

    double Price(double S0, double r, double v) override;
    double Delta(double S0, double r, double v) override;
    double Gamma(double S0, double r, double v) override;
    double GetExpirationPayoff(double ST) const override;
};

#endif
