#include "utils.h"

double cdf(double x)
{
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double pdf(double x)
{
    return exp(-0.5 * pow(x, 2)) / sqrt(2 * PI);
}

double BoxMuller()
{
    double x = static_cast<double>(rand()) / RAND_MAX;
    double y = static_cast<double>(rand()) / RAND_MAX;
    return sqrt(-2.0 * log(x)) * cos(2 * PI * y);
}
