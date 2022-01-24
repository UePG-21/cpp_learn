/*
 * @Objective: Exchange the value of two variables.
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/05/21
 */

#include <stdio.h>

int main()
{
    double i, j;

    // Swap two numbers
    // p_i - pointer to the first number
    // p_j - pointer to the second number
    void Swap(double* p_i, double* p_j);

    // Ask the user to input two numbers.
    printf("Please input two numbers in the following format:\ni j\n");

    if (scanf("%lf %lf", &i, &j))
    {
        printf("i = %lf, j = %lf.\n", i, j);
        
        // Swap i and j
        Swap(&i, &j);

        printf("If we swap i and j, then i = %lf, j = %lf.\n", i, j);
    }
    else
    {
        printf("Input Error.\n");
    }

    return 0;
}

void Swap(double* p_i, double* p_j)
{
    double temp;

    temp = (*p_i);
    (*p_i) = (*p_j);
    (*p_j) = temp;
}