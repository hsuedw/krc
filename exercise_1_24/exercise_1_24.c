#include <stdio.h>

int brace = 0, bracket = 0, paren = 0;

void in_quote(int c);
void in_comment();
void search(int c);

int main(int argc, char *argv[])
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if ((c = getchar()) == '*') {
               in_comment(); 
            } else {
	        search(c);
	    }
        } else if (c == '\'' || c == '"') {
            in_quote(c);
        } else {
            search(c);
        }

        if (brace < 0) {
            printf("Unbalanced braces\n");
            brace = 0;
        } else if (bracket < 0) {
            printf("Unbalanced brackets\n");
            brace = 0;
        } else if (paren < 0) {
            printf("Unbalanced brackets\n");
            brace = 0;
        }
    } // end of while-loop
    if (brace > 0) {
        printf("Unbalanced braces\n");
    } else if (bracket > 0) {
        printf("Unbalanced brackets\n");
    } else if (paren > 0) {
        printf("Unbalanced brackets\n");
    }
    getchar();

    return 0;
}

void search(int c)
{
    if (c == '{') {
        ++brace;
    } else if (c == '}') {
        --brace;
    } else if (c == '[') {
        ++bracket;
    } else if (c == ']') {
        --bracket;
    } else if (c == '(') {
        ++paren;
    } else if (c == ')') {
        --paren;
    } 
}

void in_comment()
{
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d != '/') {
        c =d;
	d = getchar();
    }
}

void in_quote(int c)
{
    int d;
    while ((d = getchar()) != c) {
        if (d == '\\') {
            getchar();
	}
    }
}


