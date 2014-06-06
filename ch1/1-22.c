#include <stdio.h>
#define MAXLINE     1000
#define MAXLINES    MAXLINE
#define FOLD        100

// the current line
char line[MAXLINE + 1];
// keep track of detabbed lines for printing all at once
char lines[MAXLINES][MAXLINE + 1];
// keep track of how many lines we have added to 'lines'
int linecount;

void printLines(void);
void addLine(int size);
int fold(char s[], int fold, int size);

main()
{
    int c, i, j;
    i = linecount = 0;
    while ((c = getchar()) != EOF) {
        line[i] = c;
        i++;
        if (i > MAXLINE) {
            addLine(i);
            // start filling up 'line' again from 0
            i = 0;

            // if we are about to go over the linecount, print what we have so far
            if (linecount >= MAXLINES) {
                printLines();
            }
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
    printf("\n\nOutput:\n");
    for (j = 0; j < linecount; ++j) {
        printf("%s", lines[j]);
    }
    linecount = 0;
}

void addLine(int size)
{
    int j, len;

    line[size] = '\0';
    len = fold(line, FOLD, (size + 1));
    for (j = 0; j < len; ++j) {
        lines[linecount][j] = line[j];
    }
    ++linecount;
}

/* size should include null termination character */
/* assume that s has room for all newlines to be added */
int fold(char s[], int fold, int size)
{
    int c, i, j, pos, len; 
    len = size;
    pos = 0;
    for(i = 0; (c = s[i]) != '\0'; ++i) {
        if (c == '\n') {
            pos = 0;
        } else if (pos >= fold) {
            // shift the array to the right by 1
            for (j = len; j >= i; --j) {
                s[j] = s[j - 1];
            }
            s[i] = '\n';
            pos = 0;
            ++len;
        } else {
            ++pos;
        }
    }
    
    return len;
}
