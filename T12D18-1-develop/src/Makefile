CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = ./../build/

all: print_module bst_create_test bst_insert_test bst_traverse_test

print_module: main_module_entry_point.c print_module.h print_module.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_1

bst_create_test: bst.c bst.h bst_create_test.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_3

bst_insert_test: bst.c bst.h bst_insert_test.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_4

bst_traverse_test: bst.c bst.h bst_traverse_test.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_5

clean:
	rm -rf *.o  $(BUILD_DIR)*

rebuild:
	make clean
	make all

