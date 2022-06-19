#include <stdio.h>

#define IN  (1)  // inside a word
#define OUT (0)  // outside a word
#define MAXWORD	(15) // the max length of a word
#define MAXHIST (20)

int main(int argc, char *argv[])
{
    int c, wl = 0;    // wl is the length of a word.
    int state = OUT;  // state indicates if we are inside a word
    int ovflow = 0;   // ovflow is the number of words whose lengths are greater than MAXWORD.
    int wordLens[MAXWORD];
    for (int i = 0; i < MAXWORD; ++i) {
        // Initialize all the counters.
        wordLens[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c== '\n') {
            state = OUT;
            if (wl > 0) {
                if (wl < MAXWORD) {
                    ++wordLens[wl];
                } else {
		    // The length of a word is greater than MAXWORD.
                    ++ovflow;
                }
                wl = 0; // reset the length of a word
	    }
        } else if (state == OUT) {
            // We find a new word.
            state = IN;
	    wl = 1;
        } else {
            // We are inside a word and count the length of this word.
            ++wl;
	}
    } // end of while-loop

    int maxLen = 0;
    for (int i = 0; i < MAXWORD; ++i) {
        if (maxLen < wordLens[i]) {
            maxLen = wordLens[i];
        }
    }

    for (int i = 0; i < MAXWORD; ++i) {
        printf("%5d - %5d : ", i, wordLens[i]);
	int len;
        if (wordLens[i] > 0) {
	    // We have statistics int wordLens[i].
            if ((len = wordLens[i] * MAXHIST / maxLen) <= 0) {
                // However, the statistics in wordLens[i] is too low.
                len = 1;
            }
        } else {
            len = 0;
        }
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    } // end of for-loop
    if (ovflow > 0) {
        printf("%d words >= %d", ovflow, MAXWORD);
    }

    return 0;
}
