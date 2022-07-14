#include <stdio.h>

#define TABINC (8)

int main(int argc, char *argv[])
{
    int c, nb = 0, nt = 0;

    for (int pos = 1; (c = getchar()) != EOF; ++pos) {
        if (c == ' ') {
            if (pos % TABINC != 0) {
                ++nb;
            } else {
                nb = 0;
                ++nt;
	    }
	} else {
            while (nt > 0) {
                putchar('\t');
                --nt;
            }
            if (c == '\t') {
                nb = 0;
            } else {
                while (nb > 0) {
                    putchar(' ');
                    --nb;
		}
            }
            putchar(c);
            if (c == '\n') {
                pos = 0;
            } else if (c == '\t') {
                pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
            }
        }
    }

    return 0;
}
