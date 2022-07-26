#include <stdio.h>

#define MAXLEN (4096)

int main(int argc, char *argv[])
{
    /* in_comment is a flag. 1: in comment, 0: not in comment */
    int c1, in_comment = 0, len = 0;
    char source[MAXLEN];
    char *p = source;

    while ((c1 = getchar()) != EOF) {
        *(p++) = c1;
	len++;
    } // end of while-loop

    int i = 0;
    while (i < len) {
        if (i + 1 == len) {
            // source[i] is th last character.
            if (!in_comment) {
                /* We are not in a block comment. source[i] is code. Print it. */
                printf("%c", source[i]);
            }

            /* Finish processing this line */
            break;
	}
 
        if (source[i] == '/' && source[i + 1] == '*' && !in_comment) {
            /* We are going to enter a block comment. */
            i += 2;
	    in_comment = 1;
	} else if (source[i] == '*' && source[i + 1] == '/' && in_comment) {
            /* We are going to leave a block comment. */
            i += 2;
	    in_comment = 0;
	} else {
            if (in_comment) {
                /* We are in a block comment. Get rid of this character. */
                ++i;
            } else {
                /* We are not in a block comment. print this character. */
                printf("%c", source[i]);
      	        ++i;
	    }
        }
    } // end of while-loop

    return 0;
}
