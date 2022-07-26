#include <stdio.h>

#define MAXLEN  (1000)

int mygetline(char *line, int maxlen);

int main(int argc, char *argv[])
{
    char line[MAXLEN];
    int len;

    while ((len = mygetline(line, MAXLEN)) > 0) {
        int i = 0;
        while (i < len && line[i] != '\n') {
            ++i;
        } // end of while-loop
        --i;

        while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) {
            --i;
        }
	line[i + 1] = '\0';

	printf("[%s]\n", line);
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
