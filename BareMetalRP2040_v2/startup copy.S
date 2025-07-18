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
/*a:このセクションはメモリにロードされるべき*/
/*x:このセクションは実行可能なコードを含む*/
/*progbits:プログラムに必要な情報があるセクションである．*/
/*nobits:これは.bssセクション（初期値ゼロ）に使われる*/
.section .stack_pointer,"a",%progbits

/*スタックの初期値(RAMの上端)を設定*/
/*.wordの意味について．*/
/*.word __stack_top : 32bit値を埋め込む命令*/
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
/*.textという実行可能(a)かつ実効属性(x)のセクションにリセットハンドラーを配置する*/
.section .text.__reset_handler,"ax",%progbits

/*スタックポインタを初期化．*/
/*ldr r0, =__stack_topは__stack_topのアドレスをr0に読み込む．*/
/*mov sp, r0でCPUのスタックポインタをその値に設定する*/
/*これにより関数呼び出しやローカル変数が使えるようになる．*/
__reset_handler:
    ldr r0, =__stack_top
    mov sp, r0
/*main関数を呼び出す．bl は branch with linkはサブルーチンを呼び出す命令*/
    bl main

/*通常，mainは戻らない前提であるが，もし戻ったら無限ループして止める．*/
hang:
    b hang
