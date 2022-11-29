CC = gcc
CFLAGS = -std=c11 -Wall -fmax-errors=10 -Wextra -O0 -ggdb3
LFLAGS =
LIBS = -I.
OBJFILES = main.o FIFO.o
Program_name = main

all:$(Program_name)

$(Program_name):$(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBS) -o $(Program_name)
%.o:%.c
	$(CC) $(CFLAGS)  -c $< -o $@
clean:
	rm -f $(OBJFILES) $(Program_name)