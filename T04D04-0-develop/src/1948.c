#include <math.h>
#include <stdio.h>

int is_dividable(float num, int del) {
    if (!del) {
        return -1;
    }

    while (num >= del) {
        num -= del;
    }

    if (!num) {
        return 1;
    } else {
        return 0;
    }
}

int is_prime(float num) {
    if (!num || num == 1) {
        return -1;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (is_dividable(num, i)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    float num = 0;
    int r = scanf("%f", &num);

    if (!r || round(num) != num) {
        printf("n/a");
        return 0;
    }

    if (!num) {
        printf("%f", num);
        return 0;
    }

    if (num < 0) {
        num -= 2 * num;
    }

    int max_del = 1;

    for (int i = 0; i != num; ++i) {
        for (int j = 0; j != i; ++j) {
            if (is_prime(j) == 1 && is_dividable(num, j) && j > max_del) {
                max_del = j;
            }
        }
    }

    printf("%d", max_del);

    return 0;
}