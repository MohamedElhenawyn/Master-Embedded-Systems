CC = gcc
CFLAGS = -std=c11 -Wall -fmax-errors=10 -Wextra -O0 -ggdb3
LFLAGS =
LIBS = -I.
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

Program_name = main

all:$(Program_name)

$(Program_name):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(Program_name)
%.o:%.c
	$(CC) $(CFLAGS)  -c $< -o $@
clean:
	rm -f $(OBJ) $(Program_name)