#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */

// 'getLine' with a capital 'L' because 'getline' is defined in the stdlib
int getLine(char line[], int maxline);

/* print longest input line */
main()
{
    int len;                        /* current line length */
    int i, j, k;
    char line[MAXLINE];             /* current input line */
    char trimmed[MAXLINE][MAXLINE];  /* keep track of lines over 80 */

    i = 0;
    while ((len = getLine(line, MAXLINE)) >= 0) {
        // 0 is a valid return (entire line was blank)
        if (len > 0) {
            for (j = 0; j < len; ++j) {
                trimmed[i][j] = line[j];
            }
            ++i;
        }
    }

    putchar('\n');
    for (k = 0; k < i; ++k) {
        printf("%3d: %s\n", k + 1, trimmed[k]);
    }
    return 0;
}

/* getLine:  read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, b, i, blank, limited;

    i = limited = blank = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i == 0 && (c == ' ' || c == '\t')) {
            blank = 1;
            --i;
        } else if (i < (lim - 1)) {
            s[limited] = c;
            ++limited;
        }
    }

    while ((b = s[limited - 1]) == ' ' || b == '\t') {
        --limited;
        --i;
        s[limited] = '\0';
    }

    if (c == '\n' && i > 0) {
        if (limited < (lim - 1)) {
            s[limited] = c;
            ++limited;
        }

        ++i;
    }

    s[limited] = '\0';

    // no length and we didn't remove any blanks
    // this indicates the end of input with a -1.
    if (i == 0 && blank == 0) {
        i = -1;
    }

    return i;
}
