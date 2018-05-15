CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

build: tail.c cola.c cola.h testing.c syntax_validation.c pila.h pila.c diff.c
	$(CC) $(CFLAGS) tail.c cola.c cola.h testing.c syntax_validation.c pila.h pila.c diff.c -o pruebas

run: build
	./pruebas

valgrind: build
	valgrind $(VFLAGS) ./pruebas
