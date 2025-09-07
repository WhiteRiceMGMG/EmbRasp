#define KEDDRIVER_H_
#include "kedknl.h"
#include "Led.h"
#include "Button.h"

typedef struct
{
	LedDriver Led;
	ButtonDriver Button;
} KedDriver;

extern KedDriver Ked;

#endif