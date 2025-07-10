/* 
 *** Try Kernel
 *      システムライブラリ 
 * UART初期化と文字列送信関数
 * UART0を初期化して，文字列を送信できるようにするシステムライブラリ
 * これは退けてもいいかも
*/
#include <trykernel.h>
#include <knldef.h>

/* UART0の初期化 */
void tm_com_init(void)
{
    out_w(UART0_BASE+UARTx_IBRD, 67);                               /* ボーレート設定 */
    out_w(UART0_BASE+UARTx_FBRD, 52);
    out_w(UART0_BASE+UARTx_LCR_H, 0x70);                            /* データ形式設定 */
    out_w(UART0_BASE+UARTx_CR, UART_CR_RXE|UART_CR_TXE|UART_CR_EN); /* 通信イネーブル */
    /*RXE受信有効，TXE送信有効，UARTモジュール全体を有効化*/
}


/* デバッグ用UART出力 */
/*文字列を一文字ずつUART送信する関数*/
UINT tm_putstring(char* str)
{
    UINT	cnt = 0;

    /**strがNULLでない限りループ．
     * UARTx_FRフラグレジスタを読んで，TXFF(送信FIFOが満杯)をチェック
     * UARTx_DRデータレジスタに一文字書き込む
     */
    while(*str) {
        while((in_w(UART0_BASE+UARTx_FR) & UART_FR_TXFF)!= 0);  /* 送信FIFOの空き待ち */
        out_w(UART0_BASE+UARTx_DR, *str++);                     /* データ送信 */
        cnt++;
    }
    return cnt;
}

/*システムクロックが48MHZ，UARTクロックが3MHZなら
UARTボーレート計算式
*/