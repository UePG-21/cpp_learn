/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/31/21
 */
#include "Option.hpp"
#include "EuropeanOption.hpp"
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void EuropeanOption::init()  // initialise all default values
{
    data.r = 0.05;
    data.sig = 0.2;
    data.K = 110.0;
    data.T = 0.5;
    data.b = data.r;  // Black–Scholes stock option model
    data.optType = "C";  // default type is call option
}

double EuropeanOption::N(double x) const
{
    boost::math::normal_distribution<> myNormal(0.0, 1.0);
    return cdf(myNormal, x);
}

double EuropeanOption::n(double x) const
{
    boost::math::normal_distribution<> myNormal(0.0, 1.0);
    return pdf(myNormal, x);
}

double EuropeanOption::CallPrice(double S) const
{
    double d1 = (log(S / data.K) + (data.b + data.sig * data.sig * 0.5) * data.T) / (data.sig * sqrt(data.T));
    double d2 = d1 - data.sig * sqrt(data.T);

    return S * exp((data.b - data.r) * data.T) * N(d1) - data.K * exp(-data.r * data.T) * N(d2);
}

double EuropeanOption::PutPrice(double S) const
{
    double d1 = (log(S / data.K) + (data.b + data.sig * data.sig * 0.5) * data.T) / (data.sig * sqrt(data.T));
	double d2 = d1 - data.sig * sqrt(data.T);

	return -S * exp((data.b - data.r) * data.T) * N(-d1) + data.K * exp(-data.r * data.T) * N(-d2);
}

double EuropeanOption::CallDelta(double S) const
{
    double d1 = (log(S / data.K) + (data.b + data.sig * data.sig * 0.5) * data.T) / (data.sig * sqrt(data.T));

    return exp((data.b - data.r) * data.T) * N(d1);
}

double EuropeanOption::PutDelta(double S) const
{
    double d1 = (log(S / data.K) + (data.b + data.sig * data.sig * 0.5) * data.T) / (data.sig * sqrt(data.T));

    return exp((data.b - data.r) * data.T) * (N(d1) - 1.0);
}

EuropeanOption::EuropeanOption()  // default constructor
{
    init();
}

EuropeanOption::EuropeanOption(const OptionData& od)  // constructor 1
{
    data = od;
}

EuropeanOption::EuropeanOption(const string& optionType)  // constructor 2
{
    init();
    data.optType = optionType;
}

EuropeanOption::EuropeanOption(const EuropeanOption& option)  // copy constructor
{
    data = option.data;
}

EuropeanOption::~EuropeanOption()  // destructor
{

}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option)  // assignment overloading
{
    if (this == &option)
    {
        return *this;
    }

    this->data = option.data;
    return *this;
}

double EuropeanOption::Price(double S) const  // option price
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

double EuropeanOption::Delta(double S) const  // option delta
{
    if (data.optType == "C")
    {
        return CallDelta(S);
    }
    else
    {
        return PutDelta(S);
    }
}

void EuropeanOption::Parity1(const EuropeanOption& eo, const double S)  // calculate the call (or put) price for a corresponding put (or call) price
{
    if (eo.data.optType == "C")
    {
        double call_price = eo.Price(S);
        double put_price = call_price + data.K * exp(-data.r * data.T) - S;
        cout << "By parity, the put price should be " << put_price << endl;

        EuropeanOption tmp(eo);
        tmp.toggle();
        cout << "While the put price is " << tmp.Price(S) << endl;

        if (abs(put_price - tmp.Price(S)) < 0.000001)
        {
            cout << "Parity is satisfied" << endl;
        }
        else
        {
            cout << "Parity is not satisfied" << endl;
        }
    }
    else
    {
        double put_price = eo.Price(S);
        double call_price = put_price - data.K * exp(-data.r * data.T) + S;
        cout << "By parity the call price should be " << call_price << endl;

        EuropeanOption tmp(eo);
        tmp.toggle();
        cout << "While the call price is " << tmp.Price(S) << endl;

        if (abs(call_price - tmp.Price(S)) < 0.000001)
        {
            cout << "Parity is satisfied" << endl;
        }
        else
        {
            cout << "Parity is not satisfied" << endl;
        }
    }
}

void EuropeanOption::Parity2(const double call, const double put, const double S)  // check if a given set of put/call price satisfy parity
{
    if (call + data.K * exp(-data.r * data.T) - put - S < 0.000001)
    {
        cout << "Parity is satisfied" << endl;
    }
    else
    {
        cout << "Parity is not satisfied"  << endl;
    }
}

vector<double> EuropeanOption::Price(vector<double> S) const
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

vector<double> EuropeanOption::Delta(vector<double> S) const
{
    vector<double> v;
    vector<double>::iterator it;

    if (data.optType == "C")
    {
        for (it = S.begin(); it != S.end(); it++)
        {
            v.push_back(CallDelta(*it));
        }
    }
    else
    {
        for (it = S.begin(); it != S.end(); it++)
        {
            v.push_back(PutDelta(*it));
        }
    }

    return v;
}

vector<vector<double>> EuropeanOption::CallPrice(vector<vector<double>> param, vector<double> S)
{
    vector<vector<double>> m;
    for (int i = 0; i < int(param.size()); i++)
    {
        data = { param[i][0], param[i][1], param[i][2], param[i][3], param[i][4], data.optType };
        m.push_back(Price(S));
    }

    return m;
}

vector<vector<double>> EuropeanOption::PutPrice(vector<vector<double>> param, vector<double> S)
{
    vector<vector<double>> m;

    for (int i = 0; i < int(param.size()); i++)
    {
        data = { param[i][0], param[i][1], param[i][2], param[i][3], param[i][4], data.optType };
        m.push_back(Price(S));
    }

    return m;
}

double EuropeanOption::Gamma(double S) const // call and put option have the same gamma
{
    double tmp = data.sig * sqrt(data.T);
    double d1 = (log(S / data.K) + (data.b + data.sig * data.sig * 0.5) * data.T) / tmp;

    return (n(d1) * exp((data.b - data.r) * data.T)) / (S * tmp);
}

double EuropeanOption::NumericalDelta(double S, double h) const
{
    return (Price(S + h) - Price(S - h)) / (2 * h);
}

double EuropeanOption::NumericalGamma(double S, double h) const
{
    return (Price(S + h) - 2 * Price(S) + Price(S - h)) / (h * h);
}

void EuropeanOption::toggle()
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
