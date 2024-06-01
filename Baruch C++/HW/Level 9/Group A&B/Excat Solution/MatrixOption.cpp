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
#include "MatrixOption.hpp"
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

// MatrixOption
MatrixOption::MatrixOption()  // default constructor
{

}

MatrixOption::MatrixOption(const vector<double>& vs, const vector<Option>& vo)  // constructor
{
    vStock = vs;
    vOption = vo;
}

MatrixOption::MatrixOption(const MatrixOption& source)  // copy constructor
{
    vStock = source.vStock;
    vOption = source.vOption;
}

MatrixOption::~MatrixOption()  // destructor
{

}

void MatrixOption::printMatrix(vector<vector<double>> matrix, vector<double> vs)
{
    cout << "Price ";
    for (int i = 0; i < int(vs.size()); i++)
    {
        cout << "    s = " << vs[i];
    }
    cout << endl;

    cout << setiosflags(ios::right) << fixed << setprecision(5);
    for (int i = 0; i < int(matrix.size()); i++)
    {
        cout << "batch" << i + 1;
        for (int j = 0; j < int(matrix[i].size()); j++)
        {
            cout << setw(10) << matrix[i][j];
        }
        cout << endl;
    }
    std::cout.unsetf(std::ios_base::floatfield);
}

void MatrixOption::toggle()  // change opiton type
{
    for (int i = 0; i < int(vOption.size()); i++)
    {
        vOption[i].toggle();
    }
}

// EuropeanMatrixOption
EuropeanMatrixOption::EuropeanMatrixOption()
{

}

EuropeanMatrixOption::EuropeanMatrixOption(const vector<double>& vs, const vector<EuropeanOption>& vo)
{
    vS = vs;
    vE = vo;
}

EuropeanMatrixOption::EuropeanMatrixOption(const EuropeanMatrixOption& source)
{
    vS = source.vS;
    vE = source.vE;
}

EuropeanMatrixOption::~EuropeanMatrixOption()
{

}

double EuropeanMatrixOption::Price(int i, int j) const
{
    return vE[i].Price(vS[j]);
}

vector<vector<double>> EuropeanMatrixOption::Price() const
{
    vector<vector<double>> vm;
    vm.resize(vE.size());

    for (int i = 0; i < int(vE.size()); i++)
    {
        for (int j = 0; j < int(vS.size()); j++)
        {
            vm[i].push_back(this->Price(i, j));
        }
    }

    return vm;
}

double EuropeanMatrixOption::Delta(int i, int j) const
{
    return vE[i].Delta(vS[j]);
}

vector<vector<double>> EuropeanMatrixOption::Delta() const
{
    vector<vector<double>> vm;
    vm.resize(vE.size());

    for (int i = 0; i < int(vE.size()); i++)
    {
        for (int j = 0; j < int(vS.size()); j++)
        {
            vm[i].push_back(this->Delta(i, j));
        }
    }

    return vm;
}

void EuropeanMatrixOption::toggle()
{
    for (int i = 0; i < int(vE.size()); i++)
    {
        vE[i].toggle();
    }
}

// AmericanMatrixOption
AmericanMatrixOption::AmericanMatrixOption()
{

}

AmericanMatrixOption::AmericanMatrixOption(const vector<double>& vs, const vector<AmericanOption>& vo)
{
    vS = vs;
    vA = vo;
}

AmericanMatrixOption::AmericanMatrixOption(const AmericanMatrixOption& source)
{
    vS = source.vS;
    vA = source.vA;
}

AmericanMatrixOption::~AmericanMatrixOption()
{

}

double AmericanMatrixOption::Price(int i, int j) const
{
    return vA[i].Price(vS[j]);
}

vector<vector<double>> AmericanMatrixOption::Price() const
{
    vector<vector<double>> vm;
    vm.resize(vA.size());

    for (int i = 0; i < int(vA.size()); i++)
    {
        for (int j = 0; j < int(vS.size()); j++)
        {
            vm[i].push_back(this->Price(i, j));
        }
    }

    return vm;
}

void AmericanMatrixOption::toggle()
{
    for (int i = 0; i < int(vA.size()); i++)
    {
        vA[i].toggle();
    }
}
