#include <stdio.h>

int main()
{
    int married = NULL;

    // get user's marital status
    printf("Please input 1 if you are married, or 0 if you aren't married.\n");

    if (scanf("%d", &married))
    {
        if (!married || married == 1)  // input is 0 or 1
        {
            printf(married ? "You are married.\n" : "You are not married.\n");
        }
        else  // input is not 0 or 1
        {
            printf("Input Error: The input number must be 0 or 1.\n");
            return 0;
        }
    }
    else  // input is not a number
    {
        printf("Input Error: The input must be a number.\n");
    }
    return 0;
}