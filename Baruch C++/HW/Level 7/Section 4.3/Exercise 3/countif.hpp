/*
 * @Objective:
 *
 * @Author: Hanlin WANG
 *
 * @Version: 1.0
 * @Date: 10/26/21
 */
using namespace std;

bool lessThan(double a)
{
    return a < 4;
}

class LessThan
{
private:
    double m_number;

public:
    LessThan() : m_number(0) {};  // default constructor
    LessThan(double n) : m_number(n) {};
    ~LessThan() {};

    bool operator () (double a)
    {
        return a < m_number;
    }
};
