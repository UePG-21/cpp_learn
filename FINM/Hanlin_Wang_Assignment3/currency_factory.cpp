#include "currency_factory.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>

using namespace std;

CurrencyFactory::CurrencyFactory()
{
}

CurrencyFactory::CurrencyFactory(string file_name)
{
    ifstream infile(file_name);

    if (!infile)
    {
        throw runtime_error("Unable to open file");  // change #7: using exceptions
    }

    string data;
    string symbol;
    double rate;

    while (infile)
    {
        getline(infile, data);
        istringstream iss(data);  // change #10: using streams
        iss >> symbol >> rate;

        currency_map_[symbol] = new Currency(symbol, rate);  // change #4: free store
    }
}

CurrencyFactory::~CurrencyFactory()
{
    for (auto iter = currency_map_.begin(); iter != currency_map_.end(); ++iter)
    {
        delete iter->second;  // change #5: delete
    }
}

Currency* CurrencyFactory::GetCurrency(string symbol)
{
    auto iter = currency_map_.find(symbol);

    if (iter == currency_map_.end())
    {
        throw runtime_error("Currency not found");  // change #7: using exceptions
    }

    return iter->second;
}
