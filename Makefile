SRC = pin.c scanner.c grammar.c token.c
OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -O3 -Wall -ansi
LIBS = -lgmp
RAGEL = ragel
LEMON = lemon

OUT = pin

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)

grammar.c: grammar.y
	$(LEMON) grammar.y
	$(CC) $(CFLAGS) -c $@

scanner.c: scanner.rl scanner.h
	$(RAGEL) -C scanner.rl
	$(CC) $(CFLAGS) -c $@

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

.PHONY: clean
