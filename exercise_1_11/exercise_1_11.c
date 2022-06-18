#include <stdio.h>

#define IN  (1) // inside a word
#define OUT (0) // outside a word

int main(int argc, char *argv[]) {
    int c, state = OUT, nc = 0, nw = 0, nl = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
	if (c == '\n') {
            ++nl;
	} else if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
	} else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("nl: %d, nw: %d, nc: %d\n", nl, nw, nc);

    return 0;
}
