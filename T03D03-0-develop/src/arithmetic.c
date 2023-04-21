#include <stdio.h>

int sum(int a, int b);

int main() {
    int lhs = 0, rhs = 0;

    int r = scanf("%d %d", &lhs, &rhs);

    printf("%d %d %d ", lhs + rhs, lhs - rhs, lhs * rhs);

    if (r != 2) {
        printf("Invalid parameters!");
        return 0;
    }

    if (rhs) {
        printf("%d", lhs / rhs);
    } else {
        printf("n/a");
    }

    return 0;
}

int sum(int a, int b) { return (2 * a * b) / (a - b); }