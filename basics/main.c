#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    char *str = "awe";
    char arr[3] = "ba\0";
    printf("hello %s\n", str);
    printf("hello %s\n", arr);

    bool isTrue = true ? 2 == 2 : false;

    printf("%d\n", (int)(isTrue));

    char *leak = malloc(2 * sizeof(char));

    char *cpyLeak = leak;

    printf("%p\n", leak++);
    printf("%p\n", leak);

    free(cpyLeak);

    return 0;
}