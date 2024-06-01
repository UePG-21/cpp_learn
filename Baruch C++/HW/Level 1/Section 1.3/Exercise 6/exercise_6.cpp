#include <stdio.h>

int main()
{
    long long int i;
    long long int i_right_shift_2;

    printf("Please input an integer.\n");

    if (scanf("%lld", &i))
    {
        // get i shifted
        i_right_shift_2 = i >> 2;
        
        printf("Shift %lld two places to the right, then it becomes to %lld.\n", i, i_right_shift_2);
        printf("An arithmetic shift is performed.\n");
    }
    else
    {
        printf("Input Error: Input is not an integer.\n");
        return 0;
    }
    return 0;
}