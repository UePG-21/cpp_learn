#include <stdio.h>

int main()
{
    char input_char;
    int n_zero = 0;
    int n_one = 0;
    int n_two = 0;
    int n_three = 0;
    int n_four = 0;
    int n_others = 0;

    printf("%s", "Please input characters. The input should be halted with ^Z (EOF) in a new line.\n");

    while ((input_char = getchar()) != EOF)
    {
        // calculate the times that each number has been typed
        switch (input_char)
        {
            case '0':
                n_zero++;
                break;
            case '1':
                n_one++;
                break;
            case '2':
                n_two++;
                break;
            case '3':
                n_three++;
                break;
            case '4':
                n_four++;
                break;
            default:
                n_others++;
                break;
        }
    }

    // print the amount of times
    printf("0 has been typed %d times.\n", n_zero);
    printf("1 has been typed %d times.\n", n_one);
    printf("2 has been typed %d times.\n", n_two);
    printf("3 has been typed %d times.\n", n_three);
    printf("4 has been typed %d times.\n", n_four);

	// print the amount of times number 3 has been typed in words
	switch (n_three)
	{
		case 0:
			printf("Number three appears zero time.\n");
			break;
		case 1:
			printf("Number three appears one time.\n");
			break;
		case 2:
			printf("Number three appears two times.\n");
			break;
		default:
			printf("The number three appears more than two times.\n");
			break;
	}

    return 0;
}