#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "decision.h"

int main() {
    double *data = NULL;
    int n = 0;

    input(&data, &n);

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);
}
