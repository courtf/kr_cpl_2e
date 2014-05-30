#include <stdio.h>

#define PREV_CHAR_BLANK = 1
#define PREV_CHAR_CHAR = 0

main()
{
    int c;
    int prevChar;

    while ((c = getchar()) != EOF) {
        if (!(c == ' ')) {
            putchar(c);
        }

        if (c == ' ') {
            if (!(prevChar == ' ')) {
                putchar(c);
            }
        }

        prevChar = c;
    }
}
