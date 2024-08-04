#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int arr[5] = {1, 2, 3, 4, 5};

typedef struct point
{
    int x, y;
} point;

typedef bool comparator(int, int);

bool isCloserToCoordStart(int p1, int p2)
{
    return abs(p1) < abs(p2);
}

comparator *lessAbs = isCloserToCoordStart;

int input(int *arr, int size)
{
    for (int i = 0; i != size; ++i)
    {
        if (!scanf("%d", arr + i))
        {
            return 1;
        }
    }
    return 0;
}

void output(int *arr, int size)
{
    for (int i = 0; i != size; ++i)
    {
        char *format = i < size - 1 ? "%d " : "%d";
        printf(format, arr[i]);
    }
    putchar('\n');
}

int inPoints(point *ps, int size)
{
    for (int i = 0; i != size; ++i)
    {
        if (scanf("%d.%d", &ps[i].x, &ps[i].y) < 2)
        {
            return 1;
        }
    }
    return 0;
}

void outPoints(point *ps, int size)
{
    for (int i = 0; i != size; ++i)
    {
        char *format = i < size - 1 ? "(%d, %d) " : "(%d, %d)";
        printf(format, ps[i].x, ps[i].y);
    }
    putchar('\n');
}

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void swapPoints(point *a, point *b)
{
    point tmp = *b;
    *b = *a;
    *a = tmp;
}

void sortPoints(int *xPoints, int size, comparator *comp)
{
    for (int i = 0; i != size; ++i)
    {
        for (int j = 0; j != (size - 1) - i; ++j)
        {
            if (comp(xPoints[j + 1], xPoints[j]))
            {
                swap(xPoints + j, xPoints + j + 1);
            }
        }
    }
}

double dist(point p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

void sortPoints1(point *points, int size)
{
    for (int i = 0; i != size; ++i)
    {
        for (int j = 0; j != (size - 1) - i; ++j)
        {
            if (dist(points[j + 1]) < dist(points[j]))
            {
                swapPoints(points + j + 1, points + j);
            }
        }
    }
}

void pointPrint(point p)
{
    printf("%d-%d", p.x, p.y);
}

// [1 1 2 3 3 3 4 1 1]

int mostFrequent(int *arr, int size)
{
    int freq = 0, elem = 0;

    for (int i = 0; i < size; ++i)
    {
        int curFreq = 1, curElem = arr[i];
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] == curElem)
            {
                ++curFreq;
            }
        }
        if (curFreq > freq)
        {
            freq = curFreq;
            elem = curElem;
        }
    }
    return elem;
}

int maxPairSum(int *arr, int size)
{
    int maxSum = -__INT_MAX__;
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] + arr[i + 1] > maxSum)
        {
            maxSum = arr[i] + arr[i + 1];
        }
    }
    return maxSum;
}

int main()
{
    int size;

    if (!scanf("%d", &size))
    {
        printf("can't scan arr size\n");
        exit(1);
    }

    int *xPoints = calloc(size, sizeof(int));

    if (input(xPoints, size) != 0)
    {
        printf("can't scan arr element\n");
        exit(1);
    }

    output(xPoints, size);
    sortPoints(xPoints, size, isCloserToCoordStart);
    printf("most freq - %d\n", mostFrequent(xPoints, size));
    printf("max sum - %d\n", maxPairSum(xPoints, size));
    output(xPoints, size);

    free(xPoints);

    if (!scanf("%d", &size))
    {
        printf("can't scan points size\n");
        exit(1);
    }

    point *points = calloc(size, sizeof(point));
    if (inPoints(points, size) != 0)
    {
        printf("can't scan point elem\n");
        exit(1);
    }
    outPoints(points, size);
    sortPoints1(points, size);
    outPoints(points, size);
    free(points);
}
