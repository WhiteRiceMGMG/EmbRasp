#include "gpio.h"
#include <unistd.h>

int main(void) {
	gpio_init();
	int pin = 17;
	gpio_set_output(pin);

	while(1) {
		gpio_write(pin, 1);
		sleep(1);
		gpio_write(pin, 0);
		sleep(1);
	}
	return 0;
}
