#include <stdio.h>

void lower (char *s) {
    while (*s != '\0') {
        *s = (*s >= 'A' && *s <= 'Z') ? 'a' + *s - 'A' : *s;
        s++;
    }
}

void main () {
    char name[] = "Anirudh";
    printf("%s\n", name);

    lower(name);
    printf("%s\n", name);
}