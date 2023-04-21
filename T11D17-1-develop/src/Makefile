CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = ./../build/

all: door_struct list_test stack_test

door_struct: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_1

list_test: list_test.c door_struct.h list.c list.h
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_2

stack_test: stack_test.c stack.c stack.h # need all used files(stack.c included)
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_3

clean:
	rm -rf *.o  $(BUILD_DIR)*

rebuild:
	make clean
	make all