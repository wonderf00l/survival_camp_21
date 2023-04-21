#include <stdio.h>
#include <math.h>

int main() {
    float x = 0, y = 0;
    int r = scanf("%f %f", &x, &y);
    printf("%f ww %f", x, y);

    if (r != 2) {
        printf("n/a");
        return 0;
    }

    if (pow(x, 2) + pow(y, 2) < 25) {
        printf("GOTCHA");
    } else {
        printf("MISS");
    }

    return 0;
}