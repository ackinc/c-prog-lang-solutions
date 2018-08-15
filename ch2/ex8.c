#include <stdio.h>

#define BITS_IN_INT 32

// n bits starting from p will be 1, other bits will be 0
// 0 <= p <= 31
// 1 <= n <= p + 1
unsigned int makemask(int p, int n) {
    unsigned int leftmask = ~0 << (p + 1);
    unsigned int rightmask = ~(~0 << (p - n + 1));
    return ~(leftmask | rightmask);
}

unsigned int setbits(unsigned int x, int start, int n, unsigned int y) {
    y <<= start - n + 1;
    unsigned int mask = ~makemask(start, n);
    x &= mask;
    x |= y;
    return x;
}

unsigned int rightrot(unsigned int x, int n) {
    unsigned int mask = makemask(n - 1, n);
    unsigned int lost_bits = x & mask;
    x >>= n;
    x = setbits(x, BITS_IN_INT - 1, n, lost_bits);
    return x;
}

void main() {
    unsigned int x = 65535;
    printf("x = %d\n", x);
    printf("%ud\n", rightrot(x, 1));  // 2^31 + (2^15 - 1)
    printf("%ud\n", rightrot(x, 16)); // (2^32 - 1) - (2 ^ 16 - 1)
}
