#include <stdio.h>

#define ALPHABET_LENGTH 26

int isBlank(char c) { return (c == ' ' || c == '\t' || c == '\n' || c == EOF); }

void drawHorizontalHistogram(int frequencies[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c: ", i + 'a');
        for (int j = 0; j < frequencies[i]; j++) printf("*");
        printf("\n");
    }
}

int getArrayMax(int arr[], int n) {
    // assumes arr has at least one element
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    return max;
}

void drawVertHistRow(int row, int nrows, int numbersArr[], int n) {
    for (int i = 0; i < n; i++) {
        if (numbersArr[i] >= nrows - row)
            printf("*");
        else
            printf(" ");
    }
    printf("\n");
}

void drawVerticalHistogram(int frequencies[], int n) {
    int maxfreq = getArrayMax(frequencies, n);
    for (int i = 0; i < maxfreq; i++)
        drawVertHistRow(i, maxfreq, frequencies, n);

    for (int i = 0; i < n; i++) printf("%c", i + 'a');
    printf("\n");
}

void main() {
    char c;
    int frequencies[ALPHABET_LENGTH];
    for (int i = 0; i < ALPHABET_LENGTH; i++) frequencies[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z')
            frequencies[c - 'a']++;
        else if (c >= 'A' && c <= 'Z')
            frequencies[c - 'A']++;
    }

    drawHorizontalHistogram(frequencies, ALPHABET_LENGTH);
    drawVerticalHistogram(frequencies, ALPHABET_LENGTH);
}
