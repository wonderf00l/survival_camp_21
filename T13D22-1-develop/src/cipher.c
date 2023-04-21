#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_empty(FILE* stream);
void file_output(char* buf, FILE* stream);
void write_to_file(char* text, FILE* stream);
void encrypt(int shift, FILE* stream);
void encrypt_outer(char* dir);
void delete (char* dir);
void encrypt_and_delete();

int main() {
    int mode = 0;
    FILE* fptr;

    while (mode != -1) {
        if (scanf("%d", &mode)) {  // to also read \n -- for fgets -- BUT -1 mode works incorrectly then
            getchar();
            char filename[256];
            char buf[1024];
            if (mode == 1) {
                // scanf("%255s", filename);  // 255 - to prevent overflow
                fgets(filename, sizeof(filename), stdin);
                filename[strlen(filename) - 1] = '\0';

                if ((fptr = fopen(filename, "r"))) {
                    if (!is_empty(fptr)) {
                        file_output(buf, fptr);
                        fclose(fptr);
                    } else {
                        printf("n/a\n");
                    }
                } else {
                    printf("n/a\n");
                }
            } else if (mode == 2) {
                if ((fptr = fopen(filename, "r+"))) {  // if a+ - ptr on the EOF

                    char add_text[256];
                    fgets(add_text, sizeof(add_text), stdin);

                    fseek(fptr, 0, SEEK_END);
                    write_to_file(add_text, fptr);
                    fseek(fptr, 0, SEEK_SET);
                    file_output(buf, fptr);

                    fclose(fptr);
                }
            } else if (mode == 3) {
                encrypt_and_delete();
            } else if (mode == -1) {
                continue;
            } else {
                printf("n/a\n");
            }
        } else {
            printf("n/a\n");
            char tmp[256];
            fgets(tmp, sizeof(tmp), stdin);  // extract bad symbols from the stdin - clear stdin
        }
    }
}

void file_output(char* buf, FILE* stream) {
    while (fgets(buf, sizeof(buf), stream)) {
        printf("%s", buf);
    }
    putchar('\n');
}

int is_empty(FILE* stream) {
    int flag = 0;

    int sym = fgetc(stream);  // int - to compare with EOF

    if (sym == EOF) {
        flag = 1;
    } else {
        ungetc(sym, stream);
    }

    return flag;
}

void write_to_file(char* text, FILE* stream) {
    fputs(text, stream);
    // fputc('\n', stream);
}

void encrypt(int shift, FILE* stream) {
    char ch = 0;
    while ((ch = fgetc(stream)) != EOF) {
        fseek(stream, -1, SEEK_CUR);
        fputc((ch + shift) % 128, stream);
    }
}

void encrypt_outer(char* dir) {  // +- 3

    char command[256];
    int shift = 0;

    // snprintf(command, sizeof(command), "cd %s", dir);
    snprintf(command, sizeof(command), "ls %s | grep '.c' > tmp.txt", dir);
    system(command);

    if (scanf("%d", &shift)) {
        FILE* fptr;
        fptr = fopen("tmp.txt", "r");

        char file[256];

        while (!feof(fptr)) {
            if (fgets(file, sizeof(file), fptr)) {
                file[strlen(file) - 1] = '\0';

                char dir_cpy[256];
                strcpy(dir_cpy, dir);
                strcat(dir_cpy, file);
                int index = strchr(dir_cpy, '\\') - dir_cpy;
                memmove(&dir_cpy[index], &dir_cpy[index + 1], strlen(dir_cpy) - index);

                FILE* ftmp;
                if ((ftmp = fopen(dir_cpy, "r+"))) {
                    encrypt(shift, ftmp);
                    fclose(ftmp);
                } else {
                    printf("n/a");
                }
            }
        }

        fclose(fptr);

    } else {
        printf("n/a");
    }

    remove("tmp.txt");
}

void delete (char* dir) {
    char command[256];

    snprintf(command, sizeof(command), "rm -f %s*.h", dir);

    system(command);
}

void encrypt_and_delete() {
    char dir[256];

    if (fgets(dir, sizeof(dir), stdin)) {
        dir[strlen(dir) - 1] = '\0';  // GET RID OF \n for the following IO
        encrypt_outer(dir);
        delete (dir);
    } else {
        printf("n/a");
    }
}
