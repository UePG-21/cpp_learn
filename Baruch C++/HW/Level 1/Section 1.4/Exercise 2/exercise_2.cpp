#include <stdio.h>

int main()
{
    int ASCII = NULL;  // ASCII-value of the character
    int num_chars = 0;  // number of the characters
    int num_words = 0;  // number of the words
    int num_lines = 0;  // number of the lines
    bool flg_last_is_char = false;  // true when last input is a character, but false when not
    bool flg_last_is_line = false;  // true when last input is a new line, but false when not

    printf("Please input text, with the end of which is Ctrl+D.\n");

    do
    {

        if (ASCII == 32)  // if input is a space, which ASCII value is 32
        {
            if (flg_last_is_char)  // if last input is a character
            {
                num_words++;  // count as a new word
            }

            flg_last_is_char = false;
        }
        else if (ASCII == 10)  // if input is a new line, which ASCII value is 10
        {
            if (flg_last_is_char)  // if last input is a character
            {
                num_words++;  // count as a new word
            }

            flg_last_is_char = false;
            flg_last_is_line = true;
        }
        else  // if input is a character
        {
            num_chars++;  // count as a new character

            if (flg_last_is_line)  // if last input is a new line
            {
                num_lines++;  // count as a new line
            }

            flg_last_is_char = true;
            flg_last_is_line = false;
        }
    }
    while ((ASCII = getchar()) != 4);  // if input is not ^D, which ASCII value is 4

    // at the end of the text
    if (flg_last_is_char)  // if the last input is a character
    {
        num_words++;  // this also indicates a word
    }

    if (num_words > 0)  // if the number of the words is over 0
    {
        num_lines++;  // this indicates that we should add a new line because we lost the last line
    }

    printf("In this text,\nthe amount of the characters is %d,\nthe amount of the words is %d,\nthe amount of the lines is %d.\n",
            num_chars, num_words, num_lines);

    return 0;
}
