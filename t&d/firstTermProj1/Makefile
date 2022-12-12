CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -g -gdwarf-2
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name=FirstTermProj

all:$(Project_name).bin
	@echo "build is done"

%.o: %.s
	$(CC)as.exe -c $(CFLAGS) $(INCS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) -c $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $(Project_name).elf -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
clean_all:
	rm -f *.o *.elf *.bin *.hex *.map
clean:
	rm -f *.elf *.bin


	
	