#include <stdio.h>

int main() {
    int c, cnt = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            ++cnt;
	    if (cnt == 1) {
                printf(" ");
	    }
	    continue;
        }
	cnt = 0;
	printf("%c", c);
    }

    return 0;
}
