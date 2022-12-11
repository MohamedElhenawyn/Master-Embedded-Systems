#include <stdint.h>
#include <stdio.h>
#include "state.h"
#include "driver.h"
#include "psHandler.h"
#include "AlarmHandler.h"
#include "mA.h"
void setup(){
	psHandler_init();
	ps_handler_state = STATE(ps_reading);
	mA_Handler_state = STATE(pressureHandling);
	AH_state = STATE(idle);
}
int main (){
	//GPIO_INITIALIZATION();
	setup();
	while (1)
	{
		//Implement your Design
		ps_handler_state();
		mA_Handler_state();
		AH_state();
		Delay(5000);
	}
}
