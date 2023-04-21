#include <stdio.h>

int main() {
    int num;
    int r = scanf("%d", &num);
    if (!r) {
        printf("Incorrect input!");
        return -1;
    }

    printf("Hello, %d!", num);

    return 0;
}