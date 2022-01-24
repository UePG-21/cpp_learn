/*
 * @Objective: Get the maximum value of the two numbers using macro MAX2.
               Get the maximum value of the three numbers using macro MAX3.
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/05/21
 */

#include <stdio.h>
#include "Defs.h"

int main()
{
    double a, b, c;

    // Ask the user to input three numbers.
    printf("Please input three numbers in the following format:\na b c\n");

    if (scanf("%lf %lf %lf", &a, &b, &c))
    {
        // Print the maximum value of a and b by using MAX2.
        printf("The maximum value of %lf and %lf is %lf.\n", a, b, MAX2(a, b));

        // Print the maximum value of a, b and c by using MAX3.
        printf("The maximum value of %lf, %lf and %lf is %lf.\n", a, b, c, MAX3(a, b, c));
    }
    else
    {
        printf("Input Error.\n");
    }

    return 0;
}