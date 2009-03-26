SRC = pin.c parser.c
OBJ = ${SRC:.c=.o}
CC = gcc
LEG = leg
OUT = pin

$(OUT): $(OBJ)
	$(CC) -o $@ $(OBJ)

parser.c: pin.leg
	rm parser.c
	$(LEG) pin.leg -o $@
	
.c.o:
	$(CC) -c $<
	
clean:
	rm *.o
	rm parser.c
	rm pin
	
PHONY: clean
