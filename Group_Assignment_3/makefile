all: divideAndConquer

divideAndConquer: divideAndConquer.o 
	gcc -o divideAndConquer divideAndConquer.o 

divideAndConquer.o: divideAndConquer.c myLibrary.h
	gcc -g divideAndConquer.c myLibrary.h -lm

##testOne.o: testOne.c myLibrary.h
##	gcc testOne.c -lm
