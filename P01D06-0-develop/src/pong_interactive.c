#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

static struct termios stored_settings;

void set_keypress(void) {
    struct termios new_settings;

    tcgetattr(0, &stored_settings);

    new_settings = stored_settings;

    new_settings.c_lflag &= (~ICANON & ~ECHO);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;

    tcsetattr(0, TCSANOW, &new_settings);
    return;
}

void reset_keypress(void) {
    tcsetattr(0, TCSANOW, &stored_settings);
    return;
}

void print_field(int left_cent, int right_cent, int ball_x, int ball_y);
void start();

int main(void) { start(); }
void start() {
    int left_cent = 12, right_cent = 12, ball_x = 40, ball_y = 12;
    int dx = 2, dy = 0;
    int left_score = 0, right_score = 0;

    fd_set rfds;
    struct timeval tv;
    int retval;

    set_keypress();

    print_field(left_cent, right_cent, ball_x, ball_y);

    while (1) {
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);

        tv.tv_sec = 0;
        tv.tv_usec = 0;
        retval = select(2, &rfds, NULL, NULL, &tv);

        int input = 0;

        if (retval) {
            input = getc(stdin);
        }
        usleep(100000);

        printf("LEFT SCORE: %d\t", left_score);
        printf("RIGHT SCORE: %d\n", right_score);

        if ((input == 'k' || input == 'K') && right_cent > 2) {
            --right_cent;
        } else if ((input == 'm' || input == 'M') && right_cent < 22) {
            ++right_cent;
        }
        if ((input == 'a' || input == 'A') && left_cent > 2) {
            --left_cent;
        } else if ((input == 'z' || input == 'Z') && left_cent < 22) {
            ++left_cent;
        }
        if (input == 'q' || input == 'Q') {
            return;
        }

        ball_x += dx;
        ball_y += dy;

        if (ball_x == 2) {
            if (ball_y - left_cent == -1) {
                dx = 2;
                dy = -1;
            }
            if (ball_y - left_cent == 0) {
                dx = 2;
            }
            if (ball_y - left_cent == 1) {
                dx = 2;
                dy = 1;
            }
        }

        if (ball_x == 78) {
            if (ball_y - right_cent == -1) {
                dx = -2;
                dy = -1;
            }
            if (ball_y - right_cent == 0) {
                dx = -2;
            }
            if (ball_y - right_cent == 1) {
                dx = -2;
                dy = 1;
            }
        }

        if (ball_y == 1) {
            if (dx == -2 && dy == -1) {
                dy = 1;
            }
            if (dx == 2 && dy == -1) {
                dy = 1;
            }
        }
        if (ball_y == 23) {
            if (dx == 2 && dy == 1) {
                dy = -1;
            }
            if (dx == -2 && dy == 1) {
                dy = -1;
            }
        }

        if (ball_x < 2) {
            ++right_score;
            left_cent = 12, right_cent = 12, ball_x = 40, ball_y = 12, dx = -2, dy = 0;
        }

        if (ball_x > 79) {
            ++left_score;
            left_cent = 12, right_cent = 12, ball_x = 40, ball_y = 12, dx = 2, dy = 0;
        }

        if (right_score == 21) {
            printf("RIGHT HAS WON!\n");
            return;
        } else if (left_score == 21) {
            printf("LEFT HAS WON!\n");
            return;
        }

        system("clear");

        print_field(left_cent, right_cent, ball_x, ball_y);
    }

    reset_keypress();
    exit(0);
}

void print_field(int left_cent, int right_cent, int ball_x, int ball_y) {
    for (int j = 1; j <= 80; ++j) {
        printf("*");
    }

    putchar('\n');

    for (int i = 1; i <= 23; ++i) {
        for (int j = 1; j <= 80; ++j) {
            if (i == ball_y && j == ball_x) {
                printf("o");
                continue;
            }

            if (j == 40) {
                printf("*");
                continue;
            }

            if (j == 1) {
                printf("*");
                continue;
            }
            if (j == 80) {
                printf("*");
                continue;
            }

            if ((abs(i - left_cent) <= 1) && j == 2) {
                printf("[");
                continue;
            }
            if ((abs(i - right_cent) <= 1) && j == 79) {
                printf("]");
                continue;
            }

            printf(" ");
        }
        putchar('\n');
    }

    for (int j = 1; j <= 80; ++j) {
        printf("*");
    }
    putchar('\n');
}
