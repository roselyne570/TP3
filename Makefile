CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -g
SRC = pile.c file.c calculatrice.c test_tp3.c
OBJ = pile.o file.o calculatrice.o test_tp3.o
BIN = test_tp3

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(BIN)
	./$(BIN)

clean:
	 rm -f $(OBJ) $(BIN)

.PHONY: all test clean
