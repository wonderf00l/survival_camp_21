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
void rec_output(door* rec);
int rec_compare(door* lhs, door* rhs);

int main() {
    char path[256];
    fgets(path, sizeof(path), stdin);
    path[strlen(path) - 1] = '\0';

    int day_to_search = 0, month_to_search = 0, year_to_search = 0;

    if (scanf("%d.%d.%d", &day_to_search, &month_to_search, &year_to_search)) {
        FILE* fptr;
        door rec_to_search = {.day = day_to_search, .month = month_to_search, .year = year_to_search};

        if ((fptr = fopen(path, "rb"))) {
            if (file_size(fptr)) {
                door buf_door;
                int found = 0;
                while (fread(&buf_door, sizeof(door), 1, fptr)) {
                    if (rec_compare(&rec_to_search, &buf_door)) {
                        rec_output(&buf_door);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("n/a");
                }
            } else {
                printf("n/a");
            }
            fclose(fptr);
        } else {
            printf("n/a");
        }
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

void rec_output(door* rec) { printf("%d", rec->code); }

int rec_compare(door* lhs, door* rhs) {
    return (lhs->day == rhs->day && lhs->month == rhs->month && lhs->year == rhs->year) ? 1 : 0;
}