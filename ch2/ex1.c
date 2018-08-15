#include <float.h>
#include <limits.h>
#include <stdio.h>

void computeRanges() {
    char c = 0;
    char prevc = -1;

    unsigned char uc = 1;
    unsigned char prevuc = 0;

    short s = 0;
    short prevs = -1;

    unsigned short us = 1;
    unsigned short prevus = 0;

    int i = 0;
    int previ = -1;

    unsigned int ui = 1;
    unsigned int prevui = 0;

    long l = 0;
    long prevl = -1;

    unsigned long ul = 1;
    unsigned long prevul = 0;

    float f = 1;
    float prevf = 0;

    double d = 1;
    double prevd = 0;

    printf("Sizeof Char: %ld\n", sizeof(char));
    while (c > prevc) {
        prevc = c;
        c++;
    }

    while (uc > prevuc) {
        prevuc = uc;
        uc++;
    }

    printf("Min Char: %d\n", c);
    printf("Max Char: %d\n", prevc);
    printf("Min Unsigned Char: %d\n", uc);
    printf("Max Unsigned Char: %d\n", prevuc);

    printf("\n\n");

    printf("Sizeof Short: %ld\n", sizeof(short));
    while (s > prevs) {
        prevs = s;
        s++;
    }

    while (us > prevus) {
        prevus = us;
        us++;
    }

    printf("Min Short: %d\n", s);
    printf("Max Short: %d\n", prevs);
    printf("Min Unsigned Short: %d\n", us);
    printf("Max Unsigned Short: %d\n", prevus);

    printf("\n\n");

    printf("Sizeof Int: %ld\n", sizeof(int));
    while (i > previ) {
        previ = i;
        i += 1e4;
    }
    i = previ--;
    while (i > previ) {
        previ = i;
        i++;
    }

    while (ui > prevui) {
        prevui = ui;
        ui += 1e4;
    }
    ui = prevui--;
    while (ui > prevui) {
        prevui = ui;
        ui++;
    }

    printf("Min Int: %d\n", i);
    printf("Max Int: %d\n", previ);
    printf("Min Unsigned Int: %ud\n", ui);
    printf("Max Unsigned Int: %ud\n", prevui);

    printf("\n\n");

    printf("Sizeof Long: %ld\n", sizeof(long));
    while (l > prevl) {
        prevl = l;
        l += 1e14;
    }
    l = prevl--;
    while (l > prevl) {
        prevl = l;
        l += 1e9;
    }
    l = prevl--;
    while (l > prevl) {
        prevl = l;
        l += 1e4;
    }
    l = prevl--;
    while (l > prevl) {
        prevl = l;
        l++;
    }

    while (ul > prevul) {
        prevul = ul;
        ul += 1e14;
    }
    ul = prevul--;
    while (ul > prevul) {
        prevul = ul;
        ul += 1e9;
    }
    ul = prevul--;
    while (ul > prevul) {
        prevul = ul;
        ul += 1e4;
    }
    ul = prevul--;
    while (ul > prevul) {
        prevul = ul;
        ul++;
    }

    printf("Min Long: %ld\n", l);
    printf("Max Long: %ld\n", prevl);
    printf("Min Unsigned Long: %lu\n", ul);
    printf("Max Unsigned Long: %lu\n", prevul);

    printf("\n\n");

    // INCORRECT: Adding 1 to MAX_FLOAT doesn't make it wrap around
    // printf("Sizeof Float: %ld\n", sizeof(float));
    // while (f > prevf) {
    //     prevf = f;
    //     f += 1e14;
    // }
    // f = prevf--;
    // while (f > prevf) {
    //     prevf = f;
    //     f += 1e9;
    // }
    // f = prevf--;
    // while (f > prevf) {
    //     prevf = f;
    //     f += 1e4;
    // }
    // f = prevf--;
    // while (f > prevf) {
    //     prevf = f;
    //     f++;
    // }
    // f = prevf--;
    // while (f > prevf) {
    //     prevf = f;
    //     f += 0.1;
    // }

    // printf("Min Float: %f\n", f);
    // printf("Max Float: %f\n", prevf);
}

void printRangesFromLimitsHeader() {
    printf("Min Char: %d\n", CHAR_MIN);
    printf("Max Char: %d\n", CHAR_MAX);
    printf("Max Unsigned Char: %u\n", UCHAR_MAX);

    printf("Min Short: %d\n", SHRT_MIN);
    printf("Max Short: %d\n", SHRT_MAX);
    printf("Max Unsigned Short: %u\n", USHRT_MAX);

    printf("Min Int: %d\n", INT_MIN);
    printf("Max Int: %d\n", INT_MAX);
    printf("Max Unsigned Int: %u\n", UINT_MAX);

    printf("Min Long: %ld\n", LONG_MIN);
    printf("Max Long: %ld\n", LONG_MAX);
    printf("Max Unsigned Long: %lu\n", ULONG_MAX);

    printf("Min Float: %f\n", -FLT_MAX);
    printf("Max Float: %f\n", FLT_MAX);
    printf("Min Double: %f\n", -DBL_MAX);
    printf("Max Double: %f\n", DBL_MAX);
}

void main() {
    // computeRanges();
    printRangesFromLimitsHeader();
}
