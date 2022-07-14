#include <stdio.h>

#define MAXCOL (10)
#define TABINC (8)

char line[MAXCOL];
int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

int main(int argc, char *argv[])
{
    int c, pos =0;

    while ((c = getchar()) != EOF) {
        line[pos] = c;
        if (c == '\t') {
            pos = exptab(pos);
        } else if (c == '\n') {
            printl(pos);
            pos = 0;
        } else if (++pos >= MAXCOL) {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }

    return 0;
}

void printl(int pos)
{
    for (int i = 0; i < pos; ++i) {
        putchar(line[i]); 
    }
    if (pos > 0) {
        putchar('\n');
    }
}

int exptab(int pos)
{
    line[pos] = ' ';
    ++pos;
    while (pos < MAXCOL && pos % TABINC != 0) {
        line[pos] = ' ';
        ++pos;
    }

    if (pos < MAXCOL) {
        // The current line is not full.
        return pos;
    }

    // The current line is full.
    printl(pos); 
    return 0;
    
}

int findblnk(int pos)
{
    while (pos > 0 && line[pos] != ' ') {
        --pos;
    }
    if (pos == 0) {
        // no blanks in this line
        return MAXCOL;
    }

    // At least one blank in this line.
    // Return the position after the blank.
    return pos + 1;
}

int newpos(int pos)
{
    if (pos <= 0 || pos >= MAXCOL) {
        return 0;
    }

    int i = 0;
    for (int j = pos; j < MAXCOL; ++j, ++i) {
        line[i] = line[j];
    }
    return i;
}
