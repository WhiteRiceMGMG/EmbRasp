	.section .text.startup
	.global _start
	.thumb
	.syntax unified

_start:
    ldr r0, =_stack_top
    mov sp, r0
    bl main

loop:
	b loop
