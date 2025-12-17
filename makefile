CC=gcc
CFLAGS=-Wall -Wextra -std=c99

TARGETS=akari

build: $(TARGETS)

akari: akari.c akari_obj.o
	$(CC) $(CFLAGS) akari.c akari_obj.o -o akari

akari_obj.o: akari_functions.c akari_headers.h
	$(CC) $(CFLAGS) -c akari_functions.c -o akari_obj.o

clean:
	rm -f $(TARGETS) *.o

.PHONY: clean
