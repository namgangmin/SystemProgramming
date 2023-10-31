OBJECTS = main.o add.o sub.o multiplay.o divide.o
CC = gcc
CFLAGS = -g -O2
TARGET = oper

oper : main.o add.o sub.o multiply.o divide.o
	gcc -o main main.o add.o sub.o multiply.o divide.o

main.o : main.c
	gcc -c -o main.o main.c

add.o : add.c
	gcc -c -o add.o add.c

sub.o : sub.c
	gcc -c -o sub.o sub.c

multiply.o : multiply.c
	gcc -c -o multiply.o multiply.c

divide.o : divide.c
	gcc -c -o divide.o divide.c

clean :
	rm -f oper add.o sub.o multiply.o divide.o

