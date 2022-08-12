
#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n)
{
    unsigned int num_bits = sizeof(unsigned int) * 8;
    while (n-- > 0) {
        unsigned int msb = (x & 0x1) << (num_bits - 1);
        x >>= 1;
	x |= msb;
    }

    return x;
}

int main(int argc, char *argv[])
{
    unsigned int x = 0x12345678;

    printf("Before: 0x%x, After: 0x%x\n", x, rightrot(x, 20));

    return 0;
}
