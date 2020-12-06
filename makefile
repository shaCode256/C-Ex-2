CC=gcc 
FLAGS= -Wall -g 

all: myBanks mains

myBanks: myBank.o myBank.h
	ar -rcs libmyBank.a myBank.o myBank.h	
	
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c -fPIC myBank.c
	
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c

mains: main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o libmyBank.a	

.PHONY: clean all
	   mains
clean: 
	rm -f *.o mains libmyBank.a