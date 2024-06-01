/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/31/21
 */
#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include "Option.hpp"

using namespace std;

class EuropeanOption : public Option
{
private:  // variable
    OptionData data;

private:  // function
    void init();  // initialise all default values

    // cdf and pdf of naormal distribution
    double N(double x) const;
    double n(double x) const;

    // pricing functions
    double CallPrice(double S) const;
    double PutPrice(double S) const;

    // delta functions
    double CallDelta(double S) const;
    double PutDelta(double S) const;

public:  // funtion
    EuropeanOption();  // default constructor
    EuropeanOption(const OptionData& od);  // constructor 1
    EuropeanOption(const string& optionType);  // constructor 2
    EuropeanOption(const EuropeanOption& option);  // copy constructor
    virtual ~EuropeanOption();  // destructor

    EuropeanOption& operator = (const EuropeanOption& option);  // assignment overloading

    double Price(double S) const;  // option price
    double Delta(double S) const;  // option delta

    // parity checking
    void Parity1(const EuropeanOption& eo, const double S);  // calculate the call (or put) price for a corresponding put (or call) price
    void Parity2(const double call, const double put, const double S);  // check if a given set of put/call price satisfy parity

    // vector manipulation
    vector<double> Price(vector<double> S) const;
    vector<double> Delta(vector<double> S) const;

    // matrix manipulation
    vector<vector<double>> CallPrice(vector<vector<double>> param, vector<double> S);
    vector<vector<double>> PutPrice(vector<vector<double>> param, vector<double> S);

    // gamma function
    double Gamma(double S) const; // call and put option have the same gamma

    // numerical methods to calculate greeks
    double NumericalDelta(double S, double h) const;
    double NumericalGamma(double S, double h) const;

    // change option type (C->P, P->C)
    virtual void toggle();
};

#endif
