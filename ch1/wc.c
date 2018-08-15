#include <stdio.h>

#define IN 1
#define OUT 0

int isWhitespace(char c) { return (c == ' ' || c == '\t' || c == '\n'); }
int isNumber(char c) { return (c >= '0' && c <= '9'); }
void main() {
    int c, state = OUT;
    int ndigits[10];
    int nwhite = 0, nother = 0;
    int nc = 0, nl = 0, nb = 0, nt = 0, nw = 0;

    for (int i = 0; i < 10; i++) ndigits[i] = 0;

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == ' ') nb++;
        if (c == '\t') nt++;
        if (c == '\n') nl++;
        if (isWhitespace(c)) {
            state = OUT;
            nwhite++;
        } else if (state == OUT) {
            state = IN;
            nw++;
        }

        if (isNumber(c)) {
            ndigits[c - '0']++;
        } else {
            nother++;
        }
    }
    printf("\n");
    printf("# chars: %d\n", nc);
    printf("# blanks: %d\n", nb);
    printf("# tabs: %d\n", nt);
    printf("# words: %d\n", nw);
    printf("# lines: %d\n", nl);

    printf("digits:");
    for (int i = 0; i < 10; i++) printf(" %d", ndigits[i]);
    printf(", whitespace: %d, other chars: %d\n", nwhite, nother);
}
