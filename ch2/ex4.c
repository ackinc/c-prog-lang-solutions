#include <stdio.h>

// returns 1 if c is in s, 0 otherwise
int in_str(char c, char *s) {
    while (*s != '\0')
        if (*s++ == c) return 1;
    return 0;
}

// deletes any char in s1 that also occurs in s2
char *squeeze(char *s1, char *s2) {
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        s1[j] = s1[i];
        if (!in_str(s1[i], s2)) j++;
    }
    s1[j] = '\0';
    return s1;
}

void main() {
    char name[] = "Anirudh";
    printf("%s\n", squeeze(name, "BCD"));
    printf("%s\n", squeeze(name, "idu"));
    printf("%s\n", squeeze(name, "hdurinA"));
}
