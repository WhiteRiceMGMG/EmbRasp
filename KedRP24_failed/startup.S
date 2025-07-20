/*
 * startup.S
 *
 *  Created on: 2025/07/20
 *      Author: shion
 */
.syntax unified
.cpu cortex-m0plus
.thumb

.global __stack_pointer, __reset_handler

.section .stack_pointer,"a",%progbits
__stack_pointer:
    .word __stack_top

.section .vectors,"a",%progbits
__vectors:
    .word __stack_top
    .word __reset_handler

.thumb_func
.global __reset_handler
.section .text.__reset_handler,"ax",%progbits
__reset_handler:
    ldr r0, =__stack_top
    mov sp, r0

    bl main

hang:
    b hang
