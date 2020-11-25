
OBJECT_LIB=myBank.o
OBJECT_MAIN=main.o
CFLAGS=-Wall -g
CC=gcc

dynamic: myBankd maind
maind: $(OBJECT_MAIN) 
	$(CC) $(CFLAGS) -o maind $(OBJECT_MAIN) ./libmyBank.so
myBankd: $(OBJECT_LIB)
	$(CC) -shared -o libmyBank.so $(OBJECT_LIB)
myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c
main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c
.PHONY: clean dynamic

clean:
	rm -f *.o *.so maind