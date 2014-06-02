#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */

// 'getLine' with a capital 'L' because 'getline' is defined in the stdlib
int getLine(char line[], int maxline);
void reverse(char s[]);

main()
{
    char line[MAXLINE];     /* current input line */

    while (getLine(line, MAXLINE) > 0) {
        printf("%s\n", line);
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
    reverse(s);
    return i;
}

void reverse(char s[])
{
    int c, i, j, n, m;
    i = 0;
    // get the max index of 's'
    while((c = s[i]) != '\0') {
        ++i;
    }
    --i;

    if (i > 0) {
        j = 0;
        for (; i > j; --i) {
            n = s[j];
            m = s[i];
            s[j] = m;
            s[i] = n;
            ++j;
        }
    }
}
