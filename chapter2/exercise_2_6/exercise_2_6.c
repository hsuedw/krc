#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int y_mask = ~(~0 << n);
    unsigned int shift = p + 1 - n;
    unsigned int x_mask = ~(~(~0 << n) << shift);

    return ((y & y_mask) << shift) | (x & x_mask);
}

int main(int argc, char *argv[])
{
    unsigned int x = 0x12345678;
    unsigned int y = 0xabcdef01;

    printf("x: 0x%x, y: 0x%x\n", x, y);
    printf("Before: 0x%x, After: 0x%x\n", x, setbits(x, 30, 20, y));

    return 0;
}
