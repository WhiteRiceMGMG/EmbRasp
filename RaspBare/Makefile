CROSS = arm-none-eabi
GCCVER = 15.1.0
GCCROOT = /usr/local/Cellar/arm-none-eabi-gcc/$(GCCVER)

CFLAGS = -mcpu=cortex-m0 -mthumb -nostdlib -Wall -Os \
  -I/usr/local/Cellar/arm-none-eabi-gcc/15.1.0/lib/gcc/arm-none-eabi/15.1.0/include \
  -I/usr/local/Cellar/arm-none-eabi-gcc/15.1.0/lib/gcc/arm-none-eabi/15.1.0/include-fixed



all: main.uf2

main.elf: startup.o main.o
	$(CROSS)-ld -T link.ld startup.o main.o -o main.elf

main.o: main.c
	$(CROSS)-gcc $(CFLAGS) -c main.c -o main.o

startup.o: startup.S
	$(CROSS)-gcc $(CFLAGS) -c startup.S -o startup.o

main.bin: main.elf
	$(CROSS)-objcopy -O binary main.elf main.bin

main.uf2: main.bin
	python3 uf2conv.py main.bin -c -b 0x10000000 -o main.uf2

clean:
	rm -f *.o *.elf *.bin *.uf2
