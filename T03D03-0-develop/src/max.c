#include <stdio.h>

int max(int lhs, int rhs) {
    if (lhs > rhs) {
        return lhs;
    } else {
        return rhs;
    }
}

int main() {
    int lhs = 0, rhs = 0;
    int r = scanf("%d %d", &lhs, &rhs);
    if (r != 2) {
        printf("n/a");
    }
    printf("%d", max(lhs, rhs));
    return 0;
}
