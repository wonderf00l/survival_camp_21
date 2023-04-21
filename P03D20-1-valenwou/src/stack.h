#ifndef STACK_H
#define STACK_H

typedef struct stack_struct {
    char* buf;
    int buf_size;
    int head;
} stack;

void init_stack(stack* st, int size);
void push(stack* st, char item);
char pop(stack* st);
char peek(stack* st);
int isEmpty(stack* st);
void print_stack(stack* st);
void free_stack(stack* st);

#endif
