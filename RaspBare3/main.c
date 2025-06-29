#include "gpio.h"
 #include <unistd.h>
 
 int main() {
	      gpio_init();
	       
	           int pin = 17; // BCM GPIO17（物理ピン11）
				 //  
				 //       gpio_set_output(pin);
				 //        
				 //             while (1) {
				 //                      gpio_write(pin, 1); // ON
				 //                               sleep(1);
				 //                                        gpio_write(pin, 0); // OFF
				 //                                                 sleep(1);
				 //                                                      }
				 //                                                       
				 //                                                            return 0;
				 //                                                             }
