CC=gcc
CFLAGS=-g -W -Wall -Werror -fexceptions -std=c11 -pedantic -D_GNU_SOURCE -Iinclude

LDFLAGS= -lsndfile

readwav: readwav.o
	$(CC) -o readwav readwav.o $(LDFLAGS)

readwav.o: readwav.c
	$(CC) -c readwav.c $(CFLAGS) 

