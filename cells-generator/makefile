CC = gcc
CFLAGS = -Wall -std=gnu99

generator: generator.o
	$(CC) $(CFLAGS) -o generator generator.o
generator.o: generator.c
	$(CC) $(CFLAGS) -c generator.c
clean:
	rm generator.o generator
