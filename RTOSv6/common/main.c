/*
 * main.c
 *
 *  Created on: 2025/07/25
 *      Author: shion
 */
#include <kedknl.h>

/* 時間待ち関数 */
static void delay_ms( UINT ms)
{
    UINT cnt = ms/TIMER_PERIOD;

    while(cnt) {
        if((in_w(SYST_CSR) & SYST_CSR_COUNTFLAG)!=0) {  /* TIMER_PERIOD経過するとフラグがセット */
            cnt--;
        }
    }
}


int main(void)
{
	u1 num = 0;
    tm_com_init();                      /* デバッグ出力の初期化 */
    tm_putstring("hello,world\n");      /* デバッグ出力 */

    while(1) {
        if (in_w(GPIO_IN) & (1 << 18)) {    // GPIO18が1ならボタン押されてる（プルアップ設定なら押してないときは1、押すと0なので反転判定に注意）
            out_w(GPIO_OUT_SET, (1 << 15));  // LED ON
        } else {
            out_w(GPIO_OUT_CLR, (1 << 15));  // LED OFF
        }

        if (in_w(GPIO_IN) & (1 << 20)) {    // GPIO18が1ならボタン押されてる（プルアップ設定なら押してないときは1、押すと0なので反転判定に注意）
            out_w(GPIO_OUT_SET, (1 << 13));  // LED ON
        } else {
            out_w(GPIO_OUT_CLR, (1 << 13));  // LED OFF
        }

        if (in_w(GPIO_IN) & (1 << 16)) {    // GPIO18が1ならボタン押されてる（プルアップ設定なら押してないときは1、押すと0なので反転判定に注意）
            out_w(GPIO_OUT_SET, (1 << 11));  // LED ON
        } else {
            out_w(GPIO_OUT_CLR, (1 << 11));  // LED OFF
        }

        if (in_w(GPIO_IN) & (1 << 22)) {    // GPIO18が1ならボタン押されてる（プルアップ設定なら押してないときは1、押すと0なので反転判定に注意）
            out_w(GPIO_OUT_SET, (1 << 9));  // LED ON
        } else {
            out_w(GPIO_OUT_CLR, (1 << 9));  // LED OFF
        }

        delay_ms(50);  // ボタンのチャタリング防止とCPU負荷軽減
    }
    return 0;
}


