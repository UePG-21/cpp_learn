#ifndef CURRENCY_FACTORY_H
#define CURRENCY_FACTORY_H

#include <map>
#include "currency.h"

using namespace std;

class CurrencyFactory
{
private:
    map<string, Currency*> currency_map_;  // change #3: store currency, change #6: using a map

public:
    CurrencyFactory();
    CurrencyFactory(string file_name);
    ~CurrencyFactory();

    Currency* GetCurrency(string symbol);
};

#endif