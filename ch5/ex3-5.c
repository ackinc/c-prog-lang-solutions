#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 1000

int intMin(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int strLen(char *s) {
    char *p = s;
    while (*p) p++;
    return p - s;
}

void strCpy(char *s, char *d) {
    while (*d++ = *s++) continue;
}

// if we did not have the statement limiting the value of n, then
// if n > strLen(s), and d has just enough space to hold s,
// the last assignment will overwrite un-owned memory
void strNCpy(char *s, char *d, int n) {
    n = intMin(n, strLen(s));
    while (--n >= 0 && (*d++ = *s++)) continue;
    *d = '\0';
}

// appends t to s
// assumes that s is big enough
void strCat(char *s, char *t) {
    s += strLen(s);
    while (*s++ = *t++) continue;
}

void strNCat(char *s, char *t, int n) {
    n = intMin(n, strLen(t));
    s += strLen(s);
    while (--n >= 0) *s++ = *t++;
    *s = '\0';
}

int strCmp(char *s, char *t) {
    while (*s == *t && *t != '\0') { s++, t++; }
    return *s - *t;
}

int strNCmp(char *s, char *t, int n) {
    n = intMin(n, intMin(strLen(s), strLen(t)));
    while (--n >= 0) {
        if (*s == *t)
            s++, t++;
        else
            return *s - *t;
    }
    return 0;
}

// returns true if s ends with t
// false otherwise
// assumed strLen(s) >= strLen(t)
bool strEnd(char *s, char *t) {
    s += strLen(s) - strLen(t);
    return (strCmp(s, t) == 0);
}

void testStrNCat(char *s1, char *s2, int n) {
    char s[MAX_LEN];
    strCpy(s1, s);
    strNCat(s, s2, n);
    printf("%s\n", s);
}

void testStrEnd(char *s1, char *s2) { printf("%d\n", strEnd(s1, s2)); }

void main() {
    testStrNCat("Nimmagadda", "Anirudh", 7);
    testStrNCat("", "Anirdu", 6);
    testStrNCat("", "Anirdu", 3);
    testStrNCat("", "Anirdu", 0);
    testStrNCat("Anird", "", 0);

    testStrEnd("Nimmagadda", "");
    testStrEnd("Nimmagadda", "dda");
    testStrEnd("Nimmagadda", "Nimmagadda");
    testStrEnd("Nimmagadda", "dd");

    printf("%d should be 0\n", strNCmp("anirudh", "anirudh", 0));
    printf("%d should be 0\n", strNCmp("anirudh", "anirudh", 6));
    printf("%d should be 0\n", strNCmp("anirudh", "anirudh", 7));
    printf("%d should be 0\n", strNCmp("anirudha", "anirudh", 7));
    printf("%d should be 0\n", strNCmp("anirudh", "anirudha", 7));

    printf("%d should be -ve\n", strNCmp("anirudha", "anirudhc", 8));
    printf("%d should be +ve\n", strNCmp("anirudhc", "anirudha", 8));

    char s[MAX_LEN];
    char *S = "Anirudh Nimmagadda";
    strNCpy(S, s, 10);
    printf("%s\n", s);
}
