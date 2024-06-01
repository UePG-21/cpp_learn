/*
 * @Objective: Print the day of a given day-number.
 * 
 * @Author: Hanlin WANG
 * 
 * @Version: 1.0
 * @Date: 10/05/21
 */

#include <stdio.h>

int main()
{
    int day_num = 0;  // day-number input

    // Print the day of a given day-number
    void DayName(int day_num);

    // Ask the user to input the day-number.
    printf("Please input a day number: (a integer from 1 to 7).\n");

    if (scanf("%d", &day_num))
    {
        // Call DayName to print the day number and day name.
        DayName(day_num);
    }
    else
    {
        printf("Input Error.\n");
    }

    return 0;
}

void DayName(int day_num)
{
    // Creat an array of strings. String itself is also an array, so we need a two-dimensional array.
    char day_name[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Print the day name.
    printf("Day %d is a %s.\n", day_num, day_name[day_num - 1]);
}