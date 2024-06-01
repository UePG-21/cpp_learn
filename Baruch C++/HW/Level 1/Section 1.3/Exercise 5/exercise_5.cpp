#include <stdio.h>

int main()
{
    long int i = NULL;  // number input
    long int original_i = NULL;  // record of number input
    long int i_minus_minus = NULL;  // i--
    long int minus_minus_i = NULL;  // --i

    // get number input
    printf("Please input an integer as the value of i.\n");

    if (scanf("%ld", &i))
    {
        // record i in original_i
        original_i = i;

        // i_minus_minus = i, then i = i - 1
        i_minus_minus = i--;

        // recover the value of i
        i = original_i;

        // i = i - 1, then i_minus_minus = i
        minus_minus_i = --i;

        // print
        printf("i equals to %ld.\nIf we assign i-- to IMM, then IMM equals to %ld.\nOr if we assign --i to MMI, then MMI equals to %ld.\nIn both cases, the value of i becomes to %ld", original_i, i_minus_minus, minus_minus_i, i);
    }
    else
    {
        printf("Input Error.\n");
        return 0;
    }
    return 0;
}