
#include "../include/kedknl.h"
int main(void)
{
	initial_ked();
	while (1)
	{
	    SIO_GPIO_OUT_SET = (1u << 17);

	}
}

