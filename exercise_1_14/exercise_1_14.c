#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_CHARS (128)
#define MAX_HIST  (20)

int main(int argc, char *argv[]) {
    int cnts[NUM_CHARS];
    memset(cnts, 0, NUM_CHARS * sizeof(int));

    int c, max_cnt = 0;
    while ((c = getchar()) != EOF) {
        if (c < NUM_CHARS) {
            ++cnts[c];
            if (max_cnt < cnts[c]) {
                max_cnt = cnts[c]; 
            }
	}
    } // end of while-loop

    for (int i = 0; i < NUM_CHARS; ++i) {
        int len = 0;
        if (cnts[i] > 0 && (len = cnts[i] * MAX_HIST / max_cnt) < 1) {
            len = 1;
        }
        printf("%d - %c : ", i, i);
	while (len-- > 0) {
            putchar('x');
        }
        printf("\n");
    }

    return 0;
}
