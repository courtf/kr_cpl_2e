#include <stdio.h>
#define TABSTOP     4
#define MAXLINE     1000
#define MAXLINES    MAXLINE

// the current line
char line[MAXLINE + 1];
// keep track of detabbed lines for printing all at once
char lines[MAXLINES][MAXLINE + 1];
// keep track of how many lines we have added to 'lines'
int linecount;

void printLines(void);
void addLine(int size);
int detab(char s[], int tabstop, int size);

main()
{
    int c, i, j;
    i = linecount = 0;
    while ((c = getchar()) != EOF) {
        line[i] = c;
        if (i >= ((MAXLINE / TABSTOP) - 1)) {
            addLine(i + 1);
            // start filling up 'line' again from 0
            i = 0;

            // if we are about to go over the linecount, print what we have so far
            if (linecount >= MAXLINES) {
                printLines();
            }
        } else {
            ++i;
        }
    }

    // add any remaining characters to the list
    if (i > 0) {
        addLine(i);
    }

    printLines();
    putchar('\n');

    return 0;
}

void printLines()
{
    int j;
    for (j = 0; j < linecount; ++j) {
        printf("%s", lines[j]);
    }
    linecount = 0;
}

void addLine(int size)
{
    int j, len;

    line[size] = '\0';
    len = detab(line, TABSTOP, (size + 1));
    for (j = 0; j < len; ++j) {
        lines[linecount][j] = line[j];
    }
    ++linecount;
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
