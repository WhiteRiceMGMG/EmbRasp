    .syntax unified
    .thumb

    .section .vector_table, "a"
    .global vectors
vectors:
    .word 0x2004C000
    .word reset + 1

    .section .text
    .global reset
reset:
    /* ① SP 初期化 */
    ldr   r0, =0x2004C000
    mov   sp, r0

    /* ② IO/PADS リセット解除 */
    ldr   r0, =((1<<5)|(1<<6))
    ldr   r1, =0x4000C000
    str   r0, [r1]
wait_resets:
    ldr   r2, [r1, #4]
    ands  r2, r2, r0
    beq   wait_resets

    /* ③ PADS_BANK0 でピン17設定 */
    ldr   r0, =0x4001C000
    ldr   r1, =136
    ldr   r2, =0x100
    str   r2, [r0, r1]

    /* ④ IO_BANK0 でピン17→SIO */
    ldr   r0, =0x40014000
    ldr   r1, =136
    movs  r2, #5
    str   r2, [r0, r1]

    /* ⑤ SIO 側で OE_SET */
    ldr   r0, =(1<<17)
    ldr   r1, =0xD0000024
    str   r0, [r1]

    b     blink_loop

    .global blink_loop
blink_loop:
    ldr   r1, =0xD000001C
    str   r0, [r1]
    bl    delay
    b     blink_loop

delay:
    ldr   r0, =0x3FFFF
1:  subs  r0, r0, #1
    bne   1b
    bx    lr
