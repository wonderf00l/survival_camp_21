#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_create_test(int a, int b) {
    printf("GOT: %d %d\n", a, b);

    node* new_node_1 = bstree_create_node(a);
    node* new_node_2 = bstree_create_node(b);

    printf("CREATED NODES: %d %d\n", new_node_1->val, new_node_2->val);
    if (new_node_1->val == a && new_node_2->val == b) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    free(new_node_1);
    free(new_node_2);
}

void bst_insert_test(int a, int b, int c, int d, int e, int f) {
    void (*printer)(int) = &print_node_val;
    int (*cmpf)(int, int) = &max;

    node* init_node = bstree_create_node(a);
    printf("INITIAL NODE: %d\n", init_node->val);

    printf("GOT: %d %d %d %d %d\n", b, c, d, e, f);

    printf("AFTER INSERTION %d:\n", b);
    bstree_insert(&init_node, b, cmpf);
    printf("INFIX: ");
    bstree_apply_infix(init_node, printer);
    putchar('\n');
    printf("PREFIX: ");
    bstree_apply_prefix(init_node, printer);
    putchar('\n');
    printf("POSTFIX: ");
    bstree_apply_postfix(init_node, printer);
    putchar('\n');

    printf("AFTER INSERTION %d:\n", c);
    bstree_insert(&init_node, c, cmpf);
    printf("INFIX: ");
    bstree_apply_infix(init_node, printer);
    putchar('\n');
    printf("PREFIX: ");
    bstree_apply_prefix(init_node, printer);
    putchar('\n');
    printf("POSTFIX: ");
    bstree_apply_postfix(init_node, printer);
    putchar('\n');

    printf("AFTER INSERTION %d:\n", d);
    bstree_insert(&init_node, d, cmpf);
    printf("INFIX: ");
    bstree_apply_infix(init_node, printer);
    putchar('\n');
    printf("PREFIX: ");
    bstree_apply_prefix(init_node, printer);
    putchar('\n');
    printf("POSTFIX: ");
    bstree_apply_postfix(init_node, printer);
    putchar('\n');

    printf("AFTER INSERTION %d:\n", e);
    bstree_insert(&init_node, e, cmpf);
    printf("INFIX: ");
    bstree_apply_infix(init_node, printer);
    putchar('\n');
    printf("PREFIX: ");
    bstree_apply_prefix(init_node, printer);
    putchar('\n');
    printf("POSTFIX: ");
    bstree_apply_postfix(init_node, printer);
    putchar('\n');

    printf("AFTER INSERTION %d:\n", f);
    bstree_insert(&init_node, f, cmpf);
    printf("INFIX: ");
    bstree_apply_infix(init_node, printer);
    putchar('\n');
    printf("PREFIX: ");
    bstree_apply_prefix(init_node, printer);
    putchar('\n');
    printf("POSTFIX: ");
    bstree_apply_postfix(init_node, printer);
    putchar('\n');

    if (init_node->left->val == 1 && init_node->right->val == 4 && init_node->left->left->val == 0 &&
        init_node->right->left->val == 3 && init_node->right->right->val == 5) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    destroy(init_node);
}

int main() {
    int a = 2, b = 4, c = 1, d = 5, e = 0, f = 3;
    bst_create_test(a, b);
    bst_insert_test(a, b, c, d, e, f);
}