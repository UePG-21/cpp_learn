#include "currency_converter.h"

CurrencyConverter::CurrencyConverter(const CurrencyFactory& factory)
    : factory_(factory)
{
}

CurrencyConverter::~CurrencyConverter()
{
}

double CurrencyConverter::OutAmount(string in_symbol, string out_symbol, double in_amount)
{
    Currency* in_curr = factory_.GetCurrency(in_symbol);
    Currency* out_curr = factory_.GetCurrency(out_symbol);

    return in_amount / in_curr->GetRate() * out_curr->GetRate();
}
