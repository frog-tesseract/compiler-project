CC = gcc
CFLAGS = -O0 -g -Wall
RAYLIB = $(shell pkg-config --cflags --libs raylib) -lm

all: 
	$(CC) $(CFLAGS) Tokeniser.c -o Tokeniser.o

clean:
	rm -f Tokeniser.o
run:
	./Tokeniser.o test_code/addition.c
