#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define EPSILON 0.000001

// Функция для вычисления синуса
double my_sin(double x)
{
    // Приводим x к диапазону [-pi, pi]
    while (x > PI)
    {
        x -= 2 * PI;
    }
    while (x < -PI)
    {
        x += 2 * PI;
    }

    double term = x;   // Первый член ряда
    double sum = term; // Начальное значение суммы
    int n = 1;         // Начальный порядок члена

    // Вычисляем члены ряда, пока их абсолютное значение больше заданной точности
    while (fabs(term) >= EPSILON)
    {
        term *= -x * x / (2 * n * (2 * n + 1));
        sum += term;
        n++;
    }

    return sum;
}

int main()
{
    double x;

    printf("Введите значение x (в радианах): ");
    scanf("%lf", &x);

    double result = my_sin(x);
    printf("sin(%.6f) = %.6f\n", x, result);

    return 0;
}
