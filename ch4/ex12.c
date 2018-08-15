#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void itoa (int n, char *s) {
    if (n < 0) {
        s[0] = '-';
        n = -n;
        s++;
    }

    int i = 0;
    if (n / 10) {
        itoa(n / 10, s);
        i = strlen(s);
    }

    s[i] = '0' + n % 10;
    s[i + 1] = '\0';
}

void test(int n) {
    char s[MAX_LEN];
    itoa(n, s);
    printf("%d\t\t%s\n", n, s);
}

void main () {
    test(-123);
    test(0);
    test(123);
    test(INT_MAX);
}