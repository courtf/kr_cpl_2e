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
void syntaxCheck(char s[]);
void printMissing(int line, int col, char missing[]);
void printNoMatch(int line, int col, char extra[]);

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
        syntaxCheck(lines[j]);
    }
    linecount = 0;
}

void addLine(int size)
{
    int j;
    line[size] = '\0';
    for (j = 0; j < size; ++j) {
        lines[linecount][j] = line[j];
    }
    ++linecount;
}

void printMissing(int line, int col, char missing[])
{
    printf("\nline: %5d col: %4d\nMissing: \"%s\"\n", line, col, missing);
}

void printNoMatch(int line, int col, char extra[])
{
    printf("\nline: %5d col: %4d\nNo Matching: \"%s\"\n", line, col, extra);
}

void syntaxCheck(char s[])
{
    int c, i, j, curlies, squares, parens, inString, ln, col;
    ln = 1;
    curlies = squares = parens = inString = col = 0;
    for(i = 0; (c = s[i]) != '\0'; ++i) {
        ++col;
        if (c == '\n') {
            col = 0;
            ++ln;
        }

        if ((c == '\"' || c == '\'') && (i - 1 < 0 || s[i - 1] != '\\')) {
            inString = inString ? 0 : 1;
        }
        
        if (!inString) {
            if (c == '/' && s[i + 1] == '/') {
                // count the distance to the end of the line
                for (j = i + 2; s[j] != '\n' && s[j] != '\0'; ++j) {}
                i = j - 1;
            } else if (c == '/' && s[i + 1] == '*') {
                // count distance to comment closing
                for (j = i + 2; s[j] != '\0' && !(s[j] == '*' && s[j+1] == '/'); ++j) {
                    ++col;
                    if (s[j] == '\n') {
                        col = 0;
                        ++ln;
                    }
                }
                if (s[j] == '\0') {
                    printMissing(ln, col, "*/");
                } else {
                    ++col;
                }
                i = s[j] == '\0' ? j : j + 1;
            } else if (c == '[') {
                ++squares;
            } else if (c == ']') {
                --squares;
                if (squares < 0) {
                    printNoMatch(ln, col, "[");
                    squares = 0;
                }
            } else if (c == '(') {
                ++parens;
            } else if (c == ')') {
                --parens;
                if (parens < 0) {
                    printNoMatch(ln, col, "(");
                    parens = 0;
                }
            } else if (c == '{' || c == '}' || c == ';' || s[i+1] == '\0') {
                if (squares > 0) {
                    printMissing(ln, col, "]");
                    squares = 0;
                }

                if (parens > 0) {
                    printMissing(ln, col, ")");
                    parens = 0;
                }

                if (s[i+1] == '\0') {
                    if (curlies > 0) {
                        printMissing(ln, col, "}");
                        curlies = 0;
                    }
                } else if (c == '{') {
                    ++curlies;
                } else if (c == '}') {
                    --curlies;
                    if (curlies < 0) {
                        printNoMatch(ln, col, "{");
                        curlies = 0;
                    }
                }
            }
        }
    }
}
