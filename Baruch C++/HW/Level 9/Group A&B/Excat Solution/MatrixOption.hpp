/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/01/21
 */
#ifndef MatrixOption_hpp
#define MatrixOption_hpp

#include "Option.hpp"
#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"

using namespace std;

class MatrixOption : public Option
{
private:  // variable
    vector<double> vStock;
    vector<Option> vOption;

public:  // function
    MatrixOption();  // default constructor
    MatrixOption(const vector<double>& vs, const vector<Option>& vo);  // constructor
    MatrixOption(const MatrixOption& source);  // copy constructor
    virtual ~MatrixOption();  // destructor

    void printMatrix(vector<vector<double>> matrix, vector<double> vs);
    virtual void toggle();  // change opiton type
};

class EuropeanMatrixOption : public MatrixOption
{
private:
    vector<double> vS;
    vector<EuropeanOption> vE;

public:
    EuropeanMatrixOption();
    EuropeanMatrixOption(const vector<double>& vs, const vector<EuropeanOption>& vo);
    EuropeanMatrixOption(const EuropeanMatrixOption& source);
    virtual ~EuropeanMatrixOption();

    double Price(int i, int j) const;
    vector<vector<double>> Price() const;

    double Delta(int i, int j) const;
    vector<vector<double>> Delta() const;

    virtual void toggle();
};

class AmericanMatrixOption : public MatrixOption
{
private:
    vector<double> vS;
    vector<AmericanOption> vA;

public:
    AmericanMatrixOption();
    AmericanMatrixOption(const vector<double>& vs, const vector<AmericanOption>& vo);
    AmericanMatrixOption(const AmericanMatrixOption& source);
    virtual ~AmericanMatrixOption();

    double Price(int i, int j) const;
    vector<vector<double>> Price() const;

    virtual void toggle();
};

#endif
