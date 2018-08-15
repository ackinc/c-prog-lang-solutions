#include <stdio.h>

void main() {
    int c, prevc = EOF;
    while ((c = getchar()) != EOF) {
        if (prevc == ' ' && c == ' ') continue;
        putchar(c);
        prevc = c;
    }
}
