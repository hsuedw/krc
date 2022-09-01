#include <stdio.h>

#define MAXLINE (1024)

void escape(char *s, size_t s_maxline, char *t)
{
    int i, j;
    for (i = 0, j = 0; t[i] != '\0' && j + 1 < s_maxline; ++i) {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

void unescape(char *s, size_t s_maxline, char *t)
{
    int i = 0, j = 0;
    while (t[i] != '\0' && j + 1 < s_maxline) {
        switch (t[i]) {
        case '\\':
            switch (t[i + 1]) {
            case 'n':
                s[j++] = '\n';
		i += 2;
                break;
            case 't':
                s[j++] = '\t';
		i += 2;
                break;
            default:
                s[j++] = t[i++];
                break;
            }
            break;
        default:
            s[j++] = t[i++];
            break;
        }
    }

}

int main(int argc, char *argv[])
{
    int c;
    size_t i = 0;
    char s1[MAXLINE], s2[MAXLINE];

    printf("Test escape():\n");
    while ((c = getchar()) != EOF && i + 1 < MAXLINE) {
        s2[i++] = c;
    }
    s2[i] = '\0';
    escape(s1, MAXLINE, s2);
    printf("\ts1: %s\n", s1);
    printf("\ts2: %s\n", s2);

    printf("Test unescape():\n");
    unescape(s2, MAXLINE, s1);
    printf("\ts1: %s\n", s1);
    printf("\ts2: %s\n", s2);

    return 0;
}
