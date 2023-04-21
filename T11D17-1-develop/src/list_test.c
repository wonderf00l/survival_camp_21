#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

void add_door_test() {
    struct door init_door = {0, 0};
    struct node* init_node = init(&init_door);

    struct door normal_door = {1, 0};

    printf("NORMAL: INSERT(id=%d status=%d) AFTER (id=%d status=%d)\n", normal_door.id, normal_door.status,
           init_door.id, init_door.status);
    printf("EXPECTED: DOOR1(id=%d, status=%d) -- DOOR2(id=%d, status=%d)\n", init_node->door.id,
           init_node->door.status, normal_door.id, normal_door.status);
    struct node* new_node = add_door(init_node, &normal_door);
    printf("GOT: DOOR1(id=%d, status=%d) -- DOOR2(id=%d, status=%d)\n", init_node->door.id,
           init_node->door.status, new_node->door.id, new_node->door.status);
    if (new_node->door.id == init_node->next->door.id &&
        new_node->door.status == init_node->next->door.status && find_door(1, init_node) == new_node) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
    free(new_node);

    init_node->next = NULL;
    printf("BAD: INSERT %p AFTER (id=%d status=%d)\n", NULL, init_door.id, init_door.status);
    printf("EXPECTED: DOOR1(id=%d, status=%d) -- NULL\n", init_node->door.id, init_node->door.status);
    new_node = add_door(init_node, NULL);
    printf("GOT: DOOR1(id=%d, status=%d) -- %p\n", init_node->door.id, init_node->door.status, new_node);
    if (!new_node && !init_node->next) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
    free(init_node);
    free(new_node);

    init_node = NULL;
    printf("BAD: INSERT (id=%d status=%d) AFTER %p \n", normal_door.id, normal_door.status, NULL);
    printf("EXPECTED: %p\n", NULL);
    new_node = add_door(init_node, &normal_door);
    printf("GOT: %p\n", new_node);
    if (!new_node) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    destroy(init_node);
}
void remove_door_test() {
    struct door init_door = {0, 0};
    struct node* init_node = init(&init_door);

    struct door normal_door = {1, 0};
    struct node* new_node = add_door(init_node, &normal_door);

    printf("NORMAL: DELETE (id=%d status=%d)\n", new_node->door.id, new_node->door.status);
    printf("EXPECTED: DOOR1(id=%d status=%d) -- %p\n", init_node->door.id, init_node->door.status, NULL);
    struct node* after_deleted = remove_door(new_node, init_node);
    printf("GOT: DOOR1(id=%d, status=%d) -- %p\n", init_node->door.id, init_node->door.status, after_deleted);
    if (!after_deleted && !init_node->next) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }
    destroy(init_node);

    new_node = add_door(init_node, &normal_door);
    printf("BAD: DELETE %p\n", NULL);
    printf("EXPECTED: DOOR1(id=%d status=%d) -- DOOR2(id=%d status=%d)\n", init_node->door.id,
           init_node->door.status, new_node->door.id, new_node->door.status);
    after_deleted = remove_door(NULL, init_node);
    printf("GOT: DOOR1(id=%d, status=%d) -- DOOR2(id=%d status=%d)\n", init_node->door.id,
           init_node->door.status, new_node->door.id, new_node->door.status);
    if (!after_deleted && init_node->next) {
        printf("SUCCESS\n\n");
    } else {
        printf("FAIL\n\n");
    }

    free(init_node);
}

int main() {
    add_door_test();
    remove_door_test();
}