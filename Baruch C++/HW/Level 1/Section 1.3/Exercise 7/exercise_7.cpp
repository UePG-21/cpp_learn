#include <stdio.h>

int main()
{
    long long int num_input;
    long long int num_power;

    // get number to be multiplied
    printf("Please input the integer to be multiplied.\n");

    if (!scanf("%lld", &num_input))
    {
        printf("Input Error: The number is not an integer.\n");
        return 0;
    }

    // get the value of the power
    printf("Please input the power.\n");

    if (!scanf("%lld", &num_power))
    {
        printf("Input Error: The number is not an interger.\n");
        return 0;
    }

    // print the result of num_input * 2^num_power
    printf("Mutiply %lld by a factor 2 to the power %lld, we can get %lld.\n",
            num_input, num_power, (num_input << num_power));
    return 0;
}