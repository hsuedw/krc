#include <stdio.h>
#include <ctype.h>

int lower(int c)
{
    c = islower(c) ? c & ~0x20 : c;
    return c;
}

int main(int argc, char *argv[])
{
    printf("a ==> %c\n", lower('a'));
    printf("A ==> %c\n", lower('A'));
    printf("? ==> %c\n", lower('?'));

    return 0;
}
