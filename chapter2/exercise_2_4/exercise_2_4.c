#include <stdio.h>

void squeeze(char *s1, char *s2)
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

    int m = 0, n = 0;
    while (s1[n] != '\0') {
        size_t idx = s1[n];
        if (htbl[idx] == 0) {
            s1[m++] = s1[n++];
        } else {
            ++n;
	}
    }
    s1[m] = '\0';
}

int main(int argc, char *argv[])
{
    char s1[] = "Hello World, I am Edward!";
    char s2[] = "lo,d";

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}
