
OBJECT_LIB=myBank.o
OBJECT_MAIN=main.o
CFLAGS=-Wall -g
CC=gcc
##static dont work
all: static dynamic
static: mains libmyBank.a
dynamic: libmyBank.so maind
mains: $(OBJECTS_MAIN) libmyBank.a 
	$(CC) $(FLAGS) $(OBJECTS_MAIN) -lmyBank -L. -o mains
libmyBank.a: $(OBJECTS_LIB)
	$(AR) rcs libmyBank.a $(OBJECTS_LIB)
maind: $(OBJECT_MAIN) 
	$(CC) $(CFLAGS) -o maind $(OBJECT_MAIN) ./libmyBank.so
libmyBank.so: $(OBJECT_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECT_LIB)
myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c
.PHONY: clean dynamic static all

clean:
	rm -f *.o *.so *.a maind mains