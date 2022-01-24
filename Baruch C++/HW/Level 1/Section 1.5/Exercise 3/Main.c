#include <stdio.h>
#include "Print.c"

int main()
{
    double i;

    // get the input number
    printf("Please input a number.\n");

    if (scanf("%lf", &i))
    {
        // if the user input a number, call print() to multiplies it by 2 and print the result 
        print(i);
    }

    return 0;
}