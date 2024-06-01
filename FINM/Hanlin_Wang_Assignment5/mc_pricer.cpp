#include "mc_pricer.h"

double MCPricer::Price(
    const Option& option,
    double stock_price,
    double vol,
    double rate,
    unsigned long paths
)
{
    double ttl_payoff = 0.0;

    double T = option.GetTimeToExpiration();

    for (unsigned int i = 0; i < paths; ++i)
    {
        double z = BoxMuller();
        double ST = stock_price * exp((rate - vol*vol/2.0)*T + vol*z*sqrt(T));
        double payoff = option.GetExpirationPayoff(ST);
        ttl_payoff += payoff;
    }

    double price = ttl_payoff / paths;

    return price;
}
