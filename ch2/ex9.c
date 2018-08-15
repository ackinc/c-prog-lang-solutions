#include <stdio.h>

unsigned int bitcount(unsigned int x) {
    unsigned int count = 0;
    while (x != 0) {
        count++;
        x &= (x - 1);
    }
    return count;
}

void main () {
    unsigned int x;

    x = 0;
    printf("%ud %ud\n", x, bitcount(x));
    x = 31;
    printf("%ud %ud\n", x, bitcount(x));
    x = 32;
    printf("%ud %ud\n", x, bitcount(x));
    x = 65535;
    printf("%ud %ud\n", x, bitcount(x));
    x = -1;
    printf("%ud %ud\n", x, bitcount(x));
}