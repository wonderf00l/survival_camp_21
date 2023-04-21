#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

node* bstree_create_node(int item) {
    node* new_node = malloc(sizeof(node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->val = item;
    return new_node;
}

int max(int lhs, int rhs) { return (lhs > rhs) ? lhs : rhs; }

void print_node_val(int item) { printf(" %d ", item); }

void bstree_insert(node** root, int item, int (*cmpf)(int, int)) {
    if (!(*root)) {
        *root = malloc(sizeof(node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->val = item;
        return;
    }

    if ((*cmpf)(item, (*root)->val) == item) {
        bstree_insert(&((*root)->right), item, cmpf);
    } else {
        bstree_insert(&((*root)->left), item, cmpf);
    }
}

void bstree_apply_infix(node* root, void (*applyf)(int)) {
    if (!root) {
        return;
    }

    bstree_apply_infix(root->left, applyf);
    (*applyf)(root->val);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(node* root, void (*applyf)(int)) {
    if (!root) {
        return;
    }

    (*applyf)(root->val);
    bstree_apply_infix(root->left, applyf);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_postfix(node* root, void (*applyf)(int)) {
    if (!root) {
        return;
    }

    bstree_apply_infix(root->left, applyf);
    bstree_apply_infix(root->right, applyf);
    (*applyf)(root->val);
}

void destroy(node* root) {
    if (!root) {
        return;
    }
    node* left_ = root->left;
    node* right_ = root->right;
    free(root);

    destroy(left_);
    destroy(right_);
}