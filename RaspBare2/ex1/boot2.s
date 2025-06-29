.section .boot2, "a", %progbits
.global _start

_start:
    ldr r3, =0x00000000             // ROM base
    ldr r2, [r3, #0x18]             // rom_table_lookup
    ldr r1, =('C' | 'X' << 8)       // lookup code for _flash_enter_cmd_xip()
    blx r2                          // call lookup, result in r0
    blx r0                          // call _flash_enter_cmd_xip()

    // Set VTOR (Vector Table Offset Register) to our vector table
    ldr r0, =vectors
    ldr r1, =0xE000ED08             // SCB->VTOR
    str r0, [r1]

    // Load SP and PC from the vector table
    ldr r1, [r0, #4]                // Reset handler (PC)
    ldr r0, [r0]                    // Initial SP
    mov sp, r0
    bx r1

// 以下はベクタテーブル参照先のダミーアドレス
// 実際のリンク時に配置される
