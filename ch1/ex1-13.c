#include <stdio.h>

#define MAXWORDLEN 20
#define OUT 0
#define IN 1

int isBlank(char c) { return (c == ' ' || c == '\t' || c == '\n' || c == EOF); }
void drawHorizontalHistogram(int frequencies[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%2d: ", i);
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
            printf("  *");
        else
            printf("   ");
    }
    printf("\n");
}
void drawVerticalHistogram(int frequencies[], int n) {
    int maxfreq = getArrayMax(frequencies, n);
    for (int i = 0; i < maxfreq; i++)
        drawVertHistRow(i, maxfreq, frequencies, n);

    for (int i = 0; i < n; i++) printf("%3d", i);
    printf("\n");
}
void main() {
    int c, state = OUT, curWordLen = 0;
    int frequencies[MAXWORDLEN];
    for (int i = 0; i < MAXWORDLEN; i++) frequencies[i] = 0;

    while (c = getchar()) {
        if (!isBlank(c)) {
            state = IN;
            curWordLen++;
        } else if (state == IN) { // we are at a word boundary
            state = OUT;
            if (curWordLen > MAXWORDLEN) curWordLen = MAXWORDLEN;
            frequencies[curWordLen]++;
            curWordLen = 0;
        }
        if (c == EOF) break;
    }

    printf("\n");
    printf("Frequencies: ");
    for (int i = 0; i < MAXWORDLEN; i++) printf(" %d", frequencies[i]);
    printf("\n\n");
    drawHorizontalHistogram(frequencies, MAXWORDLEN);
    printf("\n\n");
    drawVerticalHistogram(frequencies, MAXWORDLEN);
}
