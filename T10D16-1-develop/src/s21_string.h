#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char* str);
int s21_strcmp(char* str1, char* str2);
char* s21_strcpy(const char* src, char* dest);
char* s21_strchr(const char* str, char sym);
char* s21_strcat(char* dest, const char* src);
#endif