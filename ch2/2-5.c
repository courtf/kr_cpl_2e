#include <stdio.h>
#define MAXLINE 1000

int any(char s1[], char s2[]);

main()
{
    char line[1000];
    char s2[] = "qwerty";

    int i, c;
    i = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n' || i > MAXLINE - 2) {
            line[i] = '\0';
            printf("%d\n", any(line, s2)); 
            i = 0;
        } else {
            line[i] = c;
            ++i;
        }
    }
}

int any(char s1[], char s2[])
{
    int i, j, pos, loopBreak;
    loopBreak = 0;
    pos = -1;
    for (i = 0; !loopBreak && s1[i] != '\0'; i++) {
        for (j = 0; !loopBreak && s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                loopBreak = 1;
                pos = i;
            }
        }
    }
    return pos;
}
