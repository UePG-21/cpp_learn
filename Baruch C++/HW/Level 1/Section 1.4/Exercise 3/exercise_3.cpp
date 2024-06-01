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

    while ((ASCII = getchar()) != 4)  // if input is not ^D, which ASCII value is 4
    {
        switch (ASCII)
        {
            case 32:  // if input is a space, which ASCII value is 32
                switch (flg_last_is_char)  // if last input is a character
                {
                    case 1:
                        num_words++;  // count as a new word
                        break;
                    default:
                        break;
                }

                flg_last_is_char = false;
                break;

            case 10:  // if input is a new line, which ASCII value is 10
                switch (flg_last_is_char)  // if last input is a character
                {
                    case 1:
                        num_words++;  // count as a new word
                        break;
                    default:
                        break;
                }

                flg_last_is_char = false;
                flg_last_is_line = true;
                break;

            default:  // if input is a character
                num_chars++;  // count as a new character

                switch (flg_last_is_line)  // if last input is a new line
                {
                    case 1:
                        num_lines++;  // count as a new line
                    default:
                        break;
                }

                flg_last_is_char = true;
                flg_last_is_line = false;
                break;
        }
    }

    // at the end of the text
    switch (flg_last_is_char)  // if the last input is a character
    {
        case 1:
            num_words++;  // this also indicates a word
            break;
        default:
            break;
    }

    switch (num_words > 0)  // if the number of the words is over 0
    {
        case 1:
            num_lines++;  // this indicates that we should add a new line because we lost the last line
            break;
        default:
            break;
    }

    printf("In this text,\nthe amount of the characters is %d,\nthe amount of the words is %d,\nthe amount of the lines is %d.\n",
            num_chars, num_words, num_lines);
    
    return 0;
}