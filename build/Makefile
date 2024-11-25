DC=gdc
CC=gcc
SRC=../src
DFLAGS=-c -Wall -Wpedantic -Werror -I $(SRC)
CFLAGS=-std=c11 -c -Wall -Wpedantic -Werror -Wundef
OBJ=universal_interpreter.o op_meta.o instructions.o

edit : $(OBJ)
	$(DC) -o unin $(OBJ)

op_meta.o : $(SRC)/op_meta.d $(SRC)/instructions.c $(SRC)/instructions.h
	$(DC) $(DFLAGS) $(SRC)/op_meta.d

universal_interpreter.o : $(SRC)/universal_interpreter.d $(SRC)/op_meta.d
	$(DC) $(DFLAGS) $(SRC)/universal_interpreter.d


instructions.o : $(SRC)/instructions.c $(SRC)/instructions.h
	$(CC) $(CFLAGS) $(SRC)/instructions.c


.PHONY : clean
clean :
	rm unin $(OBJ)
