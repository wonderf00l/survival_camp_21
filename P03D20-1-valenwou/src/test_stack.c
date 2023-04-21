#include "stack.h"
#include <stdio.h>

int main() {
    const int st_size = 5;

    stack st;
    init_stack(&st, st_size);

    push(&st, 'a');
    push(&st, 'b');
    push(&st, 'c');
    push(&st, 'd');
    push(&st, 'e');
    printf("POPPED: %c\n", pop(&st));
    push(&st, 'f');
    printf("PEEK: %c\n", peek(&st));

    print_stack(&st);

    free_stack(&st);
}