#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "uart.h"

/*Example*/

void main(void)
{
	
uart_init();


while(1)
{

fprintf(&Serial_print,"testing %u %u %u"\n\r,1,2,3);

}

}