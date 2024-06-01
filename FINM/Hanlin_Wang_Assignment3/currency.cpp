#include "currency.h"

using namespace std;

Currency::Currency(string symbol, double rate)
    : symbol_(symbol), rate_(rate)
{
}

Currency::~Currency()
{
}

string Currency::GetSymbol()
{
    return symbol_;
}

void Currency::SetSymbol(string symbol)
{
    symbol_ = symbol;
}

double Currency::GetRate()
{
    return rate_;
}

void Currency::SetRate(double rate)
{
    rate_ = rate;
}