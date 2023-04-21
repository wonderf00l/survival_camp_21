#include "s21_string.h"

void s21_strlen_test() {
    const char* str1 = "normal str";
    int str_len = 10;
    int res = s21_strlen(str1);
    printf("NORMAL:%s\n", str1);
    printf("EXPECTED:%d\nGOT:%d\n", str_len, res);
    if (res == str_len) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    const char* str2 = NULL;
    str_len = -1;
    res = s21_strlen(str2);
    printf("BAD:NULL\n");
    printf("EXPECTED:%d\nGOT:%d\n", str_len, res);
    if (res == str_len) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    const char* str3 = "\0";
    str_len = 0;
    res = s21_strlen(str3);
    printf("MARGINAL:%s\n", str3);
    printf("EXPECTED:%d\nGOT:%d\n", str_len, res);
    if (res == str_len) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    char* str1 = "str1";
    char* str2 = "str2";

    int dif = 1;

    int res = s21_strcmp(str2, str1);

    printf("NORMAL:%s\t%s\n", str1, str2);
    printf("EXPECTED:%d\nGOT:%d\n", dif, res);
    if (res == dif) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    str1 = "anything you want";
    str2 = NULL;
    dif = -1;
    res = s21_strcmp(str1, str2);
    printf("BAD:%s\tNULL\n", str1);
    printf("EXPECTED:%d\nGOT:%d\n", dif, res);
    if (res == dif) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    str1 = NULL;
    str2 = NULL;
    dif = -1;
    res = s21_strcmp(str1, str2);
    printf("BAD:NULL\tNULL\n");
    printf("EXPECTED:%d\nGOT:%d\n", dif, res);
    if (res == dif) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    str1 = "looong s";
    str2 = "looong str";
    dif = 116;
    res = s21_strcmp(str1, str2);
    printf("MARGINAL:%s\t%s\n", str1, str2);
    printf("EXPECTED:%d\nGOT:%d\n", dif, res);
    if (res == dif) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    str1 = "-101";
    str2 = "12345";
    dif = 4;
    res = s21_strcmp(str2, str1);
    printf("MARGINAL:%s\t%s\n", str1, str2);
    printf("EXPECTED:%d\nGOT:%d\n", dif, res);
    if (res == dif) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void s21_strcpy_test() {  // can't modify string literals
    char* src = "string";
    char* dest = NULL;

    dest = s21_strcpy(src, dest);
    printf("NORMAL:SRC - %s ; DEST - NULL\n", src);
    printf("EXPECTED:%s\nGOT:NULL\n", src);
    if (dest) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
    free(dest);

    char* src_ = "string";
    char* dest_ = "not null";

    char* dest__ = s21_strcpy(src, dest_);
    printf("BAD:SRC - %s ; DEST - NULL\n", src_);
    printf("EXPECTED:NULL\nGOT:NULL\n");
    if (!dest__) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    char* src__ = "\0";
    char* dest___ = NULL;

    dest___ = s21_strcpy(src__, dest___);
    printf("MARGINAL:SRC - %s ; DEST - NULL\n", src__);
    printf("EXPECTED:%s\nGOT:%s\n", src__, dest___);
    if (!*dest___) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void s21_strchr_test() {
    char* str = "str";
    char sym = 't';

    char* pos = s21_strchr(str, sym);
    char* exp = str + 1;

    printf("NORMAL:%s\n", str);
    printf("EXPECTED:%s\nGOT:%s\n", exp, pos);
    if (exp == pos) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    char* str_ = NULL;
    sym = 'a';

    char* pos_ = s21_strchr(str_, sym);
    printf("BAD: NULL\n");
    printf("EXPECTED:NULL\nGOT: NULL\n");
    if (!pos_) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    char* str__ = "a";
    sym = 'a';

    char* pos__ = s21_strchr(str__, sym);
    printf("MARGINAL: %s\n", str__);
    printf("EXPECTED: %s\nGOT: %s\n", str__, pos__);
    if (str__ == pos__) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

void s21_strcat_test() {
    char* src = "str1";
    char dest[256] = "str2";

    char* res = s21_strcat(dest, src);
    printf("NORMAL:SRC - %s; DEST - %s\n", src, dest);
    printf("EXPECTED:str2str1\nGOT:%s\n", res);
    if (!s21_strcmp(res + s21_strlen(src), src)) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
}

int main() {
#ifdef STRLEN
    s21_strlen_test();
#endif
#ifdef STRCMP
    s21_strcmp_test();
#endif
#ifdef STRCPY
    s21_strcpy_test();
#endif
#ifdef STRCAT
    s21_strcat_test();
#endif
#ifdef STRCHR
    s21_strchr_test();
#endif
}
