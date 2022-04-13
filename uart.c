#include "uart.h"

char rxBuffer[RX_BUFFER_SIZE];
static uint8_t rxReadPos = 0;
static uint8_t rxWritePos = 0;


void uart_Init(void)
{
	UBRR0H = (BRC >> 8);
	UBRR0L = BRC;
	UCSR0B = (1 << TXEN0) | (1 << RXEN0) | (1 << RXCIE0);
	/*no stop bit no parity, 8bit frame*/
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	sei();
}

void uart_putChar(char c)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = c;
}

char uart_getChar(void)
{
	char ret = '\0';
	if (rxReadPos != rxWritePos)
	{
		ret = rxBuffer[rxReadPos];
		rxReadPos++;
		if (rxReadPos >= RX_BUFFER_SIZE)
		{
			rxReadPos = 0;
		}
	}
	return ret;
}

uint8_t uart_available(void)
{
	
	if(uart_getChar()==AVAILABLE_SYMBOL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}




ISR(USART0_RX_vect)
{
	rxBuffer[rxWritePos] = UDR0;
	rxWritePos++;

	if (rxWritePos >= RX_BUFFER_SIZE)
	{
		rxWritePos = 0;
	}
}