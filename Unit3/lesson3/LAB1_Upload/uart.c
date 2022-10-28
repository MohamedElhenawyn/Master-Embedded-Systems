#include "uart.h"
#define UART0DR *((volatile unsigned int * const)((unsigned int *)0x101f1000)) // (unsigned int *) this casting to tell that this is an address


void uart_send_string(unsigned char * P_tx_string)
{
	while(*P_tx_string != '\0')
	{//loop until end of string
		UART0DR = (unsigned int )( *P_tx_string);//transmit char to the uart
		P_tx_string++;//next char


		

	}
}