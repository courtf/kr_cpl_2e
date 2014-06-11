#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

unsigned long long htoi(char s[]);

main()
{
    char line[1000];

    int i, c;
    i = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n' || i > MAXLINE - 2) {
            line[i] = '\0';
            printf("%s = %llu\n", line, htoi(line));
            i = 0;
        } else {
            line[i] = c;
            ++i;
        }
    }
}

unsigned long long htoi(char s[])
{
    long long n = 0;
    int i, c, d;
    for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f'); ++i) {
        c = tolower(s[i]);
        if (i == 0 && (s[i] == '0' && tolower(s[i+1]) == 'x')) {
            ++i;
        } else {
            if (c > '9') {
                d = (c - 'a') + 10;
            } else {
                d = c - '0';
            }

            n = n * 16 + d; 
        }
    }

    return n;
}
