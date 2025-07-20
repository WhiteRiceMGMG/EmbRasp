MEMORY {
    ROM (rx) : ORIGIN = 0x10000000, LENGTH = 2048K
    RAM (rwx): ORIGIN = 0x20000000, LENGTH = 256K
}

ENTRY(__boot2_start)

SECTIONS 
	{
    .boot2 ORIGIN(ROM) : ALIGN(4) {
        KEEP(*(.boot2))
    } > ROM

    .vectors : ALIGN(4) {
        KEEP(*(.vectors))
    } > ROM

    .text : ALIGN(4) {
        *(.text.__reset_handler) 
        *(.text .text.*)
        *(.rodata .rodata.*)
    } > ROM

    .data : ALIGN(4) {
        __data_start = .;
        *(.data .data.*)
        __data_end = .;
    } > RAM AT > ROM

    .bss : ALIGN(4) {
        __bss_start = .;
        *(.bss .bss.*)
        *(COMMON)
        __bss_end = .;
    } > RAM

    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
