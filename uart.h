#ifndef UART_H
#define UART_H

#define BAUD 9600
#define BRC ((F_CPU / (16UL * BAUD)) - 1)
#define RX_BUFFER_SIZE 128

#define AVAILABLE_SYMBOL '\n'

void uart_Init(void);
void uart_putChar(char c);
char uart_getChar(void);
uint8_t uart_available(void);

static FILE Serial_print = FDEV_SETUP_STREAM(Serial_put_char, NULL, _FDEV_SETUP_WRITE);
static FILE Serial_read = FDEV_SETUP_STREAM(NULL, Serial_get_char, _FDEV_SETUP_READ);

#endif UART_H
