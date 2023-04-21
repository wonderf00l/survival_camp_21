#include <stdio.h>
#include <string.h>

typedef struct door_state {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int stat;
    int code;
} door;

int file_size(FILE* stream);
int rec_quantity(FILE* stream);
door* max(door* rec1, door* rec2);
void rec_sort_inner(FILE* stream, door* rec1, door* rec2);
void rec_sort(FILE* stream, int rec_quantity);
void rec_output(door* rec);

int main() {
    char path[256];
    fgets(path, sizeof(path), stdin);
    path[strlen(path) - 1] = '\0';

    int mode = 0;

    if (scanf("%d", &mode)) {
        FILE* fptr;
        if (mode == 0) {
            if ((fptr = fopen(path, "rb"))) {
                door buf_door;
                while (fread(&buf_door, sizeof(door), 1, fptr)) {
                    rec_output(&buf_door);
                }
                fclose(fptr);
            } else {
                printf("n/a");
            }
        } else if (mode == 1) {  // no add if empty
            if ((fptr = fopen(path, "rb"))) {
                rec_sort(fptr, rec_quantity(fptr));
                fseek(fptr, 0, SEEK_SET);
                door buf_door;
                while (fread(&buf_door, sizeof(door), 1, fptr)) {
                    rec_output(&buf_door);
                }
                fclose(fptr);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
        // if empty and no mode 2 -- n/a
        // another modes
    } else {
        printf("n/a");
    }
}

int file_size(FILE* stream) {
    int size = 0;
    fseek(stream, 0, SEEK_END);
    size = ftell(stream);
    rewind(stream);
    return size;
}

int rec_quantity(FILE* stream) { return file_size(stream) / sizeof(door); }

door* max(door* rec1, door* rec2) {
    if (rec1->year >= rec2->year) {
        return rec1;
    } else {
        return rec2;
    }

    if (rec1->month >= rec2->month) {
        return rec1;
    } else {
        return rec2;
    }

    if (rec1->day >= rec2->day) {
        return rec1;
    } else {
        return rec2;
    }

    if (rec1->hour >= rec2->hour) {
        return rec1;
    } else {
        return rec2;
    }

    if (rec1->min >= rec2->min) {
        return rec1;
    } else {
        return rec2;
    }

    if (rec1->sec >= rec2->sec) {
        return rec1;
    } else {
        return rec2;
    }
}

void rec_sort_inner(FILE* stream, door* rec1, door* rec2) {
    fread(rec1, sizeof(door), 1, stream);
    fread(rec2, sizeof(door), 1, stream);
    fseek(stream, -2 * sizeof(door), SEEK_CUR);
    if (max(rec1, rec2) == rec1) {
        fwrite(rec2, sizeof(door), 1, stream);
        fwrite(rec1, sizeof(door), 1, stream);
    }
    fseek(stream, -1 * sizeof(door), SEEK_CUR);
}

void rec_sort(FILE* stream, int rec_quantity) {
    for (int i = 0; i != rec_quantity - 1; ++i) {
        for (int j = 0; j != rec_quantity - 1 - i; ++j) {
            door rec1, rec2;
            rec_sort_inner(stream, &rec1, &rec2);
        }
    }
}

void rec_output(door* rec) {
    printf("%d %d %d %d %d %d %d %d\n", rec->year, rec->month, rec->day, rec->hour, rec->min, rec->sec,
           rec->stat, rec->code);
}
