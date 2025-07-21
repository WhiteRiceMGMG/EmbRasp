フォルダ構成を整えてビルド成功．
次はRPの全機能を開放するために頑張りたい．

picoの動き
１．電源投入・リセット
電源オンされるとまずリセット状態に入る．
ここでboot romが有効になる

２．boot rom（0x000000000～）
アドレスは0x00000000にマッピングされる固定ROｍ
内容はUSB警手でファイル書き込みやQSPIフラッシュからの
プログラム読み込みなどを行う
bootsel ボタンの確認
qspiフラッシュの初期化．
ユーザプログラムの読み込み
エントリポインタ呼び出し


#define LED_PIN 17
static void Led_On(void) {
    SIO_GPIO_OUT_SET = (1u << LED_PIN);
}

LedController Led = {
    .On = Led_On,
    .Off = Led_Off,
    .Toggle = Led_Toggle,
};

#pragma once
#include "led.h"

typedef struct {
    LedController Led;
} KedSystem;

extern KedSystem Ked;

KedSystem Ked = {
    .Led = {
        .On = Led_On,
        .Off = Led_Off,
        .Toggle = Led_Toggle,
    }
};
Ked.Led.On();