#include <stdio.h>

int main(int argc, char *argf[])
{
    int cb = 0, ct = 0, cn = 0, c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++cb;
	} else if (c == '\t') {
            ++ct;
	} else if (c == '\n') {
            ++cn;
	}
    }
    printf("cb: %d, ct: %d, cn: %d\n", cb, ct, cn);

    return 0;
}
