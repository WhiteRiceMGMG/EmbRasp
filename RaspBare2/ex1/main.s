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
    /* 初期化と点滅処理はここに同じように続けてOK */
