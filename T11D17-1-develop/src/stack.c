#include "stack.h"

#include <stdlib.h>

struct node* init(struct stack* stack, int val) {
    if (!stack->head) {
        stack->head = malloc(sizeof(struct node));
        stack->head->val = val;
        stack->head->next = NULL;
        return stack->head;
    } else {
        return stack->head;
    }
}

struct node* push(struct stack* stack, int val) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = stack->head;
    stack->head = new_node;
    return stack->head;
}

struct node* pop(struct stack* stack) {
    int flag = 0;

    if (!stack->head) {
        flag = -1;
    }

    if (!flag) {
        struct node* temp = stack->head->next;
        free(stack->head);
        stack->head = temp;
        return stack->head;
    } else {
        return NULL;
    }
}

void destroy(struct stack* stack) {
    struct node* current = stack->head;
    while (current) {
        struct node* temp = current->next;
        free(current);
        current = temp;
    }
    stack->head = NULL;
}