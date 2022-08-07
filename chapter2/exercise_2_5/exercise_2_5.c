#include <stdio.h>

int any(char *s1, char *s2)
{
    /*
     * Because we have 128 symbols in ASCII table,
     * use a htbl hoding 128 ints to record which
     * symbol is in s2.
     */
    int htbl[128] = { 0 };
    for (int i = 0; s2[i] != '\0'; ++i) {
        size_t idx = s2[i];
        htbl[idx] = 1;
    }

    
    for (int i = 0; s1[i] != '\0'; ++i) {
        size_t idx = s1[i];
        if (htbl[idx] == 1) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    char s1[] = "Hello World, I am Edward!";
    char s2[] = "Ea";

    printf("%d\n", any(s1, s2));

    return 0;
}
