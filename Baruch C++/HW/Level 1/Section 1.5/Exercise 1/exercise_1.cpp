#include <stdio.h>

int main()
{
    double num_1 = NULL;
    double num_2 = NULL;

    double minus(double num_1, double num_2);

    // get two numbers input
    printf("Please input two numbers in the following format: number_1 number_2.\n");

    if (scanf("%lf %lf", &num_1, &num_2))
    {
        // if the input is in required format, call minus() and print the difference of the two numbers
        printf("%lf minus %lf equals to %lf.\n", num_1, num_2, minus(num_1, num_2));
    }
    else
    {
        printf("Input Error.\n");
    }

    return 0;
}

double minus(double num_1, double num_2)
{
    return num_1 - num_2;
}