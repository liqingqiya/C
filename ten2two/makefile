main: main.o ten_t_two.o reverse.o
	gcc -g -o main main.o ten_t_two.o reverse.o

main.o:main.c
	gcc -g -c main.c

ten_t_two.o:ten_t_two.h ten_t_two.c
	gcc -g -c ten_t_two.c

reverse.o:reverse.c reverse.h
	gcc -g -c reverse.c
