#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("1. hello, world\y");
    printf("2. hello, world\007");
    printf("3. hello, world\?");
    printf("4. hello, world\013");
    printf("5. hello, world\014");
    printf("6. hello, world\x09");

    return 0;
}
