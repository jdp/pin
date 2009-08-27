SRC = pin.c ast.c stack.c grammar.c interpret.c
OBJ = ${SRC:.c=.o}
CC = gcc
LEG = leg
OUT = pin

$(OUT): $(OBJ)
	$(CC) -o $@ $(OBJ)

grammar.c: grammar.leg
	$(LEG) grammar.leg -o $@
	
.c.o: pin.h
	$(CC) -c $<
	
clean:
	rm *.o
	rm grammar.c
	rm pin
	
PHONY: clean

