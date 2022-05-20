/*
 * SW.c
 *
 *  Created on: 28 Dec 2021
 */

#include "SW.h"
#if SW_WITH_EXTERNAL_INTERRUPTS
#include "external_interrupts.h"
#else
#include "gpio.h"
#endif

void SW_init(void){
#if SW_WITH_EXTERNAL_INTERRUPTS
	EXTERNAL_INTERRUPTS_init(SW_INT_PIN_CONNECTED, SW_LOGIC);
#else
	GPIO_setupPinDirection(SW_PORT_CONNECTED, SW_PIN_CONNECTED, INPUT);
#endif
#if SW_ENABLE_PULLUP
	GPIO_writePin(SW_PORT_CONNECTED, SW_PIN_CONNECTED, LOGIC_HIGH);
#endif
}

#if SW_WITH_EXTERNAL_INTERRUPTS
void SW_setCallBack(void (*ptr2Func)(void)){
	EXTERNAL_INTERRUPTS_setCallBack(ptr2Func, SW_INT_PIN_CONNECTED);
}
#endif

#if !SW_WITH_EXTERNAL_INTERRUPTS
uint8 SW_isButtonPressed(void){
#if SW_POSITIVE_LOGIC
	if(GPIO_readPin(SW_PORT_CONNECTED, SW_PIN_CONNECTED)){
		return TRUE;
	}
	else{
		return FALSE;
	}
#else
	if(!GPIO_readPin(SW_PORT_CONNECTED, SW_PIN_CONNECTED)){
		return TRUE;
	}
	else{
		return FALSE;
	}
#endif
}
#endif
