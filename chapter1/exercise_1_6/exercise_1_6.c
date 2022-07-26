#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;

    while(c = getchar() != EOF) {
        printf("in while-loop: %d\n", c);
    }
    printf("out of while-loop: %d\n", c);

    return 0;
}
