#ifndef EUROPEAN_CALL_H
#define EUROPEAN_CALL_H

#include "option.h"

class EuropeanCall : public Option
{
private:
    double K_;
    double T_;

private:
    double d1(double S0, double r, double v);
    double d2(double S0, double r, double v);

public:
    EuropeanCall(double K, double T);
    
    double Price(double S0, double r, double v) override;
    double Delta(double S0, double r, double v) override;
    double Gamma(double S0, double r, double v) override;
};

#endif