#include <stdio.h>
#define TABSTOP     4
#define MAXLINE     1000
#define MAXLINES    MAXLINE

int detab(char s[], int tabstop, int size);

/* print longest input line */
main()
{
    // the current line
    char line[MAXLINE + 1];
    // keep track of detabbed lines for printing all at once
    char lines[MAXLINES][MAXLINE + 1];

    int c, i, j, linecount, len;
    i = linecount = 0;
    while ((c = getchar()) != EOF) {
        line[i] = c;
        if (c == '\n' || i >= ((MAXLINE / TABSTOP) - 1)) {
            // end of line or input, put down null termination
            line[i + 1] = '\0';
            // detab the current line
            len = detab(line, TABSTOP, (i + 2));
            // start filling up 'line' again from 0
            i = 0;
            
            // copy 'line' into our list of lines
            for (j = 0; j < len; ++j) {
                lines[linecount][j] = line[j];
            }
            ++linecount;

            // we are about to go over the linecount, print what we have so far
            if (linecount >= MAXLINES) {
                for (j = 0; j < linecount; ++j) {
                    printf("%s", lines[j]);
                }

                // start over adding lines
                linecount = 0;
            }
        } else {
            ++i;
        }
    }

    for (j = 0; j < linecount; ++j) {
        printf("%s", lines[j]);
    }
    putchar('\n');

    return 0;
}

/* assume that s has room for tab expansion */
/* size should include null termination character */
int detab(char s[], int tabstop, int size)
{
    int c, i, j, pos, len, spaces;
    len = size;
    pos = 0;
    for(i = 0; (c = s[i]) != '\0'; ++i) {
        if (c == '\n') {
            pos = 0;
        } else if (c == '\t') {
            spaces = tabstop - (pos % tabstop);
            pos = pos + spaces;

            // shift the end of the array by 'spaces' - 1
            for (j = (len - 1); j > i; --j) {
                s[j + spaces - 1] = s[j];
            }
            // we have a new length
            len = len + (spaces - 1);

            // insert spaces into the new gaps
            for (j = i; j < (i + spaces); ++j) {
                s[j] = ' ';
            }
            // we can skip over the next couple of indexes
            i = i + (spaces - 1);
        } else {
            ++pos;
        }
    }
    
    return len;
}
