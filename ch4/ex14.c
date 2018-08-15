#include <stdio.h>

#define swap(t, x, y) { t w = x; x = y; y = w; }

void test(int i, int j) {
    printf("(%d %d) -> ", i, j);
    swap(int, i, j);
    printf("(%d %d)\n", i, j);
}

void main () {
    test(1, 2);
    test(-1, -2);
}