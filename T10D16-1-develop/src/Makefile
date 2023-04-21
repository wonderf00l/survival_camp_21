CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_DIR = ./../build/

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strtok_tests strstr_tests

strlen_tests: s21_string.o test1.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_1

strcmp_tests: s21_string.o test2.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_2

strcpy_tests: s21_string.o test3.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_3

strcat_tests: s21_string.o test4.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_4

strchr_tests: s21_string.o test5.o
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)Quest_5

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c $< -o $@

s21_string_test.o: s21_string.o
	$(CC) $(CFLAGS) -c $< -o $@

test1.o: s21_string_test.c s21_string.h
	$(CC) $(CFLAGS) -DSTRLEN -c $< -o $@

test2.o: s21_string_test.c s21_string.h
	$(CC) $(CFLAGS) -DSTRCMP -c $< -o $@
    
test3.o: s21_string_test.c s21_string.h
	$(CC) $(CFLAGS) -DSTRCPY -c $< -o $@

test4.o: s21_string_test.c s21_string.h
	$(CC) $(CFLAGS) -DSTRCAT -c $< -o $@

test5.o: s21_string_test.c s21_string.h
	$(CC) $(CFLAGS) -DSTRCHR -c $< -o $@

clean:
	rm -rf *.o  $(BUILD_DIR)Quest_1 $(BUILD_DIR)Quest_2 $(BUILD_DIR)Quest_3 $(BUILD_DIR)Quest_4 $(BUILD_DIR)Quest_5 $(BUILD_DIR)Quest_6 $(BUILD_DIR)Quest_7

rebuild: clean all
