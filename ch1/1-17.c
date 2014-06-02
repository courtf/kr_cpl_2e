#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */
#define TARGET  80          /* print lines longer than target */

// 'getLine' with a capital 'L' because 'getline' is defined in the stdlib
int getLine(char line[], int maxline);

main()
{
    int len;                        /* current line length */
    int i, j, k;
    char line[MAXLINE];             /* current input line */
    char eighty[MAXLINE][MAXLINE];  /* keep track of lines over 80 */

    i = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > TARGET) {
            for (j = 0; j < len; ++j) {
                eighty[i][j] = line[j];
            }
            ++i;
        }
    }

    putchar('\n');
    for (k = 0; k < i; ++k) {
        printf("%3d: %s\n", k + 1, eighty[k]);
    }
    return 0;
}

/* getLine:  read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i, limited;

    i = limited = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < (lim - 1)) {
            s[limited] = c;
            ++limited;
        }
    }

    if (c == '\n') {
        if (limited < (lim - 1)) {
            s[limited] = c;
            ++limited;
        }

        ++i;
    }

    s[limited] = '\0';
    return i;
}
