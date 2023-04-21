#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

void field_init(char*** field, char*** next_gen, int width, int length);
int field_input(char** field, int width, int length);
void field_output(char** field, int width, int length);
void field_clear(char** field, char** next_gen, int width);

int neighbours_counter(char** field, int width, int length, int i, int j);
int gen_change(char** field, char** next_gen, int width, int length);
void gen_swap(char*** field, char*** next_gen);

void start(char** field, char** next_gen, int width, int length);

void set_keypress(void);
void reset_keypress(void);

static struct termios stored_settings;

int main() {
    const int width = 25;
    const int length = 80;

    char** field = NULL;
    char** next_gen = NULL;

    field_init(&field, &next_gen, width, length);
    if (!field_input(field, width, length)) {
        start(field, next_gen, width, length);
    } else {
        printf("n/a");
    }

    field_clear(field, next_gen, width);

    return 0;
}

void field_init(char*** field, char*** next_gen, int width, int length) {
    *field = (char**)malloc(width * sizeof(char*));

    for (int i = 0; i != width; ++i) {
        (*field)[i] = (char*)malloc(length * sizeof(char));
    }

    *next_gen = (char**)malloc(width * sizeof(char*));

    for (int i = 0; i != width; ++i) {
        (*next_gen)[i] = (char*)malloc(length * sizeof(char));
    }
}

void set_keypress(void) {
    struct termios new_settings;

    tcgetattr(0, &stored_settings);

    new_settings = stored_settings;

    new_settings.c_lflag &= (~ICANON & ~ECHO);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;

    tcsetattr(0, TCSANOW, &new_settings);
}

void reset_keypress(void) { tcsetattr(0, TCSANOW, &stored_settings); }

int field_input(char** field, int width, int length) {
    int flag = 0;
    char ch;

    for (int i = 0; i != width; ++i) {
        for (int j = 0; j != length + 1; ++j) {  // + 1 for '\n'
            if (scanf("%c", &ch)) {
                if (ch == 'O' || ch == '_') {
                    field[i][j] = ch;
                } else if (ch == '\n') {
                    continue;
                } else {
                    flag = 1;
                }
            } else {
                flag = 1;
                break;
            }
        }
    }

    return flag;
}

void field_output(char** field, int width, int length) {
    for (int i = 0; i != width; ++i) {
        for (int j = 0; j != length; ++j) {
            printf("%c", field[i][j]);
        }
        if (i != width - 1) {
            putchar('\n');
        }
    }
    putchar('\n');
}

void field_clear(char** field, char** next_gen, int width) {
    for (int i = 0; i != width; ++i) {
        free(field[i]);
    }
    free(field);

    for (int i = 0; i != width; ++i) {
        free(next_gen[i]);
    }
    free(next_gen);
}

int neighbours_counter(char** field, int width, int length, int i, int j) {
    int neighbours = 0;

    (field[i][(j + (length - 1)) % length] == 'O') ? ++neighbours : true;  // [i][j - 1]
    (field[i][(j + 1) % length] == 'O') ? ++neighbours : true;             // [i][j + 1]
    (field[(i + (width - 1)) % width][j] == 'O') ? ++neighbours : true;    //[i - 1][j]
    (field[(i + 1) % width][j] == 'O') ? ++neighbours : true;              //[i + 1][j]
    (field[(i + (width - 1)) % width][(j + (length - 1)) % length] == 'O') ? ++neighbours
                                                                           : true;       // [i - 1][j - 1]
    (field[(i + (width - 1)) % width][(j + 1) % length] == 'O') ? ++neighbours : true;   //[i - 1][j + 1]
    (field[(i + 1) % width][(j + (length - 1)) % length] == 'O') ? ++neighbours : true;  //[i + 1][j - 1]
    (field[(i + 1) % width][(j + 1) % length] == 'O') ? ++neighbours : true;             // [i + 1][j + 1]

    return neighbours;
}

void gen_swap(char*** field, char*** next_gen) {
    char** temp = *field;
    *field = *next_gen;
    *next_gen = temp;
}

int gen_change(char** field, char** next_gen, int width, int length) {
    int has_changes = 0;

    for (int i = 0; i != width; ++i) {
        for (int j = 0; j != length; ++j) {
            if (field[i][j] == 'O') {
                if (neighbours_counter(field, width, length, i, j) < 2 ||
                    neighbours_counter(field, width, length, i, j) > 3) {
                    next_gen[i][j] = '_';  // dying in next_gen
                    has_changes = 1;
                } else {
                    next_gen[i][j] = 'O';  // still alive in next_gen
                }
            } else if (field[i][j] == '_') {
                if (neighbours_counter(field, width, length, i, j) == 3) {
                    next_gen[i][j] = 'O';  // birth in next_gen
                    has_changes = 1;
                } else {
                    next_gen[i][j] = '_';  // stil dead in next_gen
                }
            }
        }
    }

    return has_changes;
}

void start(char** field, char** next_gen, int width, int length) {
    fd_set rfds;
    struct timeval tv;

    set_keypress();

    int has_changes = 1;
    int time = 1;

    while (has_changes) {
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);

        tv.tv_sec = 0;
        tv.tv_usec = 0;
        int retval = select(2, &rfds, NULL, NULL, &tv);

        int input = 0;

        if (retval != 0) {
            input = getc(stdin);
        }
        usleep(1000000 - time * 85000);

        if (input - '0' >= 0 && input - '0' <= 9) {  // user input
            time = input - '0';
        } else if (input == 'q' || input == 'Q') {
            break;
        }

        system("clear");

        field_output(field, width, length);

        has_changes = gen_change(field, next_gen, width, length);

        gen_swap(&field, &next_gen);
    }

    reset_keypress();

    printf("\nGAME OVER");
}
