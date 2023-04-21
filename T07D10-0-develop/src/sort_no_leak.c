#include <stdio.h>
#include <stdlib.h>

int input(int** a, int* n);
void swap(int* a, int* b);
void sort(int* a, int n);
void output(const int* a, int n);

int main() {
    int n = 0;
    int* arr = NULL;

    if (input(&arr, &n)) {
        sort(arr, n);
        output(arr, n);
        free(arr);
    } else {
        printf("n/a");
        return 0;
    }
}

int input(int** a, int* n) {
    int flag = 0;

    if (!scanf("%d", n) || *n <= 0) {
        flag = 1;
    }

    if (!(*a = (int*)calloc(*n, sizeof(int)))) {
        flag = 1;
    }

    for (int* p = *a; p - *a < *n; p++) {
        if (!scanf("%d", p)) {
            flag = 1;
            break;
        }
    }
    if (!flag) {
        return 1;
    } else {
        return 0;
    }
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void sort(int* a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void output(const int* a, int n) {
    for (int i = 0; i != n; ++i) {
        if (i == n - 1) {
            printf("%d", a[i]);
            break;
        }
        printf("%d ", a[i]);
    }
    return;
}