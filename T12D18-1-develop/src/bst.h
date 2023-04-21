#ifndef BST_H
#define BST_H

typedef struct tree_node {
    struct tree_node* left;
    struct tree_node* right;
    int val;
} node;

node* bstree_create_node(int item);
int max(int lhs, int rhs);
void print_node_val(int item);
void bstree_insert(node** root, int item, int (*cmpf)(int, int));
void bstree_apply_infix(node* root, void (*applyf)(int));
void bstree_apply_prefix(node* root, void (*applyf)(int));
void bstree_apply_postfix(node* root, void (*applyf)(int));
void destroy(node* root);

#endif