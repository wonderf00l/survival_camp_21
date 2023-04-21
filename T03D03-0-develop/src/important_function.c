#include <math.h>
#include <stdio.h>

float f(float x) {
    return 7 * pow(10, -3) * pow(x, 4) +
           ((22.8 * pow(x, (float)1 / 3) - pow(10, 3)) * x + 3) / ((float)x * x / 2) -
           x * pow(10 + x, (float)2 / x) - 1.01;
}

int main() {
    float x = 0;
    int r = scanf("%f", &x);

    if (r != 1 || x <= 0) {
        printf("n/a");
        return 0;
    }

    printf("%.1f", f(x));

    return 0;
}