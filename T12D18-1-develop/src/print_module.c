#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    struct tm* newtime;
    time_t ltime;

    ltime = time(NULL);
    newtime = localtime(&ltime);

    char str[256];
    // int h = 0, min = 0, sec = 0;
    printf("%s ", Log_prefix);
    // sscanf(asctime(newtime), "%s %s%d %d:%d:%d %d\n",str, str, &a, &h, &min, &sec, &b);
    strftime(str, 256, "%H:%M:%S", newtime);
    printf("%s ", str);

    for (int i = 0; message[i]; ++i) {
        (*print)(message[i]);
    }
}