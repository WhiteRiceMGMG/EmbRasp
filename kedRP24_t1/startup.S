/*多分これbss dataの初期化がないから追加する．それか全部Cで書くか？*/
.syntax unified
.cpu cortex-m0plus
.thumb

.global __stack_pointer, __reset_handler

/* スタックポインタを定義：これはROMではなくRAM用 */
.section .stack_pointer,"a",%progbits
__stack_pointer:
    .word __stack_top

/* ベクタテーブル：ROMに配置される */
.section .vectors,"a",%progbits
__vectors:
    .word __stack_top     /* スタック初期値 */
    .word __reset_handler /* リセットベクタ */

.thumb_func
.global __reset_handler
.section .text.__reset_handler,"ax",%progbits
__reset_handler:
    ldr r0, =__stack_top
    mov sp, r0

    bl main

hang:
    b hang
