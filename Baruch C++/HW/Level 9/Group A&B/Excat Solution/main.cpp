/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/01/21
 */
#include "Option.hpp"
#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"
#include "MatrixOption.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// function for producing mesh array
vector<double> MeshArray(double start, double end, double h)
{
    vector<double> v;

    for (double i = start; i < end; i += h)
    {
        v.push_back(i);
    }

    return v;
}

int main()
{
    // Test
    cout << "Test" << endl;

    OptionData batch0 = { 0.04, 0.4, 120.0, 1.0, 0.04, "P"};  // r, sig, K, T, b, Type
    EuropeanOption EuropeanOption0(batch0);
    cout << "The put option's price of batch 0 is " << EuropeanOption0.Price(100.0) << endl;
    cout << "The put option's Delta of batch 0 is " << EuropeanOption0.Delta(100.0) << endl;
    cout << "The put option's Gamma of batch 0 is " << EuropeanOption0.Gamma(100.0) << endl;
    cout << endl;

    // # GROUP A: EXACT SOLUTIONS
    cout << "# GROUP A: EXACT SOLUTIONS" << endl << endl;

    // ============================== a) Options Pricing ==============================
    cout << "a) Options Pricing" << endl << endl;

    // batch 1
    OptionData batch1 = { 0.08, 0.30, 65.0, 0.25, 0.08, "C" };
    EuropeanOption EuropeanOption1(batch1);
    cout << "The call option's price of batch 1 is " << EuropeanOption1.Price(60.0) << endl;
    EuropeanOption1.toggle();  // change it to a put
    cout << "The put option's price of batch 1 is " << EuropeanOption1.Price(60.0) << endl;
    EuropeanOption1.toggle();  // change it back to a call for the next use of it

    // batch 2
    OptionData batch2 = { 0.0, 0.2, 100.0, 1.0, 0.0, "C" };
    EuropeanOption EuropeanOption2(batch2);
    cout << "The call option's price of batch 2 is " << EuropeanOption2.Price(100.0) << endl;
    EuropeanOption2.toggle();  // change it to a put
    cout << "The put option's price of batch 2 is " << EuropeanOption2.Price(100.0) << endl;
    EuropeanOption2.toggle();  // change it back to a call for the next use of it

    // batch 3
    OptionData batch3 = { 0.12, 0.50, 10.0, 1.0, 0.12, "C" };
    EuropeanOption EuropeanOption3(batch3);
    cout << "The call option's price of batch 3 is " << EuropeanOption3.Price(5.0) << endl;
    EuropeanOption3.toggle();  // change it to a put
    cout << "The put option's price of batch 3 is " << EuropeanOption3.Price(5.0) << endl;
    EuropeanOption3.toggle();  // change it back to a call for the next use of it

    // batch 4
    OptionData batch4 = { 0.08, 0.30, 100.0, 30.0, 0.08, "C"};
    EuropeanOption EuropeanOption4(batch4);
    cout << "The call option's price of batch 4 is " << EuropeanOption4.Price(100.0) << endl;
    EuropeanOption4.toggle();  // change it to a put
    cout << "The put option's price of batch 4 is " << EuropeanOption4.Price(100.0) << endl;
    EuropeanOption4.toggle();  // change it back to a call for the next use of it

    cout << endl;

    // ============================== b) Check Put-Call Parity ==============================
    cout << "b) Check Put-Call parity" << endl << endl;

    // method 1
    EuropeanOption1.Parity1(EuropeanOption1, 60.0);

    // method 2
    double call1 = EuropeanOption1.Price(60.0);
    EuropeanOption1.toggle();
    double put1 = EuropeanOption1.Price(60.0);
    EuropeanOption1.Parity2(call1, put1, 60.0);
    EuropeanOption1.toggle();

    cout << endl;

    // ============================== c) Option Prices for Different Values of S ==============================
    cout << "c) Option Prices for Different Values of S" << endl << endl;

    // make a vector of S
    double start = 10;
    double end = 50;
    double h = 1;
    vector<double> v = MeshArray(start, end, h);

    // calculate and print the price
    vector<double> vPrice = EuropeanOption1.Price(v);

    typename vector<double>::iterator it;

    cout << "call price of batch 1 is ";
    for (it = vPrice.begin(); it != vPrice.end(); it++)
    {
        cout << "  " << *it;
    }
    cout << endl << endl;

    // ============================== d) Option Prices for Matrix ==============================
    cout << "d) Option Prices for matrix" << endl << endl;

    vector<EuropeanOption> vEuropeanOption;  // matrix of option parameteres

    vEuropeanOption.push_back(EuropeanOption1);
    vEuropeanOption.push_back(EuropeanOption2);
    vEuropeanOption.push_back(EuropeanOption3);
    vEuropeanOption.push_back(EuropeanOption4);

    EuropeanMatrixOption mEuropeanOption(v, vEuropeanOption);

    vector<vector<double>> mEprice = mEuropeanOption.Price();

    cout << "Call price" << endl;
    mEuropeanOption.printMatrix(mEprice, v);

    cout << endl << endl;

    // # GROUP A: SENSATIVITIES
    cout << "# GROUP A: SENSATIVITIES" << endl << endl;

    // ============================== a) Greeks ==============================
    cout << "a) Greeks" << endl << endl;

    // delta
    OptionData greeksData = { 0.1, 0.36, 100.0, 0.5, 0, "C" };
    EuropeanOption greeksOption(greeksData);
    cout << "Exact delta call " << greeksOption.Delta(105) << endl;
    greeksOption.toggle();
    cout << "Exact delta put " << greeksOption.Delta(105) << endl;
    greeksOption.toggle();

    // gamma
    cout << "Exact gamma " << greeksOption.Gamma(105) << endl;

    cout << endl;

    // ============================== b) Delta for Different Values of S ==============================
    cout << "b) Delta fot Different Values of S" << endl << endl;

    vector<double> vCallDelta = EuropeanOption1.Delta(v);

    cout << "Calll delta of batch1: ";
    for (int i = 1; i < int(vCallDelta.size()); i++)
    {
        cout << vCallDelta[i] << ",";
    }
    cout << endl << endl;

    // ============================== c) Deltas for Matrix ==============================
    cout << "c) Deltas fot Matrix" << endl << endl;

    cout << "Call Delta" << endl;
    mEuropeanOption.printMatrix(mEuropeanOption.Delta(), v);
    mEuropeanOption.toggle();
    cout << "Put Delta" << endl;
    mEuropeanOption.printMatrix(mEuropeanOption.Delta(), v);
    mEuropeanOption.toggle();
    cout << endl;

    // ============================== d) Numerical Method ==============================
    cout << "d) Numerical Method" << endl << endl;

    // Delta
    double h1 = 0.001;
    double h2 = 0.01;

    double numericalDelta1 = greeksOption.NumericalDelta(105, h1);
    double numericalDelta2 = greeksOption.NumericalDelta(105, h2);
    double delta = greeksOption.Delta(105);

    cout << "When h = 0.001, call delta = " << fixed << setprecision(10) << numericalDelta1 << endl;
    cout << "When h = 0.01, call delta = " << fixed << setprecision(10) << numericalDelta2 << endl;
    cout << "Exact call delta = " << fixed << setprecision(10) << delta << endl;

    if (abs(numericalDelta1 - delta) < abs(numericalDelta2 - delta))
    {
        cout << "Smaller values of h produce better approximation." << endl;
    }
    else
    {
        cout << "Larger values of h produce better approximations." << endl;
    }

    // Gamma
    double numericalGamma1 = greeksOption.NumericalGamma(105, h1);
    double numericalGamma2 = greeksOption.NumericalGamma(105, h2);
    double gamma = greeksOption.Gamma(105);

    cout << "When h = 0.001, gamma = " << fixed << setprecision(10) << numericalGamma1 << endl;
    cout << "When h = 0.01, gamma = " << fixed << setprecision(10) << numericalGamma2 << endl;
    cout << "Exact gamma = " << fixed << setprecision(10) << gamma << endl;

    if (abs(numericalGamma1 - gamma) < abs(numericalGamma2 - gamma))
    {
        cout << "Smaller values of h produce better approximation." << endl;
    }
    else
    {
        cout << "Larger values of h produce better approximation." << endl;
    }

    cout << endl << endl;

    // # GROUP B
    cout << "# GROUP B" << endl << endl;

    // ============================== b) Test the Delta ==============================
    cout << "b) Test the Delta" << endl << endl;

    OptionData batch5 = { 0.1, 0.1, 100.0, 0.0, 0.02, "C" };
    AmericanOption AmericanOption1 = AmericanOption(batch5);

    cout << "The price of call option is " << setprecision(5) << AmericanOption1.Price(110) << endl;
    AmericanOption1.toggle();
    cout << "The price of put option is " << AmericanOption1.Price(110) << endl;
    AmericanOption1.toggle();

    cout << endl;

    // ============================== c) Prices for Different Values of S ==============================
    cout << "c) Prices for Different Values of S" << endl << endl;

    // create a vector of S
    vector<double> vA1CallPrice = AmericanOption1.Price(v);
    // print the price vector
    typename vector<double>::iterator cit;
    cout << "Call price of batch1: ";
    for (cit = vA1CallPrice.begin(); cit != vA1CallPrice.end(); cit++)
    {
        cout << " " << *cit;
    }
    cout << endl;

    cout << endl;

    // ============================== d) Prices for Matrix ==============================
    cout << "d) Prices for Matrix" << endl << endl;

    // American Option doesn't have expiry time so set it 0
    OptionData batch6 = { 0.1, 0.2, 90.0, 0.0, 0.02, "C" };
    AmericanOption AmericanOption2(batch6);
    OptionData batch7 = { 0.2, 0.1, 50.0, 0.0, 0.01, "C" };
    AmericanOption AmericanOption3(batch7);
    OptionData batch8 = { 0.2, 0.4, 50.0, 0.0, 0.01, "C" };
    AmericanOption AmericanOption4(batch8);

    vector<AmericanOption> vAmericanOption;

    vAmericanOption.push_back(AmericanOption1);
    vAmericanOption.push_back(AmericanOption2);
    vAmericanOption.push_back(AmericanOption3);
    vAmericanOption.push_back(AmericanOption4);

    AmericanMatrixOption mAmericanOption(v, vAmericanOption);
    vector<vector<double>> mAprice = mAmericanOption.Price();

    cout << "Call price" << endl;
    mAmericanOption.printMatrix(mAprice, v);
    mAmericanOption.toggle();

    return 0;
}
