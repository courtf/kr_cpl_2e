#include <stdio.h>

main()
{
    int c;

    // this is wacky because the book hasn't introduced
    // the `else` statement yet
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        
        if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }

        if (!(c == '\t')) {
            if (!(c == '\b')) {
                if (!(c == '\\')) {
                    putchar(c);
                }
            }
        }
    }
}
