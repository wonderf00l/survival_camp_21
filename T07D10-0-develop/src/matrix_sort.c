#include <stdio.h>
#include <stdlib.h>

int input_dynamic_nested(int*** a, int* rows, int* cols);
void free_dynamic_nested(int*** a, int rows);
void output_dynamic_nested(int** a, int rows, int cols);
void dynamic_nested_mode(int*** a, int* rows, int* cols);

int input_dynamic_inline(int*** p_array, int** val_array, int* rows, int* cols);
void output_dynamic_inline(int** p_array, int rows, int cols);
void free_dynamic_inline(int*** p_array, int** val_array);
void dynamic_inline_mode(int*** p_array, int** val_array, int* rows, int* cols);

int input_dynamic_inline_p(int*** inline_matrix, int** ptr, int* rows, int* cols);
void output_dynamic_inline_p(int** inline_matrix, int rows, int cols);
void free_dynamic_inline_p(int*** inline_matrix);
void dynamic_inline_mode_p(int*** inline_matrix, int** ptr, int* rows, int* cols);

int row_sum(const int* row, int cols);
void row_swap(int** row1, int** row2);
void matrix_sort(int*** a, int rows, int cols);

int main() {
    int mode = 0;

    int rows = 0, cols = 0;

    if (scanf("%d", &mode)) {
        if (mode == 1) {
            int** arr = NULL;
            dynamic_nested_mode(&arr, &rows, &cols);
        } else if (mode == 2) {
            int** p_arr = NULL;
            int* val_arr = NULL;
            dynamic_inline_mode(&p_arr, &val_arr, &rows, &cols);
        } else if (mode == 3) {
            int** inline_matrix = NULL;
            int* ptr = NULL;
            dynamic_inline_mode_p(&inline_matrix, &ptr, &rows, &cols);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
        return 0;
    }
}

int input_dynamic_nested(int*** a, int* rows, int* cols) {
    int flag = 0;

    if ((scanf("%d", rows) && *rows > 0) && (scanf("%d", cols) && *cols > 0) &&
        (*a = malloc(*rows * sizeof(int*)))) {
        for (int i = 0; i != *rows; ++i) {
            if (!((*a)[i] = malloc(*cols * sizeof(int)))) {
                flag = 1;
                break;
            }
        }

        for (int i = 0; i != *rows; ++i) {
            for (int j = 0; j != *cols; ++j) {
                if (!(scanf("%d", (*a)[i] + j))) {
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

int row_sum(const int* row, int cols) {
    int sum = 0;
    for (int j = 0; j != cols; ++j) {
        sum += row[j];
    }
    return sum;
}

void row_swap(int** row1, int** row2) {
    int* tmp = *row1;
    *row1 = *row2;
    *row2 = tmp;
}

void matrix_sort(int*** a, int rows, int cols) {
    for (int k = 0; k != rows; ++k) {
        for (int i = 0; i != rows - 1 - k; ++i)
            if (row_sum((*a)[i], cols) > row_sum((*a)[i + 1], cols)) {
                row_swap(&(*a)[i], &(*a)[i + 1]);
            }
    }
}

void output_dynamic_nested(int** a, int rows, int cols) {
    for (int i = 0; i != rows; ++i) {
        for (int j = 0; j != cols; ++j) {
            if (j == cols - 1) {
                printf("%d", a[i][j]);
            } else {
                printf("%d ", a[i][j]);
            }
        }
        if (i != rows - 1) {
            putchar('\n');
        }
    }
}

void free_dynamic_nested(int*** a, int rows) {
    for (int i = 0; i != rows; ++i) {
        free((*a)[i]);
    }
    free(*a);
}

void dynamic_nested_mode(int*** a, int* rows, int* cols) {
    if (input_dynamic_nested(a, rows, cols)) {
        matrix_sort(a, *rows, *cols);
        output_dynamic_nested(*a, *rows, *cols);
        free_dynamic_nested(a, *rows);
    } else {
        printf("n/a");
    }
}

int input_dynamic_inline(int*** p_array, int** val_array, int* rows, int* cols) {
    int flag = 0;

    if ((scanf("%d", rows) && *rows > 0) && (scanf("%d", cols) && *cols > 0) &&
        (*p_array = malloc(*rows * sizeof(int*))) && (*val_array = malloc(*rows * *cols * sizeof(int)))) {
        for (int i = 0; i != *rows; ++i) {
            (*p_array)[i] = *val_array + *cols * i;
        }

        for (int i = 0; i != *rows; ++i) {
            for (int j = 0; j != *cols; ++j) {
                if (!(scanf("%d", (*p_array)[i] + j))) {
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

void output_dynamic_inline(int** p_array, int rows, int cols) {
    for (int i = 0; i != rows; ++i) {
        for (int j = 0; j != cols; ++j) {
            if (j == cols - 1) {
                printf("%d", p_array[i][j]);
            } else {
                printf("%d ", p_array[i][j]);
            }
        }
        if (i != rows - 1) {
            putchar('\n');
        }
    }
}

void free_dynamic_inline(int*** p_array, int** val_array) {
    free(*val_array);
    free(*p_array);  // можем передавать сюда local копию указателя - адрес тот же, память будет почищена
}

void dynamic_inline_mode(int*** p_array, int** val_array, int* rows, int* cols) {
    if (input_dynamic_inline(p_array, val_array, rows, cols)) {
        matrix_sort(p_array, *rows, *cols);
        output_dynamic_inline(*p_array, *rows, *cols);
        free_dynamic_inline(p_array, val_array);
    } else {
        printf("n/a");
    }
}

int input_dynamic_inline_p(int*** inline_matrix, int** ptr, int* rows, int* cols) {
    int flag = 0;

    if ((scanf("%d", rows) && *rows > 0) && (scanf("%d", cols) && *cols > 0) &&
        (*inline_matrix = malloc(*rows * *cols * sizeof(int) + *rows * sizeof(int*)))) {
        *ptr = (int*)(*inline_matrix + *rows);

        for (int i = 0; i != *rows; ++i) {
            (*inline_matrix)[i] = *ptr + *rows * i;
        }

        for (int i = 0; i != *rows; ++i) {
            for (int j = 0; j != *cols; ++j) {
                if (!(scanf("%d", (*inline_matrix)[i] + j))) {
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

void output_dynamic_inline_p(int** inline_matrix, int rows, int cols) {
    for (int i = 0; i != rows; ++i) {
        for (int j = 0; j != cols; ++j) {
            if (j == cols - 1) {
                printf("%d", inline_matrix[i][j]);
            } else {
                printf("%d ", inline_matrix[i][j]);
            }
        }
        if (i != rows - 1) {
            putchar('\n');
        }
    }
}

void free_dynamic_inline_p(int*** inline_matrix) { free(*inline_matrix); }

void dynamic_inline_mode_p(int*** inline_matrix, int** ptr, int* rows, int* cols) {
    if (input_dynamic_inline_p(inline_matrix, ptr, rows, cols)) {
        matrix_sort(inline_matrix, *rows, *cols);
        output_dynamic_inline_p(*inline_matrix, *rows, *cols);
        free_dynamic_inline_p(inline_matrix);
    } else {
        printf("n/a");
    }
}