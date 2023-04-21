CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = ./../build/

all: state_sort state_search


state_sort: state_sort.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_1

state_search: state_search.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_2

clean:
	rm $(BUILD_DIR)*

rebuild:
	make clean
	make all
