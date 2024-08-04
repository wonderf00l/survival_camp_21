#include <stdio.h>
#include <stdlib.h>

int fillMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (!scanf("%d", matrix[i] + j))
            {
                return 1;
            }
        }
    }
    return 0;
}

void outMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            char *format = j < cols - 1 ? "%d " : "%d";
            printf(format, matrix[i][j]);
        }
        putchar('\n');
    }
}

int sum(int **matrix, int rows, int cols)
{
    int sum = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < i && j < cols; ++j)
        {
            if (matrix[i][j] > 0)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int sumRow(int *row, int rowSize)
{
    int sum = 0;
    for (int i = 0; i < rowSize; ++i)
    {
        sum += row[i];
    }
    return sum;
}

void swapRows(int **l, int **r)
{
    int *tmp = *r;
    *r = *l;
    *l = tmp;
}

void sortMatrixByRows(int **matrix, int rows, int cols)
{
    int *cache = calloc(rows, sizeof(int));

    for (int k = 0; k < rows; ++k)
    {
        for (int i = 0; i < (rows - 1) - k; ++i)
        {
            int curSum = /*k > 0 ? cache[i] :*/ sumRow(matrix[i], cols);
            int nextSUm = /*k > 0 ? cache[i + 1] :*/ sumRow(matrix[i + 1], cols);
            if (curSum > nextSUm)
            {
                swapRows(matrix + i, matrix + i + 1);
            }
            cache[i] = curSum;
            cache[i + 1] = nextSUm;
        }
    }

    free(cache);
}

int main()
{
    int rows = 0, cols = 0;

    if (scanf("%d %d", &rows, &cols) < 2)
    {
        printf("invalid matrix size input\n");
        return 1;
    }

    int **matrix = calloc(rows, sizeof(int *));
    if (!matrix)
    {
        printf("error during rows mem alloc\n");
        return 1;
    }

    for (int i = 0; i < rows; ++i)
    {
        if (!(matrix[i] = calloc(cols, sizeof(int))))
        {
            printf("error during cols mem alloc\n");
            return 1;
        }
    }

    fillMatrix(matrix, rows, cols);
    putchar('\n');
    outMatrix(matrix, rows, cols);
    printf("sum - %d\n", sum(matrix, rows, cols));

    sortMatrixByRows(matrix, rows, cols);
    printf("sorted:\n");
    outMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}