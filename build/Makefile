CC=gcc
CFLAGS=-std=c99 -c -Wall -Wpedantic -Werror -Wundef
SRC=../src
OBJ=universal_interpreter.o instructions.o

edit : $(OBJ)
	$(CC) -o unin $(OBJ)

universal_interpreter.o : $(SRC)/universal_interpreter.c
	$(CC) $(CFLAGS) $(SRC)/universal_interpreter.c

instructions.o : $(SRC)/instructions.c $(SRC)/instructions.h
	$(CC) $(CFLAGS) $(SRC)/instructions.c

.PHONY : clean
clean :
	rm unin $(OBJ)
