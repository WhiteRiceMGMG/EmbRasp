AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
BINCRC = ../tools/bincrc
BIN2UF2 = ../tools/bin2uf2

MCPU = -mcpu=cortex-m0plus
ASFLAGS = $(MCPU)
CFLAGS = $(MCPU) -ffreestanding -nostartfiles -O0 -fpic -mthumb -c
LDFLAGS = --no-relax -nostdlib

all: tools led.uf2

clean:
	rm -f *.o *.elf *.uf2 *.bin
	cd ../tools && make clean

.s.o:
	$(AS) $(ASFLAGS) -o $@ $<

led.elf: boot2.o main.o memmap.ld
	$(LD) $(LDFLAGS) -o $@ -T memmap.ld boot2.o main.o 

led.bin: led.elf
	$(OBJCOPY) -O binary led.elf $@

led.uf2: led.bin
	$(BINCRC) led.bin led_crc.bin
	$(BIN2UF2) led_crc.bin $@

flash: all
	mount /dev/disk/by-label/RPI-RP2 /mnt
	cp led.uf2 /mnt

tools:
	cd ../tools && make