#include <stdio.h>

int main(int argc, char *argv[])
{
    int c, last_char = 'x';
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
	} else if (last_char != ' ') {
	    putchar(c);
	}
	last_char = c;
    }

    return 0;
}
