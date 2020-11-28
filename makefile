
OBJECT_LIB=myBank.o
OBJECT_MAIN=main.o
CFLAGS=-Wall -g
CC=gcc
AR=ar

all: static dynamic

static: mains libmyBank.a
mains: $(OBJECT_MAIN) libmyBank.a
	$(CC) $(CFLAGS) -o $@ $(OBJECT_MAIN) -L. -lmyBank
libmyBank.a: $(OBJECT_LIB)
	$(AR) rcs libmyBank.a $^

dynamic: libmyBank.so maind
maind: $(OBJECT_MAIN)
	$(CC) $(CFLAGS) -o $@ $(OBJECT_MAIN) ./libmyBank.so
libmyBank.so: $(OBJECT_LIB)
	$(CC) -shared -o $@ $^

myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean dynamic static all

clean:
	rm -f *.o *.so *.a maind mains