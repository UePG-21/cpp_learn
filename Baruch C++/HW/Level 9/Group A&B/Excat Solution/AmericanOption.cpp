/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/01/21
 */
#include "Option.hpp"
#include "AmericanOption.hpp"
#include <vector>
#include <cmath>

using namespace std;

void AmericanOption::init()
{
    data.r = 0.05;
    data.sig = 0.2;
    data.K = 110.0;
    data.T = 0;
    data.b = data.r;  // Black–Scholes stock option model
    data.optType = "C";  // default type is call option
}

double AmericanOption::CallPrice(double S) const
{
    double tmp1 = data.b / pow(data.sig, 2) - 0.5;
    double y1 = -tmp1 + sqrt(pow(tmp1, 2) + 2.0 * data.r / pow(data.sig, 2));

    if (y1 == 1.0)
    {
        return S;
    }

    double tmp2 = ((y1 - 1.0) * S) / (y1 * data.K);
    double C = data.K * pow(tmp2, y1) / (y1 - 1.0);

    return C;
}

double AmericanOption::PutPrice(double S) const
{
    double tmp1 = data.b / pow(data.sig, 2) - 0.5;
	double y2 = -tmp1 - sqrt(pow(tmp1, 2) + 2.0 * data.r / pow(data.sig, 2));

	if (y2 == 0.0)
    {
        return S;
    }

	double tmp2 = ((y2 - 1.0) * S) / (y2 * data.K);
	double P = data.K * pow(tmp2, y2) / (1.0 - y2);

	return P;
}

AmericanOption::AmericanOption()  // default constructor
{
    init();
}

AmericanOption::AmericanOption(const OptionData& od)  // constructor 1
{
    data = od;
}

AmericanOption::AmericanOption(const string& optionType)  // construction 2
{
    init();
    data.optType = optionType;
}

AmericanOption::AmericanOption(const AmericanOption& option)  // copy constructor
{
    data = option.data;
}

AmericanOption::~AmericanOption()  // destructor
{

}

AmericanOption& AmericanOption::operator = (const AmericanOption& option)  // assignment overloading
{
    if (this == &option)
    {
        return *this;
    }

    this->data = option.data;
    return *this;
}

double AmericanOption::Price(double S) const  // option price
{
    if (data.optType == "C")
    {
        return CallPrice(S);
    }
    else
    {
        return PutPrice(S);
    }
}

vector<double> AmericanOption::Price(vector<double> S) const
{
    vector<double> v;
    vector<double>::iterator it;

    if (data.optType == "C")
    {
        for (it = S.begin(); it != S.end(); it++)
        {
            v.push_back(CallPrice(*it));
        }
    }
    else
    {
        for (it = S.begin(); it != S.end(); it++)
        {
            v.push_back(PutPrice(*it));
        }
    }

    return v;
}

void AmericanOption::toggle()
{
    if (data.optType == "C")
    {
        data.optType = "P";
    }
    else
    {
        data.optType = "C";
    }
}
