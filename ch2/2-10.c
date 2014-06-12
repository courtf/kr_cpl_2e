#include <stdio.h>
#define MAXLINE 1000

int lower(int c);

main()
{
    int c;
    while((c = getchar()) != EOF) {
        if (c != '\n') {
            printf("\nlowered:%c\n", lower(c));
        }
    }
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
