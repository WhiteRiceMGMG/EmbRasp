    .syntax unified
    .thumb
    .section .text
    .global _start

_start:
    /* 1. スタック初期化 */
    ldr   r0, =0x2004C000   /* SRAM の末尾 */
    mov   sp, r0

    /* 2. IO_BANK0 (bit5) と PADS_BANK0 (bit6) のリセット解除 */
    ldr   r0, =(1<<5)|(1<<6)
    ldr   r1, =0x4000C000   /* RESETS_BASE */
    str   r0, [r1]          /* RESETS_RESET */
wait_resets:
    ldr   r2, [r1, #4]      /* RESETS_DONE */
    ands  r2, r2, r0
    beq   wait_resets

    /* 3a. PADS_BANK0 でピン17のドライブ強度／プルなし設定 */
    ldr   r0, =0x4001C000   /* PADS_BANK0_BASE */
    ldr   r1, =(8*17)       /* offset = 8 × PIN */
    movs  r2, #0x100        /* 4mA drive, pull-none */
    str   r2, [r0, r1]

    /* 3b. IO_BANK0 でピン17を SIO(ALT5) モードに */
    ldr   r0, =0x40014000   /* IO_BANK0_BASE */
    ldr   r1, =(8*17)       /* offset = 8 × PIN */
    movs  r2, #5            /* ALT5 = SIO */
    str   r2, [r0, r1]

    /* 4. SIO 側で出力有効化 */
    ldr   r0, =(1<<17)
    ldr   r1, =0xD0000024   /* SIO_GPIO_OE_SET */
    str   r0, [r1]

    /* 5. トグルループ */
    mov   r5, r0           /* toggle mask */
loop:
    ldr   r1, =0xD000001C   /* SIO_GPIO_OUT_XOR */
    str   r5, [r1]
    bl    delay
    b     loop

/* 適当ディレイ */
delay:
    mov   r0, #0x3FFFF     /* 約 2^18 ループ */
1:  subs  r0, r0, #1
    bne   1b
    bx    lr
