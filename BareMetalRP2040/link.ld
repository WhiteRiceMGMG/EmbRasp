/* link.ld — メモリマップとセクション配置 */
MEMORY {
    ROM (rx) : ORIGIN = 0x10000000, LENGTH = 2048K
    RAM (rwx): ORIGIN = 0x20000000, LENGTH = 256K
}
ENTRY(__reset_handler)

SECTIONS {
    .text : {
        KEEP(*(.data.__stack_pointer))    /* スタックポインタ */
        KEEP(*(.data.__vectors))          /* ベクターテーブル */
        *(.text .text.*)
        *(.rodata .rodata.*)
    } > ROM

    .data : {
        __data_start = .;
        *(.data .data.*)
        __data_end = .;
    } > RAM AT > ROM

    .bss : {
        __bss_start = .;
        *(.bss)
        __bss_end = .;
    } > RAM

    /* スタックポインタ用シンボルをRAM末尾に設定 */
    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
