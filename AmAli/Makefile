CC=
CFLAGS= -g -gdwarf-2
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=main

all:$(Project_name).exe
	@echo "build is done"

%.o: %.c
	gcc.exe -c $(CFLAGS) -c $< -o $@

$(Project_name).exe:$(OBJ)
	gcc.exe $(CFLAGS) $(INCS) $(OBJ) -o main.exe
clean_all:
	rm -f *.o *.elf *.bin *.hex *.map
clean:
	rm -f *.elf *.bin


	
	