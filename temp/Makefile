#

CC = gcc
CFLAGS =-I.
CFLAGS +=-std=c99
CFLAGS +=-lm


all: comb
	./run.exe

comb: fixed_point priority
	$(CC) $(CFLAGS) -o run.exe priority-calc.o

fixed_point: fixed_point.h
	$(CC) $(CFLAGS) -c fixed_point.h

priority: priority-calc.c
	$(CC) $(CFLAGS) -c priority-calc.c

clean:
	rm -f *.o *.exe
