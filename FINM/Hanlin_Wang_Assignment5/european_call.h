#ifndef EUROPEAN_CALL_H
#define EUROPEAN_CALL_H

#include "option.h"

class EuropeanCall : public Option
{
public:
    EuropeanCall(double K, double T);

    double Price(double S0, double r, double v) override;
    double Delta(double S0, double r, double v) override;
    double Gamma(double S0, double r, double v) override;
    double GetExpirationPayoff(double ST) const override;
};

#endif
