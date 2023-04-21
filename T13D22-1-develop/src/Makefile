CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = ./../build/

all: cipher

cipher: cipher.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)cipher

clean:
	rm $(BUILD_DIR)*

rebuild:
	make clean
	make all
