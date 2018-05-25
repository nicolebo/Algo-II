CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

build: main.c strutil.c strutil.h testing.c testing.h pruebas_alumno.c
	$(CC) $(CFLAGS) main.c strutil.c strutil.h testing.c pruebas_alumno.c -o pruebas

run: build
	./pruebas

valgrind: build
	valgrind $(VFLAGS) ./pruebas