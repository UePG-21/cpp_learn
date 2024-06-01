#include <stdio.h>

int main()
{
    double base = NULL;
    double height = NULL;
    double surface = NULL;

    // get base and height input
    printf("The base and the height of the triangle are: (base height)\n");

    if (scanf("%lf %lf", &base, &height))
    {
        if (base > 0 && height > 0)
        {
            // both positive
            surface = base * height / 2;
            printf("The surface of this triangle is %lf.\n", surface);
        }
        else
        {
            // at least one is not positive
            printf("Input Error.\n");
            return 0;
        }
    }
    else
    {
        // type wrong
        printf("Input Error.\n");
        return 0;
    }
    return 0;
}