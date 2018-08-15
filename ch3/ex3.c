#include <stdio.h>

void expand (char *src, char *dest) {
    char start, end;
    while ((start = *src) != '\0') {
        if (*(src + 1) == '-' && (end = *(src + 2)) != '\0' && end >= start) {
            // we have found a non-leading and non-trailing '-'
            while (start != end) *dest++ = start++;
            src += 2;
        } else {
            *dest++ = *src++;
        }
    }
    *dest = '\0';
}

void main () {
    char *src = "-a-a-c-z-";
    char dest[] = "SUFFICIENTLY LONG DEST STRING SUFFICIENTLY LONG";
    expand(src, dest);
    printf("%s\n", dest);
}