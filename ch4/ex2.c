#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]) {
    int i = 0, sign = 1;
    double val = 0, power = 1;

    if (s[i] == '-') {
        sign = -1;
        i++;
    }

    while (isdigit(s[i])) {
        val = val * 10 + (s[i] - '0');
        i++;
    }

    if (s[i] == '.' || s[i] == 'e' || s[i] == 'E') {
        if (s[i] == '.') {
            i++;
            while (isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                power /= 10;
                i++;
            }
        }
        if (s[i] == 'e' || s[i] == 'E') {
            i++;
            power *= pow(10, atof(s + i));
        }
    }

    return sign * val * power;
}

void test(char *s) { printf("%s %f\n", s, atof(s)); }

void main() {
    char *s;

    test("0");
    test("1.23");
    test("12345");
    test("-1234512.9011897");

    test("-1.23e6");
    test("12345.67e-4");
}
