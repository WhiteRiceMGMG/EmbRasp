int main(void)
{
    while(1)
    {
        IO_BANK0_GPIO25_CTRL = 5;         // GPIO25をSIO機能に設定
        SIO_GPIO_OE_SET = (1 << 25);      // GPIO25を出力に設定
        SIO_GPIO_OUT_SET = (1 << 25);     // GPIO25をHigh（LED点灯）
    }
    return 0;
}