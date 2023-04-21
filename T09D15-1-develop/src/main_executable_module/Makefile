all: main

main: main_executable_module.o data_io.o data_process.o data_stat.o decision.o
	gcc -Wall -Wextra -Werror -std=c11 main_executable_module.o data_io.o data_process.o data_stat.o decision.o -o ../../build/Quest_3

build_with_static: main_executable_module.o data_io.o data_process.o decision.o data_stat.a
	gcc -Wall -Wextra -Werror -std=c11 main_executable_module.o data_io.o data_process.o decision.o -L. data_stat.a -o ../../build/Quest_5

data_stat.a: data_stat.o
	ar r data_stat.a data_stat.o

main_executable_module.o: main_executable_module.c ../data_libs/data_io.h ../data_module/data_process.h ../yet_another_decision_module/decision.h
	gcc -Wall -Wextra -Werror -std=c11 -c main_executable_module.c

data_io.o: ../data_libs/data_io.c ../data_libs/data_io.h
	gcc -Wall -Wextra -Werror -std=c11 -c ../data_libs/data_io.c

data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	gcc -Wall -Wextra -Werror -std=c11 -c ../data_module/data_process.c

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	gcc -Wall -Wextra -Werror -std=c11 -c ../data_libs/data_stat.c

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	gcc -Wall -Wextra -Werror -std=c11 -c ../yet_another_decision_module/decision.c


clean:
	rm -rf *.o main data_stat.a

rebuild:
	make clean
	make all