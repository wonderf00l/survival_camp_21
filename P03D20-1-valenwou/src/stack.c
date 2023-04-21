#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void init_stack(stack* st, int size) {
    st->buf_size = size;
    st->buf = (char*)malloc(st->buf_size * sizeof(char));
    st->head = 0;
}

void push(stack* st, char item) {
    if (st->head <= st->buf_size) {
        st->buf[(st->head)++] = item;
    }
}

char pop(stack* st) {
    if (st->head) {
        return st->buf[--(st->head)];
    } else {
        return '\0';
    }
}

char peek(stack* st) {
    if (st->head) {
        return st->buf[st->head - 1];
    } else {
        return '\0';
    }
}

int isEmpty(stack* st) { return !st->head; }

void print_stack(stack* st) {
    for (int i = 0; i != st->head; ++i) {
        (i != st->head - 1) ? printf("%c ", st->buf[i]) : printf("%c\n", st->buf[i]);
    }
}

void free_stack(stack* st) {
    if (st->head) {
        free(st->buf);
    }
}