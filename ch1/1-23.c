#include <stdio.h>
#define MAXLINE     1000
#define MAXLINES    MAXLINE

// the current line
char line[MAXLINE + 1];
// keep track of decommented lines for printing all at once
char lines[MAXLINES][MAXLINE + 1];
// keep track of how many lines we have added to 'lines'
int linecount;

void printLines(void);
void addLine(int size);
int decomment(char s[], int size);
int collapse(char s[], int size, int from, int to);
int countLeadingWhitespace(char s[], int from);

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
    len = decomment(line, (size + 1));
    for (j = 0; j < len; ++j) {
        lines[linecount][j] = line[j];
    }
    ++linecount;
}

/* size should include null termination character */
int decomment(char s[], int size)
{
    int c, i, j, len, inString;
    len = size;
    inString = 0;
    for(i = 0; (c = s[i]) != '\0' && i < len; ++i) {
        if ((c == '\"' || c == '\'') && (i - 1 < 0 || s[i - 1] != '\\')) {
            inString = inString ? 0 : 1;
        } else if (c == '/' && s[i + 1] == '/' && !inString) {
            // count the distance to the end of the line
            for (j = i + 2; s[j] != '\n' && s[j] != '\0'; ++j) {}

            len = len - collapse(s, len, j, countLeadingWhitespace(s, i - 1));
        } else if (c == '/' && s[i + 1] == '*' && !inString) {
            // count distance to comment closing
            for (j = i + 2; s[j] != '\0' && !(s[j] == '*' && s[j+1] == '/'); ++j) {}
            j = s[j] == '\0' ? : j + 2;

            len = len - collapse(s, len, j, countLeadingWhitespace(s, i - 1));
        }
    }
    
    return len;
}

int countLeadingWhitespace(char s[], int from)
{
    int i, newlines;
    newlines = 0;
    for (i = from; i >= 0 && (s[i] == ' ' || s[i] == '\n') && newlines < 1; --i) {
        if (s[i] == '\n') {
            ++newlines;
        }
    }
    return i;
}

int collapse(char s[], int size, int from, int to)
{
    int collapse = (from - 1) - to;
    int i;
    if (s[from] == '\0') {
        s[from - collapse] = '\0';
    } else {
        for (i = from; i < size; ++i) {
            s[i - collapse] = s[i];
        }
    }
    return collapse;
}
