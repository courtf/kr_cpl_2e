#include <stdio.h>
#define MAXLINE 1000

void squeeze(char s1[], char s2[]);

main()
{
    char line[1000];
    char s2[] = "qwerty";

    int i, c;
    i = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n' || i > MAXLINE - 2) {
            line[i] = '\0';
            squeeze(line, s2);
            printf("%s\n", line); 
            i = 0;
        } else {
            line[i] = c;
            ++i;
        }
    }
}

void squeeze(char s1[], char s2[])
{
    int i, j, k, breakJ;
    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = breakJ = 0; !breakJ && s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                breakJ = 1;
            }
        }

        if (!breakJ) {
            s1[k++] = s1[i]; 
        }
    }

    s1[k] = '\0';
}
