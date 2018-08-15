#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int getbits(unsigned int x, int start, int n);
unsigned int setbits(unsigned int x, int start, int n, unsigned int y);
unsigned int makemask(int p, int n);

void main() {
    unsigned int x = 65535, y;
    printf("x = %d\n", x);

    y = 0;
    printf("y = %d\n", y);
    printf("%ud\n", setbits(x, 15, 16, y)); // 0
    printf("%ud\n", setbits(x, 23, 16, y)); // 255
    printf("%ud\n", setbits(x, 7, 8, y));   // 65535 - 255 = 65280
    printf("%ud\n", setbits(x, 31, 16, y)); // 65535

    y = 69;
    printf("y = %d\n", y);
    printf("%ud\n", setbits(x, 15, 16, y)); // 69
    printf("%ud\n", setbits(x, 23, 16, y)); // 17919
    printf("%ud\n", setbits(x, 7, 8, y));   // 65535 - 255 + 69 = 65349
    printf("%ud\n", setbits(x, 31, 16, y)); // 4587519
}

unsigned int getbits(unsigned int x, int start, int n) {
    return (x >> (start + 1 - n)) & ~(~0 << n);
}

unsigned int setbits(unsigned int x, int start, int n, unsigned int y) {
    y <<= start - n + 1;
    unsigned int mask = ~makemask(start, n);
    x &= mask;
    x |= y;
    return x;
}

// n bits starting from p will be 1, other bits will be 0
unsigned int makemask(int p, int n) {
    unsigned int leftmask = ~0 << (p + 1);
    unsigned int rightmask = ~(~0 << (p - n + 1));
    return ~(leftmask | rightmask);
}
