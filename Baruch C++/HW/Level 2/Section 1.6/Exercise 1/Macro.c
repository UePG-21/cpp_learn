/*
 * @Objective: Print two variables using macros
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
    double a, b;

    // Ask the user to input a and b.
    printf("Please input two numbers using the following format:\na b\n");

    if (scanf("%lf %lf", &a, &b))
    {
        // Print variable a.
        PRINT1(a, b);

        // Print variable a and b.
        PRINT2(a, b);
    }
    else
    {
        printf("Input Error.\n");
    }

    return 0;
}