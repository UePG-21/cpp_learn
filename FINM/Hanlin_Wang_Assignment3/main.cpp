#include <iostream>
#include "currency_converter.h"

using namespace std;

int test(CurrencyFactory& factory)
{
    // interact
    cout << "Enter a currency you want to exchange from" << endl;
    cout << "(USD, EUR, GBP, CAD, AUD):" << endl;
    string in_symbol;
    cin >> in_symbol;

    cout << "Enter a currency you want to exchange for" << endl;
    cout << "(USD, EUR, GBP, CAD, AUD):" << endl;
    string out_symbol;
    cin >> out_symbol;

    cout << "Enter the amount of the origin currency you have" << endl;
    double in_amount;
    cin >> in_amount;

    // generate CurrencyConverter
    CurrencyConverter converter(factory);

    // report
    double out_amount = converter.OutAmount(in_symbol, out_symbol, in_amount);
    cout << "You will get " << out_amount << " " << out_symbol << endl;

    // exit
    cout << "\nEnter 1 to continue, otherwise to exit" << endl;
    int flag;
    cin >> flag;

    return flag;
}

void repeat(int (*func)(CurrencyFactory&), CurrencyFactory& factory)
{
    int flag = 1;

    while (flag == 1)
    {
        flag = func(factory);
        cout << endl;
    }
}

int main()
{
    CurrencyFactory factory("cpp_learn/Hanlin_Wang_Assignment3/CurrencyRates.txt");

    repeat(test, factory);

    return 0;
}