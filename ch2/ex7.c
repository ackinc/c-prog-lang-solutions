#include <stdio.h>

// n bits starting from p will be 1, other bits will be 0
// 0 <= p <= 31
// 1 <= n <= p + 1
unsigned int makemask(int p, int n) {
    unsigned int leftmask = ~0 << (p + 1);
    unsigned int rightmask = ~(~0 << (p - n + 1));
    return ~(leftmask | rightmask);
}

unsigned int invert(unsigned int x, int start, int n) {
    unsigned int mask = makemask(start, n);
    unsigned int bits_of_interest = x & mask;
    unsigned int bits_of_interest_inverted = ~bits_of_interest & mask;
    unsigned int x_rest = x & ~mask;
    return x_rest | bits_of_interest_inverted;
}

void main() {
    unsigned int x = 65535;
    printf("x = %d\n", x);
    printf("%ud\n", invert(x, 15, 8)); // 255
    printf("%ud\n", invert(x, 7, 8));  // 65535 - 255 = 65280
    printf("%ud\n", invert(x, 3, 2));  // 65535 - 12 = 65523
}
