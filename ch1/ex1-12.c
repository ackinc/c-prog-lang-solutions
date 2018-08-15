#include <stdio.h>

int isBlank(char c) { return (c == ' ' || c == '\t' || c == '\n'); }

void main() {
    int c, prevBlank = 0;
    while ((c = getchar()) != EOF) {
        if (!isBlank(c)) {
            putchar(c);
            prevBlank = 0;
        } else if (!prevBlank) {
            putchar('\n');
            prevBlank = 1;
        }
    }
}
