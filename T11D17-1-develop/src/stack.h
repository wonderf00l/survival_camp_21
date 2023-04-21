#ifndef STACK_H
#define STACK_H

struct node {
    struct node* next;
    int val;
};

struct stack {
    struct node* head;
};

struct node* init(struct stack* stack, int val);
struct node* push(struct stack* stack, int val);
struct node* pop(struct stack* stack);
void destroy(struct stack* stack);

#endif