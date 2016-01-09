CC = gcc
CFLAGS=-Wall -std=gnu99

gameoflife: gameoflife.o gamefunc.o
	$(CC) $(CFLAGS) -o gameoflife gameoflife.o gamefunc.o

gameoflife.o: gameoflife.c gamefunc.h
	$(CC) $(CFLAGS) -c gameoflife.c

gamefunc.o: gamefunc.c
	$(CC) $(CFLAGS) -c gamefunc.c

clean: 
	rm gameoflife.o gamefunc.o gameoflife
