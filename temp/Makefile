#

CC = gcc
CFLAGS =-I.
CFLAGS +=-std=c99
CFLAGS +=-lm


all: fixed_point
	./fixed_point.exe

fixed_point: fixed_point.c
	$(CC) $(CFLAGS) fixed_point.c -o fixed_point.exe

clean:
	rm -f fixed_point.exe
