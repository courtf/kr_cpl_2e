#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX 128   /* the maximum number of words for one input */

main()
{
    int c, i, j, state, total;
    int wordSizes[MAX + 1];

    i = 0;
    state = OUT;
    printf("Enter no more than %d words at a time.\n", MAX);

    while (((c = getchar()) != EOF) && (i <= MAX)) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else {
            if (state == OUT) {
                state = IN;
                wordSizes[i] = 0;
                ++i;
            }
            
            ++wordSizes[i - 1];
        }
    }

    total = i;
    for (i = 0; i < total; ++i) {
        int bar = wordSizes[i];

        putchar('|');
        for (j = 0; j < bar; ++j) {
            putchar(']');
        }
        putchar('\n');
    }
}
