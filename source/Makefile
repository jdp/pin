SRC = pin.c internal.c parser.c
OBJ = ${SRC:.c=.o}
CC = gcc
LEG = leg
OUT = pin

$(OUT): $(OBJ)
	$(CC) -o $@ $(OBJ)

parser.c: pin.leg
	$(LEG) pin.leg -o $@
	
.c.o: pin.h
	$(CC) -c $<
	
clean:
	rm *.o
	rm parser.c
	rm pin
	
PHONY: clean

