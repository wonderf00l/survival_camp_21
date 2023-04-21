#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void swap(int *a, int *b);

int input(int **matrix, int *n, int *m);
void output(int *matrix, int n, int m);

int main() {
    int *matrix = NULL;
    int *result = NULL;
    int n = 0, m = 0;

    if (input(&matrix, &n, &m)) {
        result = (int *)malloc(n * m * sizeof(int));
        sort_vertical(&matrix, n, m, &result);
        output(result, n, m);
        putchar('\n');
        sort_horizontal(&matrix, n, m, &result);
        output(result, n, m);
        free(matrix);
        free(result);
    } else {
        printf("n/a");
    }
}

int input(int **matrix, int *n, int *m) {
    int flag = 0;

    if ((scanf("%d", n) && *n > 0) && (scanf("%d", m) && *m > 0) &&
        (*matrix = (int *)malloc((*n) * (*m) * sizeof(int)))) {
        for (int i = 0; i != *n; ++i) {
            for (int j = 0; j != *m; ++j) {
                if (!(scanf("%d", &((*matrix)[i * (*m) + j])))) {
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

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    for (int i = 0; i != n * m; ++i) {
        for (int j = 0; j != n * m - 1 - i; ++j) {
            if ((*matrix)[j] > (*matrix)[j + 1]) {
                swap((*matrix) + j, (*matrix) + j + 1);
            }
        }
    }

    for (int i = 0, src_i = 0; i != n; ++i) {
        if (i % 2) {
            for (int res_j = m - 1; res_j >= 0; --res_j, ++src_i) {
                (*result_matrix)[i * m + res_j] = (*matrix)[src_i];
            }
        } else {
            for (int res_j = 0; res_j != m; ++res_j, ++src_i) {
                (*result_matrix)[i * m + res_j] = (*matrix)[src_i];
            }
        }
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    for (int i = 0; i != n * m; ++i) {
        for (int j = 0; j != n * m - 1 - i; ++j) {
            if ((*matrix)[j] > (*matrix)[j + 1]) {
                swap((*matrix) + j, (*matrix) + j + 1);
            }
        }
    }

    for (int j = 0, src_i = 0; j != m; ++j) {  // по исходной отсоритрованной матрице движемся последовательно
        if (j % 2) {
            for (int res_i = n - 1; res_i >= 0; --res_i, ++src_i) {
                (*result_matrix)[res_i * m + j] = (*matrix)[src_i];
            }
        } else {
            for (int res_i = 0; res_i != n; ++res_i, ++src_i) {
                (*result_matrix)[res_i * m + j] = (*matrix)[src_i];
            }
        }
    }
}

void output(int *matrix, int n, int m) {
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            if (j != m - 1) {
                printf("%d ", matrix[i * m + j]);
            } else {
                printf("%d", matrix[i * m + j]);
            }
        }
        putchar('\n');
    }
}