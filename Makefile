Hw3 : main3.o printMenu.o Homework3.o  
	gcc main3.o printMenu.o Homework3.o -o Hw3

main3.o : main3.c printMenu.c Homework3.c record.h main3.h
	gcc -ansi -Wall -c main3.c

printMenu.o : printMenu.c
	gcc -ansi -Wall -c printMenu.c

Homework3.o : Homework3.c record.h  main3.h
	gcc -ansi -Wall -c Homework3.c

clean :
	rm *.o Hw3
