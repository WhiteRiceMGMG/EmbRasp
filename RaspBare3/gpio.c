#include "gpio.h"
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 
 #define BLOCK_SIZE (4 * 1024)
 
 volatile GPIORegisters *gpio;
  
  void gpio_init() {
	       int mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
	            if (mem_fd < 0) {
			             perror("open /dev/mem");
				              exit(1);
					           }
		     
		         void *gpio_map = mmap(
					          NULL,
						           BLOCK_SIZE,
							            PROT_READ | PROT_WRITE,
								             MAP_SHARED,
									              mem_fd,
										               GPIO_BASE
											            );
			  
			      if (gpio_map == MAP_FAILED) {
				               perror("mmap");
					                close(mem_fd);
							         exit(1);
								      }
			       
			           gpio = (volatile GPIORegisters *)gpio_map;
				    
				        close(mem_fd);
					 }
 
 void gpio_set_output(int pin) {
	      int reg = pin / 10;
	           int shift = (pin % 10) * 3;
		        gpio->GPFSEL[reg] &= ~(0b111 << shift);
			     gpio->GPFSEL[reg] |=  (0b001 << shift); // Output mode
								     //  }
								     //   
								     //    void gpio_write(int pin, int value) {
								     //         if (value)
								     //                  gpio->GPSET[pin / 32] = (1 << (pin % 32));
								     //                       else
								     //                                gpio->GPCLR[pin / 32] = (1 << (pin % 32));
								     //                                 }
