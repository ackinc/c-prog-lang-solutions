#include <stdio.h>

float fahrenheitToCelsius(float f) { return (5.0 / 9 * (f - 32)); }
float celsiusToFahrenheit(float c) { return (9.0 / 5 * c + 32); }

void printCelsiusToFahrenheitTable(int start, int stop, int step) {
    printf("Celsius\tFahrenheit\n");
    for (int c = start; c <= stop; c += step) {
        printf("%6dC\t%9.1fF\n", c, celsiusToFahrenheit(c));
    }
}

void printFahrenheitToCelsiusTable(int start, int stop, int step) {
    printf("Fahrenheit\tCelsius\n");
    for (int f = start; f <= stop; f += step) {
        printf("%9dF\t%6.1fC\n", f, fahrenheitToCelsius(f));
    }
}

void main(int argc, char **argv) {
    printCelsiusToFahrenheitTable(0, 100, 5);
    printFahrenheitToCelsiusTable(0, 250, 10);
}
