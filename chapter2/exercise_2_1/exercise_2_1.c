#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    printf("The range of signed char: %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("The range of signed short: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("The range of signed int: %d ~ %d\n", INT_MIN, INT_MAX);
    printf("The range of signed long: %ld ~ %ld\n", LONG_MIN, LONG_MAX);

    printf("The range of unsigned char: 0 ~ %u\n", UCHAR_MAX);
    printf("The range of signed short: 0 ~ %u\n", USHRT_MAX);
    printf("The range of signed int: 0 ~ %u\n", UINT_MAX);
    printf("The range of signed long: 0 ~ %lu\n", ULONG_MAX);
    
    return 0;
}
