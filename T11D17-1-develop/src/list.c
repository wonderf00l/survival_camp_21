#include "list.h"

#include <stdlib.h>

struct node* init(const struct door* door) {
    int flag = 0;

    if (!door) {
        flag = -1;
    }

    if (!flag) {
        struct node* new_node = malloc(sizeof(struct node));
        new_node->next = NULL;
        new_node->door = *door;
        return new_node;
    } else {
        return NULL;
    }
}

struct node* add_door(struct node* elem, const struct door* door) {
    int flag = 0;

    if (!elem || !door) {
        flag = -1;
    }

    if (!flag) {
        struct node* new_node = malloc(sizeof(struct node));
        new_node->next = elem->next ? elem->next : NULL;
        new_node->door = *door;
        elem->next = new_node;
        return new_node;
    } else {
        return NULL;
    }
}

struct node* find_door(int door_id, struct node* root) {
    int flag = 0;

    if (!root) {
        flag = -1;
    }

    if (!flag) {
        struct node* current = root;
        while (current && current->door.id != door_id) {
            current = current->next;
        }
        return current ? current : NULL;
    } else {
        return NULL;
    }
}

struct node* remove_door(struct node* elem, struct node* root) {
    int flag = 0;

    if (!elem || !root) {
        flag = -1;
    }

    if (!flag) {
        struct node* current = root;
        while (current->next) {
            if (current->next == elem) {
                free(current->next);
                current->next = elem->next;
                break;
            }
            current = current->next;
        }
        return current->next;
    } else {
        return NULL;
    }
}

void destroy(struct node* root) {
    struct node* current = root;
    while (current) {
        struct node* temp = current->next;
        free(current);
        current = temp;
    }
}