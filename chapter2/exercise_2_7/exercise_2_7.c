
#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
    unsigned int mask = ~(~0 << n) << (p - n + 1);
    return x ^ mask;
}

int main(int argc, char *argv[])
{
    unsigned int x = 0x12345678;

    printf("Before: 0x%x, After: 0x%x\n", x, invert(x, 30, 20));

    return 0;
}
