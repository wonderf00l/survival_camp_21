#include "s21_string.h"

// can't dereference null ptr

int s21_strlen(const char* str) {
    int flag = 0;

    if (!str) {
        flag = -1;
    }

    int len = 0;
    for (; !flag && *(str + len); ++len)
        ;
    return !flag ? len : flag;
}

int s21_strcmp(char* str1, char* str2) {
    int flag = 0;

    if (!str1 || !str2) {
        flag = -1;
    }

    for (; !flag && *str1 && *str1 == *str2; ++str1, ++str2)
        ;

    if (!flag && !(*str1)) {
        flag = (int)*str2;
    }

    return !flag ? *str1 - *str2 : flag;
}

char* s21_strcpy(const char* src, char* dest) {
    int flag = 0;

    if (!src || !(*src) || dest) {
        flag = -1;
    }
    dest = (char*)malloc(s21_strlen(src) + 1);
    char* current_dest = dest;

    int i = 0;
    for (; !flag && src[i]; ++i) {
        *current_dest++ = src[i];
    }

    !flag ? current_dest[i] = '\0' : 1;

    return !flag ? dest : NULL;
}

char* s21_strchr(const char* s, char sym) {
    int flag = 0;

    if (!s) {
        flag = 1;
    }
    while (!flag && *s != sym && *s) {
        ++s;
    }
    return !flag && *s == sym ? (char*)s : NULL;
}

char* s21_strcat(char* dest, const char* src) {
    int flag = 0;

    if (!src) {
        flag = -1;
    }

    char* ptr = dest + s21_strlen(dest);

    while (!flag && *src) {
        *ptr++ = *src++;
    }

    *ptr = '\0';

    return !flag ? dest : NULL;
}