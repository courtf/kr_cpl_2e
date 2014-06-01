#include <stdio.h>

main()
{
    int c, i, j;
    int freqs[7];

    for (i = 0; i < 7; ++i) {
        freqs[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'g') {
            ++freqs[c - 'a'];
        }
    }

    for (i = 0; i < 7; ++i) {
        int bar = freqs[i];
        
        putchar(i + 'a');
        putchar('|');
        for (j = 0; j < bar; ++j) {
            putchar(']');
        }
        putchar('\n');
    }
}
