#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int binsearch (int needle, int haystack[], int len) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (haystack[mid] < needle) l = mid + 1;
        else if (haystack[mid] > needle) r = mid - 1;
        else return mid;
    }
    return -1;
}

int binsearchAlt (int needle, int haystack[], int len) {
    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (haystack[mid] < needle) l = mid + 1;
        else r = mid;
    }
    if (haystack[l] == needle) return l;
    else return -1;
}

void test (int n, int numbers[], int len) {
    clock_t begin, end;

    printf("Finding %d\n", n);

    begin = clock();
    binsearch(n, numbers, len);
    end = clock();
    printf("binsearch took %ld clock cycles\n", end - begin);

    begin = clock();
    binsearchAlt(n, numbers, len);
    end = clock();
    printf("binsearchAlt took %ld clock cycles\n", end - begin);
}

void main () {
    int empty[] = {1};
    // test empty array
    printf("%d\n", binsearchAlt(5, empty, 0));

    // tests for single elem array
    printf("%d\n", binsearchAlt(1, empty, 1));
    printf("%d\n", binsearchAlt(5, empty, 1));

    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = -1; i <= 10; i++) {
        printf("%d %d %d\n", i, binsearch(i, numbers, 10), binsearchAlt(i, numbers, 10));
    }

    int items[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= 10; i++) {
        printf("%d %d %d\n", i, binsearch(i, items, 10), binsearchAlt(i, items, 10));
    }

    printf("Performance tests\n");
    int *arr = (int *)malloc(sizeof(int) * 1e6);
    for (int i = 0; i < 1e6; i++) arr[i] = i;

    test(234847, arr, 1e6);
    test(1, arr, 1e6);
    test(-9, arr, 1e6);
    test(999999, arr, 1e6);
    test(892791, arr, 1e6);
    test(90909, arr, 1e6);
    test(100953, arr, 1e6);
    test(200953, arr, 1e6);
    test(400953, arr, 1e6);
    test(500001, arr, 1e6);
    test(600424, arr, 1e6);
}