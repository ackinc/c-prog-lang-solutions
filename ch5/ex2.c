#include <ctype.h>

#include "getch.c"

// reads next input
// if it is an integer, stores it in ip and returns some +ve number
// if it is EOF, returns EOF
// else returns 0
int getfloat(double *dp) {
    int c, d, sign = 1, power = 1;
    while (isspace(c = getch())) continue;

    if (c == EOF)
        return c;
    else if (!isdigit(c) && c != '-' && c != '+' && c != '.') {
        ungetch(c);
        return 0;
    } else if (!isdigit(c)) {
        d = getch();
        ungetch(d);
        if (!isdigit(d)) {
            ungetch(c);
            return 0;
        }
    }

    if (c == '-') sign = -1;

    if (isdigit(c))
        *dp = c - '0';
    else
        *dp = 0;

    while (isdigit(c = getch())) { *dp = *dp * 10 + c - '0'; }

    if (c == '.') {
        while (isdigit(c = getch())) {
            *dp = *dp * 10 + c - '0';
            power *= 10;
        }
    }

    *dp = *dp / power * sign;
    ungetch(c);
    return c;
}

void main() {
    double x;
    int b;
    while ((b = getfloat(&x)) != 0 && b != EOF) printf("You entered: %f\n", x);
}
