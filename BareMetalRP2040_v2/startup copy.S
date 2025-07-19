/*アセンブラ構文モードの宣言*/
.syntax unified
/*使用しているCPUの型番を指定*/
.cpu cortex-m0plus
/*Thumb命令セットを使う宣言*/
.thumb

/*他ファイルから参照できるように*/
.global __stack_pointer, __reset_handler

/*スタックポインタ用のセクションを定義*/
/* スタックポインタを定義：これはROMではなくRAM用 */
.section .stack_pointer,"a",%progbits

/*スタックの初期値(RAMの上端)を設定*/
__stack_pointer:
    .word __stack_top

/* ベクタテーブル：ROMに配置される 0x10000000に配置される */
.section .vectors,"a",%progbits
/*ベクタテーブルの中身 スタックポインタの初期値，リセットベクタ*/
__vectors:
    .word __stack_top     /* スタック初期値 */
    .word __reset_handler /* リセットベクタ */

/*リセットハンドラー関数を定義する準備．*/
/*.thumb_fncはこの関数はthumb用であることをGDBやリンカに伝える*/
.thumb_func
.global __reset_handler

/*実際の処理本体を各セクション*/
/**/
.section .text.__reset_handler,"ax",%progbits
__reset_handler:
    ldr r0, =__stack_top
    mov sp, r0

    bl main

hang:
    b hang
