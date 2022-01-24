#include <stdio.h>
#include <math.h>

int main()
{
	long long int num = NULL;  // the integer input

	void printnumber(long long int num);

	// get an integer.
	printf("Please input an integer.\n");
	
	if (scanf("%lld", &num))
	{
		// if the user inputs an integer, call printnumber() to print the number digit by digit.
		printnumber(num);
	}
	else
	{
		printf("Input Error.\n");
	}

    return 0;
}

void printnumber(long long int num)
{
	// if the integer input is negative, print a "-".
	if (num < 0)
	{
		// get the absolute value of integer_number.
		num = -num;
		putchar('-');
		putchar('\n');
	}

	long long int temp_num = num;  // store the original value of integer_number
	long long int count_digit = 0;  // the number of total digits
	long long int next_num = 1;  // the number returned aftering deleting the most significant digit from integer_number
	
	// calculate the number of total digits
	while (temp_num / 10 != 0)
	{
		temp_num /= 10;
		count_digit++;
	}
	
	// print the most significant digit of integer_number
	putchar(temp_num + 48);
	putchar('\n');

	if (count_digit == 0)
	{		
		// if integer_number only has one digit, stop printing
		return;
	}
	else
	{
		// get the number after changing all the digits of integer_number to 0
		// except the most significant digit of it
		for (long long int i = 0; i < count_digit; i++)
		{
			next_num *= 10;
		}

		// set the number left after deleting the most significant digit from integer_number to next_integer_number
		next_num = num % next_num;

		// call the recursive function to print next_integer_number
		printnumber(next_num);
	}
}