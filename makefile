CC = gcc
CFLAGS = -Wall -lm

all: src/main.c
	$(CC) $(CFLAGS) src/main.c -o bin/main
	chmod +x bin/main

clean:
	rm -rf bin/*