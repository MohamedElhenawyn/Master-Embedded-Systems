#include "uart.h"

unsigned char string_buffer[100] = "Learn-in-depth:Mohamed Elhenawy";

void main(void)
{
	Uart_send_string(string_buffer);
}