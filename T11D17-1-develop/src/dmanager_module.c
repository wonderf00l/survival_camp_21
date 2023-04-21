#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void doors_sort(struct door* doors);
void doors_swap(struct door* door1, struct door* door2);
void doors_close(struct door* doors);
void doors_output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    doors_sort(doors);
    doors_close(doors);
    doors_output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void doors_swap(struct door* door1, struct door* door2) {
    struct door temp = *door1;
    *door1 = *door2;
    *door2 = temp;
}

void doors_sort(struct door* doors) {
    for (int i = 0; i != DOORS_COUNT; ++i) {
        for (int j = 0; j != DOORS_COUNT - 1 - i; ++j) {
            if (doors[j].id > doors[j + 1].id) {
                doors_swap(doors + j, doors + j + 1);
            }
        }
    }
}

void doors_close(struct door* doors) {
    for (int i = 0; i != DOORS_COUNT; ++i) {
        doors[i].status = 0;
    }
}

void doors_output(struct door* doors) {
    for (int i = 0; i != DOORS_COUNT; ++i) {
        (i == DOORS_COUNT - 1) ? printf("%d, %d", doors[i].id, doors[i].status)
                               : printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}