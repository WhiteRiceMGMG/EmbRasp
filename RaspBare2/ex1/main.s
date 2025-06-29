.syntax unified
.thumb
.section .text
.global vectors

vectors:
    .word 0x20040000       // 初期スタックポインタ
    .word (reset + 1)      // リセットベクタ（Thumb）

reset:
    // GPIOのリセット解除
    ldr r0, =1 << 5        // r0 = (1 << 5)
    ldr r3, =0x4000c000
    ldr r1, =0x3000
    str r0, [r3, r1]

reset_wait:
    ldr r1, [r3, #8]
    tst r0, r1
    beq reset_wait

    // GPIO機能をSIOに設定
    ldr r3, =0x40014000
    movs r0, #5            // GPIO25
    movs r1, #0xcc         // GPIO25_CTRL
    str r0, [r3, r1]

    // GPIO25出力有効化
    ldr r3, =0xd0000000
    movs r0, #1
    lsls r0, r0, #17       // GPIO17
    str r0, [r3, #0x24]    // GPIO_OE


    // LED点滅ループ
    mov r5, r0
    ldr r4, =0xd0000000

loop:
    str r5, [r4, #0x1c]    // GPIO_OUT_XOR
    bl delay
    b loop

delay:
    ldr r0, =1 << 20       // 適当な待機ループ
delay_loop:
    subs r0, r0, #1
    bne delay_loop
    bx lr
