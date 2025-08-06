MEMORY {
    ROM (rx) : ORIGIN = 0x10000000, LENGTH = 2048K
    RAM (rwx): ORIGIN = 0x20000000, LENGTH = 256K
}

ENTRY(__boot2_start)

SECTIONS {
    /* --- boot2 (必ず先頭に配置) --- */
    .boot2 ORIGIN(ROM) : ALIGN(4) {
        KEEP(*(.boot2))
    } > ROM

    /* --- 実行コード本体 --- */
    .text : ALIGN(4) {
        *(.text.__reset_handler) /* reset_handlerを先頭に明示配置 */
        *(.text .text.*)
        *(.rodata .rodata.*)
    } > ROM

    .data : ALIGN(4) {
        __data_start = .;
        *(.data .data.*)
        __data_end = .;
    } > RAM AT > ROM

    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
