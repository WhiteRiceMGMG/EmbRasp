@ startup.S — Cortex-M0+リセットベクタとスタック設定
    .syntax unified
    .cpu cortex-m0plus
    .thumb

    .global __stack_pointer, __reset_handler

@ スタックポインタ（データセクション）: リンカスクリプトで定義される__stack_topを指す
    .section .data.__stack_pointer,"aw"
__stack_pointer:
    .word __stack_top

@ ベクターテーブル（データセクション）: リセットハンドラへのポインタ
    .section .data.__vectors,"aw"
__vectors:
    .word __reset_handler

@ リセットハンドラ
    .thumb_func
__reset_handler:
    @ スタックをRAM末尾に設定（リンカ定義の__stack_topを使用）
    ldr r0, =__stack_top
    mov sp, r0

    bl main       @ main() を呼び出し
hang:
    b hang        @ 終了しないようループ
