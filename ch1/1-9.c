#include <stdio.h>

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
