/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 11/17/21
 */
#include "Option.hpp"
#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"
#include <vector>
#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"
#include "UtilitiesDJD/ExcelDriver/Utilities.hpp"

using namespace std;

//A global function that produces a mesh array of double separated by a mesh size h
std::vector<double> MeshArray(double start, double end, double h)
{
	vector<double> v;
	for (double i = start; i < end; i = i + h)
	{
		v.push_back(i);
	}
	return v;
}

int main()
{
	auto mesh = MeshArray(1, 100, 1);

	OptionData batch1 = { 0.08, 0.30, 65, 0.25, 0.08, "C" };
	EuropeanOption indexOption1(batch1); //r, sig, K, T

	// Calculate price
	vector<double> vCallPrice = indexOption1.Price(mesh);

	auto y = vCallPrice;

	ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(mesh, y, "Option Pricing Curve");

	return 0;
}
