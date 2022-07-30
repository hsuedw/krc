#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

/*
 * Assume s is well formated.
 *  - The characters in s are x, X, a-f, A-F and 0-9.
 *  - The first two characters could be 0x or 0X. (optional)
 *  - s is NUL terminated.
 */
int htoi(char *s, int *answer) {
    char *hex = s;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        hex = s + 2;
    }

    int slen = strlen(s), hexlen = strlen(hex);
    if (hexlen > sizeof(int) * 2) {
        printf("The original data (%s) is too long.\n", s);
        printf("This program can process less than or equal to %ld hex digits.\n", 2 * sizeof(int));
	return -1;
    }

    *answer = 0;

    int base = 1, i = slen - 1, first_idx = slen - hexlen, first_digit;
    while (i >= first_idx) {
        int num;
        if (isalpha(s[i])) {
            num = (s[i] | 0x20) - 'a' + 10;
        } else {
            num = s[i] - '0';
        }
	if (i == first_idx) {
            first_digit = num;
        }

        *answer += base * num;
	base <<= 4;
	--i;
    } // end of while-loop
    if (first_digit & 0x8) {
        *answer = -(UINT_MAX - *answer + 1);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    char s[] = "0xffffffff"; // -1
    //char s[] = "80000000"; // -2147483648
    //char s[] = "7fffffff"; // 2147483647
    //char s[] = "0x0"; // 0
    //char s[] = "0x1"; // 1
    //char s[] = "0x1234"; // 4660
    //char s[] = "0xffff1234"; // -60876

    int answer;
    if (htoi(s, &answer) != 0) {
        printf("%s is invalid.\n", s);
	return -1;
    }
    printf("%d\n", answer);

    return 0;
}
