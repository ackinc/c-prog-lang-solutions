#include <stddef.h>
#include <stdio.h>

int strLen(char *s) {
    char *p = s;
    while (*p != '\0') p++;
    return p - s;
}

void test(char *s) { printf("%s -> %d\n", s, strLen(s)); }

void main() {
    test("");
    test("a");
    test("anirudh");
}
