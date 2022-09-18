#include "uart.h"
#define UARTDR *(volatile unsigned int * const)((unsigned int *) 0x101f1000)

void Uart_send_string(unsigned char * P_tx_string)
{
	while(* P_tx_string != '\0')
	{
		UARTDR = (unsigned int )(*P_tx_string);
		P_tx_string++;
	}

}