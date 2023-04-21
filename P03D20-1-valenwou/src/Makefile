CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = ./../build/


# $^ == подставь все ресурсы (с-файлы и хедеры) вместо этой записи
stack: stack.c stack.h test_stack.c
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)stack_test

clean:
	rm -rf *.o  $(BUILD_DIR)*

rebuild:
	make clean
	make all
