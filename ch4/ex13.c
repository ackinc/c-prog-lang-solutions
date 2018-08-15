#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void reverse (char s[]) {
    int len = strlen(s);
    if (len <= 1) return;

    char c = s[0];
    reverse(s + 1);
    strcpy(s, s + 1);
    s[len - 1] = c;
    s[len] = '\0';
}

void test (char *s) {
    char d[MAX_LEN];
    strcpy(d, s);
    reverse(d);
    printf("%s -> %s\n", s, d);
}

void main () {
    test("");
    test("a");
    test("anirudh");
    test("anirudh anirudh");
}