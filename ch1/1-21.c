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
int entab(char s[], int tabstop, int size);

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
    for (j = 0; j < linecount; ++j) {
        printf("%s", lines[j]);
    }
    linecount = 0;
}

void addLine(int size)
{
    int j, len;

    line[size] = '\0';
    len = entab(line, TABSTOP, (size + 1));
    for (j = 0; j < len; ++j) {
        lines[linecount][j] = line[j];
    }
    ++linecount;
}

/* size should include null termination character */
int entab(char s[], int tabstop, int size)
{
    int c, i, j, pos, len, blanks; 
    len = size;
    pos = blanks = 0;
    for(i = 0; (c = s[i]) != '\0'; ++i) {
        // any spaces not adjacent to a tabstop cannot be
        // replaced with a tab, so any non-blank resets
        // the count of blanks immediately.
        if (c != ' ') {
            blanks = 0;
        }

        if (c == '\n') {
            pos = 0;
        } else if (c == '\t') {
            pos = pos + (tabstop - (pos % tabstop));
        } else if (c == ' ') {
            ++pos;
            ++blanks;

            // we are at a tabstop, see if we can replace
            // any preceding blanks with a tab
            if ((pos % tabstop) == 0) {
                // if there was only 1 preceding blank, leave it as a space
                if (blanks > 1) {
                    s[i - (blanks - 1)] = '\t';

                    // shift the array to the left by 'blanks' - 1
                    for (j = (i + 1); j < len; ++j) {
                        s[j - (blanks - 1)] = s[j];
                    }
                    // we have a new length
                    len = len - (blanks -1);
                    // and we have to move the index itself back too
                    i = i - (blanks - 1);
                }
                // start over counting blanks after the tabstop
                blanks = 0;
            }
        } else {
            ++pos;
        }
    }
    
    return len;
}
