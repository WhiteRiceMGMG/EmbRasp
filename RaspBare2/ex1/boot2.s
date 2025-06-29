.section .boot2
.global _start
_start:
	ldr r3, rom_base
	ldrh r0, [r3, #0x14]           // rom_func_table
	ldr r1, =('C' | 'X' << 8)      // _flash_enter_cmd_xip()
	ldrh r2, [r3, #0x18]           // rom_table_lookup
	blx r2
	blx r0

	ldr r0, =vectors
	ldr r1, m0plus_vtor
	str r0, [r1, #0]
	ldr r1, [r0, #4]
	ldr r0, [r0, #0]
	mov sp, r0
	bx r1

rom_base:
	.word 0x00000000
m0plus_vtor:
	.word 0xe000ed08
