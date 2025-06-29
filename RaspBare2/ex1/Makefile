AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=cortex-m0 -mthumb

all: main.uf2

main.elf: build/boot2.o build/main.o
	$(LD) -T memmap.ld -o main.elf build/boot2.o build/main.o

build/boot2.o: boot2.s
	$(AS) $(CFLAGS) -o build/boot2.o boot2.s

build/main.o: main.s
	$(AS) $(CFLAGS) -o build/main.o main.s

main.bin: main.elf
	$(OBJCOPY) -O binary main.elf main.bin

main_crc.bin: main.bin
	../tools/bincrc main.bin main_crc.bin

main.uf2: main_crc.bin
	cp main_crc.bin main.uf2

clean:
	rm -f build/*.o *.elf *.bin *.uf2
