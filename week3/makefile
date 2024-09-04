# Macros
CC = gcc
#CFLAGS = -Wall
# CFLAGS = -g
 CFLAGS = -D NDEBUG
# CFLAGS = -D NDEBUG -O
# CFLAGS = -std=c90 -Wall -Wextra
# Pattern rule
%.o: %.c
	$(CC) $(CFLAGS) -c $<


all: testintmath


clean:
	rm -f testintmath *.o

testintmath: testintmath.o intmath.o
	$(CC) $(CFLAGS) $< intmath.o -o $@

testintmath.o: intmath.h


intmath.o:  intmath.h
