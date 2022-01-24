/*
 * @Objective: Calculate the length of a string.
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/05/21
 */

#include <stdio.h>
#define MAXLINE 30

// String length declaration.
int Length(char* str);

int main()
{
	char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
	int c; // The input character
	int i = 0; // The counter

	// Print intro text.
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

	// Get the characters.
	while ((c = getchar()) != EOF && i < MAXLINE)
	{
		// Append entered character to string.
		string[i++] = (char)c;
	}

	string[i] = '\0'; // String must be closed with \0.

	printf("String length is %d\n", Length(string));

	return 0;
}

int Length(char* str)
{
    int len = 0;  // value for counting the length of the string

    while (*str++ != '\0')
    {
        len++;
    }

    return --len;  // ^Z must appear in a new line, so the \n which is only used for a new line should not be counted. 
}