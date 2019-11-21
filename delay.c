#include "delay.h"

void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 120; y > 0 ; y--);
}