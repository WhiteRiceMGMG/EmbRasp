/*
 * main.c
 *
 *  Created on: 2025/07/25
 *      Author: shion
 */
#include <kedknl.h>
//#include "../include/KedDriver.h"
#include <KedDriver.h>

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
    tm_com_init();                      /* デバッグ出力の初期化 */
    tm_putstring("hello,world\n");      /* デバッグ出力 */

    while(1) {
        if (Ked.Button.On()) {    // GPIO18が1ならボタン押されてる（プルアップ設定なら押してないときは1、押すと0なので反転判定に注意）
            //out_w(GPIO_OUT_SET, (1 << 17));  // LED ON
        	Ked.Led.On();
        } else {
            //out_w(GPIO_OUT_CLR, (1 << 17));  // LED OFF
        	Ked.Led.Off();
        }
        delay_ms(50);  // ボタンのチャタリング防止とCPU負荷軽減
    }
    return 0;
}


