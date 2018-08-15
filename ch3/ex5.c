#include <limits.h>
#include <stdio.h>

#define MIN_BASE 2
#define MAX_BASE 62

const char *alphabet =
    "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void copyStr(char *src, char *dest, int n) {
    while (*src != '\0' && n > 0) { *dest++ = *src++; }
    *dest = '\0';
}

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

char getChar(int n) { return alphabet[n]; }

void itob(int n, char s[], int base) {
    if (base < MIN_BASE || base > MAX_BASE) return;

    int is_neg = n < 0;
    if (is_neg) n = -n;

    int i = 0;
    do { s[i++] = getChar(n % base); } while ((n /= base) > 0);

    if (is_neg) s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

void test(int numbers[], int len, int base) {
    char dest[] = "A string that is a long enough string";

    printf("Base %d tests\n", base);
    for (int i = 0; i < len; i++) {
        itob(numbers[i], dest, base);
        printf("%16d\t%s\n", numbers[i], dest);
    }
    printf("\n");
}

void main() {
    // TODO: how to handle INT_MIN?
    // TODO: currently handling negative numbers by putting a '-' in front of
    // representation of positive number. Is there a better way?

    int len = 10;
    int numbers[] = {-23423, -35, -1,      0,        1,
                     45,     188, 3489723, 16325235, INT_MAX};

    test(numbers, len, 2);
    test(numbers, len, 8);
    test(numbers, len, 10);
    test(numbers, len, 16);
    test(numbers, len, 55);
}
