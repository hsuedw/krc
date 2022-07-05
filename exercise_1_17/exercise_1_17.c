#include <stdio.h>

#define MAXLEN  (1000)

int mygetline(char *line, int maxlen);

int main(int argc, char *argv[])
{
    char line[MAXLEN];
    int len;

    while ((len = mygetline(line, MAXLEN)) > 0) {
        if (len > 80) {
            printf("%s", line);
	}
    }

    return 0;
}

int mygetline(char *line, int maxlen) {
    int c, i;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
	++i;
    }
    line[i] = '\0';

    return i;
}
