CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -g -gdwarf-2
INCS = -I .
LIBS = 
SRC = $(wildcard *.c)
OBJ = $(SRC :.c=.o)

projectName = HPD

all:$(projectName).bin

%.o:%.c
	$(CC)gcc.exe $(CFLAGS) $(LIBS) $(INCS) -c $< -o $@
HPD.elf:$(OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@ -Map = Mapfile.map
HPD.bin:HPD.elf
	$(CC)objcopy.exe -O binary $< $@ 

clean:
	rm -rf *.o *.map *.elf *.hex *~
	@echo "Everything is clean"

