#include "stack.h"

#include <stdio.h>

void push_test() {
    struct stack stack = {.head = NULL};
    init(&stack, 1);

    printf("STACK: 1\n");
    printf("PUSH %d\n", 2);
    printf("EXPECTED: %d %d\n", 2, 1);
    push(&stack, 2);
    printf("GOT: %d %d\n", stack.head->val, stack.head->next->val);
    if (stack.head->val == 2 && stack.head->next->val == 1) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL");
    }
    destroy(&stack);
}

void pop_test() {
    struct stack stack = {.head = NULL};
    init(&stack, 1);

    push(&stack, 2);
    printf("STACK: ");
    struct node* cur = stack.head;
    while (cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\nAFTER DELETE 1 2:");
    pop(&stack);
    pop(&stack);
    cur = stack.head;
    while (cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    if (!stack.head) {
        printf("\nSUCCESS");
    } else {
        printf("\nFAIL");
    }
    destroy(&stack);
}

int main() {
    push_test();
    pop_test();
}