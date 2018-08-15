#include <limits.h>
#include <stdio.h>

int strLen(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void reverse(char s[]) {
    int i = 0, j = strLen(s) - 1, tmp;
    while (i < j) {
        tmp = s[i], s[i] = s[j], s[j] = tmp;
        i++, j--;
    }
}

void addOneLToR(char number[]) {
    int i = 0;
    while (number[i] == '9') number[i++] = '0';

    if (number[i] == '\0') {
        number[i++] = '1';
        number[i] = '\0';
    } else {
        number[i] = '0' + ((number[i] - '0') + 1);
    }
}

void itoa(int n, char s[]) {
    int is_min_int, is_neg;

    is_min_int = n == INT_MIN;
    if (is_min_int) n += 1;

    is_neg = n < 0;
    if (is_neg) n = -n;

    int i = 0;
    do { s[i++] = '0' + n % 10; } while ((n /= 10) > 0);

    s[i] = '\0';
    if (is_min_int) addOneLToR(s);

    if (is_neg) {
        s[i++] = '-';
        s[i] = '\0';
    }

    reverse(s);
}

void test(int n, char dest[]) {
    itoa(n, dest);
    printf("%d %s\n", n, dest);
}

void main() {
    char dest[] = "A SUFFICIENTLY LONG STRING";
    test(0, dest);
    test(-1, dest);
    test(981, dest);
    test(-981, dest);
    test(INT_MAX, dest);
    test(INT_MIN, dest);
}
