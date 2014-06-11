#include <stdio.h>
#define MAXLINE  1000

main()
{
    char line[MAXLINE];
    int c, i, lim, shouldBreak;
    lim = MAXLINE;
    shouldBreak = 0;
    // this is whacky because the `break` statement has not yet been introduced
    for (i = 0; !shouldBreak; ++i) {
        if (i >= lim-1) {
            shouldBreak = 1;
        } else if ((c = getchar()) == EOF) {
            shouldBreak = 1;
        } else if (c == '\n') {
            shouldBreak = 1;
        } else {
            line[i] = c;
        }
    }

    line[i] = '\0';

    printf("%s\n", line);
}
