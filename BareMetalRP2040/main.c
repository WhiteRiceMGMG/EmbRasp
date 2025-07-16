// main.c
#include <stdint.h>

// RESETSレジスタ（アドレス0x4000C000）の定義
#define RESETS_BASE             0x4000C000
#define RESETS_RESET            (*(volatile uint32_t*)(RESETS_BASE + 0x00))
#define RESETS_RESET_IO_BANK0   (1u << 5)
#define RESETS_RESET_PADS_BANK0 (1u << 8)
#define RESETS_RESET_DONE       (*(volatile uint32_t*)(RESETS_BASE + 0x08))

// SIOレジスタ（アドレス0xD0000000）の定義
#define SIO_BASE        0xD0000000
#define SIO_GPIO_OE_SET (*(volatile uint32_t*)(SIO_BASE + 0x024))
#define SIO_GPIO_OUT_SET (*(volatile uint32_t*)(SIO_BASE + 0x014))

// IO_BANK0 GPIO_CTRLレジスタのオフセット計算マクロ
#define IO_BANK0_BASE   0x40014000
#define IO_BANK_GPIO_CTRL(gpio) (*(volatile uint32_t*)(IO_BANK0_BASE + (gpio)*0x08 + 0x04))
#define FUNCSEL_SIO     5u  // SIO機能のFUNCSELコード

int main(void) {
    // IO_BANK0およびPADS_BANK0のリセット解除
    RESETS_RESET &= ~RESETS_RESET_IO_BANK0;
    RESETS_RESET &= ~RESETS_RESET_PADS_BANK0;
    // リセット解除完了待ち（必要ならループで待つ）
    while ((RESETS_RESET_DONE & (RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0)) !=
           (RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0)) {
        // ウェイト（NOP等）
    }
    // GPIO17をSIO出力に設定
    IO_BANK_GPIO_CTRL(17) = FUNCSEL_SIO;
    // 出力イネーブルON（GPIO17を出力モードに）
    SIO_GPIO_OE_SET = (1u << 17);
    // LEDを点灯（出力Highに設定）
    while (1) {
        SIO_GPIO_OUT_SET = (1u << 17);
        // 必要なら他の処理を入れてもよい
    }
    // return 0; // 到達しない
}
