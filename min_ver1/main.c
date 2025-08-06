#define IO_BANK0_GPIO25_CTRL (*(volatile unsigned int *)0x400140CC)
#define SIO_GPIO_OE_SET      (*(volatile unsigned int *)0xD0000024)
#define SIO_GPIO_OUT_SET     (*(volatile unsigned int *)0xD0000014)

void main(void) {
    IO_BANK0_GPIO25_CTRL = 5;
    SIO_GPIO_OE_SET = (1 << 25);
    SIO_GPIO_OUT_SET = (1 << 25);
    while(1);
}

void __attribute__((naked)) __reset_handler(void) {
    main();
    while(1);
}
