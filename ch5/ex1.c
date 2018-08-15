#include <ctype.h>

#include "getch.c"

// reads next input
// if it is an integer, stores it in ip and returns some +ve number
// if it is EOF, returns EOF
// else returns 0
int getint(int *ip) {
    int sign = 1;
    int c, d;

    while (isspace(c = getch())) continue; // skip whitespace

    if (c == EOF) {
        return c;
    } else if (!isdigit(c) && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    } else if (c == '+' || c == '-') {
        d = getch();
        ungetch(d);
        if (!isdigit(d)) {
            ungetch(c);
            return 0;
        }
    }

    if (c == '-') sign = -1;

    if (isdigit(c))
        *ip = c - '0';
    else
        *ip = 0;

    while (isdigit(c = getch())) *ip = *ip * 10 + (c - '0');
    ungetch(c);

    *ip *= sign;

    return c;
}

void main() {
    int x, b;
    while ((b = getint(&x)) != 0 && b != EOF) printf("You entered: %d\n", x);
}
