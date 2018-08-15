#include <stdio.h>

// returns 1 if c is in s, 0 otherwise
int in_str(char c, char *s) {
    while (*s != '\0')
        if (*s++ == c) return 1;
    return 0;
}

int any(char *s1, char *s2) {
    int i;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (in_str(s1[i], s2)) return i;
    }

    return -1;
}

void main() {
    char name[] = "Anirudh";
    printf("%d\n", any(name, "BCD"));
    printf("%d\n", any(name, "idu"));
    printf("%d\n", any(name, "hdurinA"));
}
