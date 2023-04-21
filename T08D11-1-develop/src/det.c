#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double det(double** matrix, int n);
int input_dynamic_nested(double*** a, int* rows, int* cols);

int main() {
    double** matrix = NULL;
    int n = 0, m = 0;

    if (input_dynamic_nested(&matrix, &n, &m)) {
        printf("%.6f", det(matrix, n));
        for (int i = 0; i != n; ++i) {
            free(matrix[i]);
        }
        free(matrix);
    } else {
        printf("n/a");
    }
}

int input_dynamic_nested(double*** a, int* rows, int* cols) {
    int flag = 0;

    if ((scanf("%d", rows) && *rows > 0) && (scanf("%d", cols) && *cols > 0) &&
        (*a = malloc(*rows * sizeof(double*)))) {
        for (int i = 0; i != *rows; ++i) {
            if (!((*a)[i] = malloc(*cols * sizeof(double)))) {
                flag = 1;
                break;
            }
        }

        for (int i = 0; i != *rows; ++i) {
            for (int j = 0; j != *cols; ++j) {
                if (!(scanf("%lf", (*a)[i] + j))) {
                    flag = 1;
                    break;
                }
            }
        }
    } else {
        flag = 1;
    }

    if (!flag) {
        return 1;
    } else {
        return 0;
    }
}

double det(double** matrix, int n) {
    int i, j, j1, j2;
    double det_ = 0;
    double** m = NULL;

    if (n < 1) { /* Error */

    } else if (n == 1) { /* Shouldn't get used */
        det_ = matrix[0][0];
    } else if (n == 2) {
        det_ = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    } else {
        det_ = 0;
        for (j1 = 0; j1 < n; j1++) {
            m = malloc((n - 1) * sizeof(double*));
            for (i = 0; i < n - 1; i++) m[i] = malloc((n - 1) * sizeof(double));
            for (i = 1; i < n; i++) {
                j2 = 0;
                for (j = 0; j < n; j++) {
                    if (j == j1) continue;
                    m[i - 1][j2] = matrix[i][j];
                    j2++;
                }
            }
            det_ += pow(-1.0, 1.0 + j1 + 1.0) * matrix[0][j1] * det(m, n - 1);
            for (i = 0; i < n - 1; i++) free(m[i]);
            free(m);
        }
    }
    return (det_);
}