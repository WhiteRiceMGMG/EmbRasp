/****************************************************
*メモリ関連 (SRAM)，クロック関連(CLOCKS)，クロック種別定数，
*リセットコントローラ，GPIO制御，XOSC外部クリスタル，
*PLL，UART，SIO，SysTick，クロック定数，割り込み優先度
****************************************************/



#ifndef SYSDEF_H
#define SYSDEF_H
/*
 *** Try Kernel
 *          システム（ハードウェア）関連共通定義
 */

/* メモリ関連 */
#define SRAM_START              (0x20000000)
#define SRAM_SIZE               (256*1024)

#define	INITIAL_SP              (SRAM_START + SRAM_SIZE)

/* APB ペリフェラル */
/* Clocks */
#define CLOCKS_BASE             0x40008000                 /*クロック制御ブロックのアドレス*/
#define CLK_GPOUT0              (CLOCKS_BASE+0x00)         /*出力クロックの周波数，ソースなどを設定*/
#define CLK_GPOUT1              (CLOCKS_BASE+0x0C)
#define CLK_GPOUT2              (CLOCKS_BASE+0x18)
#define CLK_GPOUT3              (CLOCKS_BASE+0x24)
#define CLK_REF	                (CLOCKS_BASE+0x30)          /*参照クロック*/
#define CLK_SYS	                (CLOCKS_BASE+0x3C)          /*システムクロック*/      
#define CLK_PERI                (CLOCKS_BASE+0x48)          /*周辺機器クロック*/
#define CLK_USB	                (CLOCKS_BASE+0x54)          /*USB周辺機器変換クロック*/
#define CLK_ADC	                (CLOCKS_BASE+0x60)          /*アナログデジタル変換クロック*/
#define CLK_RTC	                (CLOCKS_BASE+0x6C)          /*リアルタイムクロック*/
#define CLK_SYS_RESUS_CTRL      (CLOCKS_BASE+0x78)          /*クロックの有効化，ソース選択*/
#define CLK_SYS_RESUS_STATUS    (CLOCKS_BASE+0x7C)          /*クロックの分周比*/

#define	CLK_x_CTRL              (0x00)                      /*どのクロックをどう使うか*/
#define	CLK_x_DIV               (0x04)                      /*クロックをどれだけ早くするか*/
#define	CLK_x_SELECTED          (0x08)                      /*現在どのクロックが使われているか*/

#define CLK_SYS_CTRL_AUXSRC     (0x000000e0)                /*クロックないの補助クロックのうち，使うもののビットを立てる*/
#define CLK_SYS_CTRL_SRC        (0x00000001)                /*AUXを使うかどうかを決める*/
#define CLK_REF_CTRL_SRC        (0x00000003)                /*REFクロックのソースを選ぶビット領域*/
#define CLK_CTRL_ENABLE	        (0x00000800)                /*このビットを立てると，クロックが有効になる．*/

#define CLK_SYS_CTRL_SRC_AUX	(0x1)                       /*SYSクロックのソースとしてAUXを使う．CLK_SYS_STRL_SRCにこの値を設定するとAUXが有効に*/

#define CLK_KIND_GPOUT0         0                           /*クロック出力を表す定数．GPIOピンにこのクロックを出力*/
#define CLK_KIND_GPOUT1         1                           /**/
#define CLK_KIND_GPOUT2         2                           /**/
#define CLK_KIND_GPOUT3         3                           /**/
#define CLK_KIND_REF            4                           /*タイミングの基準となるクロック*/
#define CLK_KIND_SYS            5                           /*CPU．システムの中核で使われるクロック*/
#define CLK_KIND_PERI           6                           /*SPI，I2C，UARTなど周辺機器に使われるクロック*/
#define CLK_KIND_USB            7                           /*USB通信で必要となる正確なクロック*/
#define CLK_KIND_ADC            8                           /*アナログデジタル変換起用クロック*/
#define CLK_KIND_RTC            9                           /*リアルタイムようクロック，時刻を計測する用途のクロック*/

/* Reset Controler */
#define RESETS_BASE             0x4000C000                  /*リセットコントローラのベースアドレス*/
#define RESETS_RESET            (RESETS_BASE+0x0)           /*各モジュールをリセットするためのレジスタ*/
#define RESETS_WDSEL            (RESETS_BASE+0x4)           /*ウォッチドッグリセット時に影響を与えるモジュールを選ぶ*/
#define RESETS_RESET_DONE       (RESETS_BASE+0x8)           /*リセットが完了したか確認するレジスタ*/

#define RESETS_RESET_ADC        (0x00000001)                /*アナログデジタル変換器をリセットするビット*/
#define RESETS_RESET_I2C0       (0x00000008)                /*I2C0モジュールをリセットするビット*/
#define RESETS_RESET_I2C1       (0x00000010)                /**/

/* GPIO */
#define IO_BANK0_BASE           0x40014000
#define	GPIO_CTRL(n)            (IO_BANK0_BASE+0x04+(n*8))

#define	GPIO_CTRL_FUNCSEL_I2C   3
#define	GPIO_CTRL_FUNCSEL_NULL  31

#define PADS_BANK0_BASE         0x4001c000
#define	GPIO(n)                 (PADS_BANK0_BASE+0x4+(n*4))

#define	GPIO_OD                 (1<<7)
#define	GPIO_IE                 (1<<6)
#define	GPIO_DRIVE_2MA          (0<<4)
#define	GPIO_DRIVE_4MA          (1<<4)
#define	GPIO_DRIVE_8MA          (2<<4)
#define	GPIO_DRIVE_12MA         (3<<4)
#define	GPIO_PUE                (1<<3)
#define	GPIO_PDE                (1<<2)
#define	GPIO_SHEMITT            (1<<1)
#define	GPIO_SLEWDAST           (1<<0)

/* Crystal Oscillator(XOSC) */
#define XOSC_BASE               0x40024000
#define XOSC_CTRL               (XOSC_BASE+0x00)
#define XOSC_STATUS             (XOSC_BASE+0x04)
#define XOSC_STARTUP            (XOSC_BASE+0x0C)

#define	XOSC_CTRL_ENABLE        (0x00FAB000)
#define	XOSC_CTRL_DISABLE       (0x00D1E000)
#define	XOSC_CTRL_FRANG_1_15MHZ (0x00000AA0)

#define	XOSC_STATUS_STABLE      (0x80000000)

/* PLL */
#define PLL_SYS_BASE            (0x40028000)
#define PLL_USB_BASE            (0x4002C000)

#define PLL_CS                  (0x00)
#define	PLL_PWR                 (0x04)
#define	PLL_FBDIV_INT           (0x08)
#define	PLL_PRIM                (0x0C)

#define	PLL_CS_LOCK             (1<<31)
#define	PLL_PWR_PD              (1<<0)
#define	PLL_PWR_VCOPD           (1<<5)
#define	PLL_PWR_POSTDIVPD       (1<<3)
#define PLL_PRIM_POSTDIV1_LSB   (16)
#define PLL_PRIM_POSTDIV2_LSB   (12)

/* UART */
#define UART0_BASE              0x40034000
#define UART1_BASE              0x40038000

#define UARTx_DR                (0x000)
#define UARTx_FR                (0x018)
#define UARTx_IBRD              (0x024)
#define UARTx_FBRD              (0x028)
#define UARTx_LCR_H             (0x02C)
#define UARTx_CR                (0x030)

#define UART_CR_RXE             (1<<9)
#define UART_CR_TXE             (1<<8)
#define UART_CR_EN              (1<<0)
#define UART_FR_TXFF            (1<<5)

/* IOPORT レジスタ */
#define SIO_BASE                0xD0000000
#define	GPIO_IN                 (SIO_BASE+0x04)
#define GPIO_OUT                (SIO_BASE+0x10)
#define GPIO_OUT_SET            (SIO_BASE+0x14)
#define GPIO_OUT_CLR            (SIO_BASE+0x18)
#define GPIO_OUT_XOR            (SIO_BASE+0x1C)
#define GPIO_OE_SET             (SIO_BASE+0x24)
#define GPIO_OE_CLR             (SIO_BASE+0x28)
#define GPIO_OE_XOR             (SIO_BASE+0x2C)

/* SysTick レジスタ */
#define SYST_CSR                (0xE000E010)
#define SYST_RVR                (0xE000E014)
#define SYST_CVR                (0xE000E018)

#define SYST_CSR_COUNTFLAG      (1<<16)
#define SYST_CSR_CLKSOURCE      (1<<2)
#define SYST_CSR_TICKINT        (1<<1)
#define SYST_CSR_ENABLE	        (1<<0)

/* クロック周波数 */
#define	CLOCK_XOSC              (12000000UL)
#define	CLOCK_REF               (CLOCK_XOSC)
#define	CLOCK_PERI              (CLOCK_SYS)

#define	XOSC_MHz                (12)
#define	XOSC_KHz                (XOSC_MHz*1000)

#define	TMCLK_MHz               (125)
#define	TMCLK_KHz               (TMCLK_MHz*1000)
#define	TIMER_PERIOD            (10)

#define	KHz                     (1000)
#define	MHz                     (KHz*1000)

/* NVIC レジスタ */
#define SCB_SHPR3               (0xE000ED20)

#define	INTLEVEL_0              (0x00)
#define	INTLEVEL_1              (0x40)
#define	INTLEVEL_2              (0x80)
#define	INTLEVEL_3              (0xC0)

#endif  /* SYSDEF_H */