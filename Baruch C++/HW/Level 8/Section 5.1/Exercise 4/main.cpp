/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/29/21
 */

#include <iostream>
#include <ctime>
#include <map>
#include <boost/random.hpp>
#include <boost/random/detail/const_mod.hpp>

using namespace std;

int main()
{
    // Throwing dice
    // Mersenne Twister
    boost::random::mt19937 myRng;

    // Set the seed
    myRng.seed(static_cast<boost::uint32_t>(std::time(0)));
    // Uniform in range [1, 6]
    boost::random::uniform_int_distribution<int> six(1, 6);

    map<int, long>  statistics;  // structure to hold outcome and frequencies
    int outcome;  // current outcome

    for (int i = 1; i < 7; i++)
    {
        statistics[i] = 0;
    }

    cout << "How many trials? 1000000" << endl;

    int trial = 1000000;
    for (int i = 0; i < trial; i++)
    {
        outcome = six(myRng);
        statistics[outcome]++;
    }

    for (int i = 1; i < 7; i++)
    {
        cout << "Trial " << i << " has " << statistics[i] * 100.0 / trial << "% outcomes." << endl;
    }

    return 0;
}
