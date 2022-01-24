#include <stdio.h>

int main()
{
    long long int num = NULL;

    long long int factorial(long long int num);

    // get a natural number
    printf("Please input a natural number.\n");

    if (scanf("%lld", &num) >= 0)
    {
        if (factorial(num) == 0)
        {
            // if the result is too big for the long long int to store, factorial() returns 0.
            printf("Your number is too big for this program to calculate. The number should smaller than 21.\n");
        }
        else
        {
            // otherwise, print the result.
            printf("The factorial of %lld is %lld.\n", num, factorial(num));
        }
    }
    else
    {
        printf("Input Error.\n");
    }

    return 0;
}

long long int factorial(long long int num)
{
    if (num == 0)
    {
        // 0! = 1
        return 1;
    }
    else if (num > 20)
    {
        // 21! = 51090942171709440000, which is bigger than the maximum value that long long int can store
        return 0;
    }
    else
    {
        // call recursive function
        return num * factorial(num - 1);
    }
}