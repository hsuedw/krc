/*
 * We represent x in binary and ? represents either 1 or 0.
 *
 * case 1: 
 * Assume x = ????..?1, then x - 1 = ???..?0
 * Therefore, x & (x - 1) = ???..?0
 *
 * case 2:
 * Assume x = ???..?10..00, then x - 1 = ???..?01..11
 * Therefore, x & (x - 1) = ???..?00..00
 *
 * From case 1 and 2, we can conclude that x & (x - 1) deletes the 
 * right-most 1-bit in x.
 */
 
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned int x = 0x12345678, y, cnt = 0;

    y = x;
    while (x) {
        x &= x - 1;
	++cnt;
    }
    printf("0x%x has %d 1s.\n", y, cnt);

    return 0;
}
