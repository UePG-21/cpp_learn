/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/29/21
 */
#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Tell compiler which namespace
    using namespace boost::math;

    // Exponential
    cout << "********Exponential********" << endl;
    double scaleParameter = 0.5;

    // Default type is "double"
    exponential_distribution<> myExponential(scaleParameter);
    cout << "exp(2)" << endl;
    cout << "Mean: " << mean(myExponential) << ", Standard deviation: " << standard_deviation(myExponential) << endl;

    // Distributional properties
    double x = 2.5;
    cout << "pdf: " << pdf(myExponential, x) << endl;
    cout << "cdf: " << cdf(myExponential, x) << endl;
    cout << endl;

    // Choose another data type and now exp(1) variate
    exponential_distribution<float> myExponential2;
    cout << "exp(1)" << endl;
    cout << "Mean: " << mean(myExponential2) << ", Standard deviation: " << standard_deviation(myExponential2) << endl;

    cout << "pdf: " << pdf(myExponential2, x) << endl;
    cout << "cdf: " << cdf(myExponential2, x) << endl;
    cout << endl;

    // Choose precision
    cout.precision(10);  // number of values behind the comma

    // Other properties
    cout << "properties of exp(2)" << endl;
    cout << "mean: " << mean(myExponential) << endl;
    cout << "variance: " << variance(myExponential) << endl;
    cout << "median: " << median(myExponential) << endl;
    cout << "mode: " << mode(myExponential) << endl;
    cout << "kurtosis excess: " << kurtosis_excess(myExponential) << endl;
    cout << "kurtosis: " << kurtosis(myExponential) << endl;
    cout << "characteristic function: " << chf(myExponential, x) << endl;
    cout << "hazard: " << hazard(myExponential, x) << endl;
    cout << endl;

    // Poisson
    cout << "********Poisson********" << endl;
    double mean = 3.0;
    poisson_distribution<double> myPoisson(mean);
    cout << "Poisson(3)" << endl;
    cout << "Mean: " << myPoisson.mean() << ", standard deviation: " << standard_deviation(myPoisson) << endl;

    double d = 10.0;
    cout << "pdf: " << pdf(myPoisson, d) << endl;
    cout << "cdf: " << cdf(myPoisson, d) << endl;

    // pdf and cdf with step 0.25
    vector<double> pdfList;
    vector<double> cdfList;

    double start = 0.0;
    double end = 10.0;
    long N = 50;  // number of subdicisions

    double val = 0.0;
    double step = (end - start) / double(N);

    for (long j = 1; j <= N; j++)
    {
        pdfList.push_back(pdf(myPoisson, val));
        cdfList.push_back(cdf(myPoisson, val));
        val += step;
    }

    // Print value in two list
    cout << endl << "pdf List: " << endl;
    for (long j = 0; j < long(pdfList.size()); j++)  // .size() return an unsigned number, resulting in a comparison warning
    {
        cout << pdfList[j] << ", ";
    }

    cout << "..." << endl;

    cout << endl << "cdf List: " << endl;
    for (long j = 0; j < long(cdfList.size()); j++)  // .size() return an unsigned number, resulting in a comparison warning
    {
        cout << cdfList[j] << ", ";
    }

    cout << "..." << endl;

    return 0;
}

