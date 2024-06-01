#ifndef CURRENCY_CONVERTER_H
#define CURRENCY_CONVERTER_H

#include "currency_factory.h"


class CurrencyConverter
{
private:
    CurrencyFactory factory_;

public:
    CurrencyConverter() = default;  // change #11: using default implementations
    CurrencyConverter(const CurrencyFactory& factory);
    ~CurrencyConverter();

    double OutAmount(string in_symbol, string out_symbol, double in_amount);
};




#endif