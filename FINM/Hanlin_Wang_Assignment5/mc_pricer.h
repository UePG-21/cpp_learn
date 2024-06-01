#ifndef MC_PRICER_H
#define MC_PRICER_H

#include "option.h"

class MCPricer
{
public:
    double Price(
        const Option& option,
        double stock_price,
        double vol,
        double rate,
        unsigned long path
    );
};

#endif
