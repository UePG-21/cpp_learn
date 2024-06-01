/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/31/21
 */
#ifndef Option_hpp
#define Option_hpp

#include <vector>
#include <string>

using namespace std;

struct OptionData
{
    double r;  // risk-free rate
    double sig;  // valotility
    double K;  // strike price
    double T;  // expiry date
    double b;  // cost of carry
    string optType;  // option type ("C" for call, "P" for put)
};

class Option
{
private:  // variable
    OptionData data;

public:  // function
    Option();  // default constructor
    Option(const OptionData& source);  // constructor
    Option(const Option& source);  // copy constructor
    virtual ~Option();  // destructor

    virtual void toggle() {};  // change option type (C->P, P->C)
};

#endif
