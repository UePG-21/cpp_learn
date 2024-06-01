/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/01/21
 */
#ifndef AmericanOption_hpp
#define AmericanOption_hpp

#include "Option.hpp"

using namespace std;

class AmericanOption : public Option
{
private:  // variable
    OptionData data;

private:  // function
    void init();  // initialise all default values
    double CallPrice(double S) const;  // call price
    double PutPrice(double S) const;  // put price

public:  // function
    AmericanOption();  // default constructor
    AmericanOption(const OptionData& od);  // constructor 1
    AmericanOption(const string& optionType);  // construction 2
    AmericanOption(const AmericanOption& option);  // copy constructor
    virtual ~AmericanOption();  // destructor

    AmericanOption& operator = (const AmericanOption& option);  // assignment overloading

    double Price(double S) const;  // option price
    vector<double> Price(vector<double> S) const;  // vector manipulations
    virtual void toggle();  // change option type (C->P, P->C)
};

#endif
