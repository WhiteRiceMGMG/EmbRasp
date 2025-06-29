MEMORY
{
	FLASH(rx) : ORIGIN = 0x10000000, LENGTH = 2048k
}

SECTIONS
{
	.boot2 : {
		*(.boot2)
		. = 0x100;
	} > FLASH

	.text : {
		*(.text)
	} > FLASH
}
