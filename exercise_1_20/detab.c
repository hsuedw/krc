#include <stdio.h>

#define TAB_SZ (8)

int main(int argc, char *argv[])
{
    printf("01234567890123456789012345678901234567890123456789\n");

    int c, pos = 1; 
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TAB_SZ - (pos - 1) % TAB_SZ;
            while(spaces > 0) {
                putchar(' ');
                ++pos;
                --spaces;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
