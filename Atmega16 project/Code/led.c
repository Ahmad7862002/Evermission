/*
 * led.c
 *
 *  
 *      
 */

#include "led.h"
#include "gpio.h"

void LED_init(void){
#if LED_NUMBER_OF_LEDS >= 1
	GPIO_setupPinDirection(LED0_PORT_CONNECTED, LED0_PIN_CONNECTED, OUTPUT);
#endif
#if LED_NUMBER_OF_LEDS >= 2
	GPIO_setupPinDirection(LED1_PORT_CONNECTED, LED1_PIN_CONNECTED, OUTPUT);
#endif
#if LED_NUMBER_OF_LEDS >= 3
	GPIO_setupPinDirection(LED2_PORT_CONNECTED, LED2_PIN_CONNECTED, OUTPUT);
#endif
#if LED_NUMBER_OF_LEDS >= 4
	GPIO_setupPinDirection(LED3_PORT_CONNECTED, LED3_PIN_CONNECTED, OUTPUT);
#endif
#if LED_NUMBER_OF_LEDS == 5
	GPIO_setupPinDirection(LED4_PORT_CONNECTED, LED4_PIN_CONNECTED, OUTPUT);
#endif
}

void LED_sendState(uint8 LED_id, LED_states state){
	switch(LED_id){
#if LED_NUMBER_OF_LEDS >= 1
	case LED0_ID:
		GPIO_writePin(LED0_PORT_CONNECTED, LED0_PIN_CONNECTED, state);
		break;
#endif
#if LED_NUMBER_OF_LEDS >= 2
	case LED1_ID:
		GPIO_writePin(LED1_PORT_CONNECTED, LED1_PIN_CONNECTED, state);
		break;
#endif
#if LED_NUMBER_OF_LEDS >= 3
	case LED2_ID:
		GPIO_writePin(LED2_PORT_CONNECTED, LED2_PIN_CONNECTED, state);
		break;
#endif
#if LED_NUMBER_OF_LEDS >= 4
	case LED3_ID:
		GPIO_writePin(LED3_PORT_CONNECTED, LED3_PIN_CONNECTED, state);
		break;
#endif
#if LED_NUMBER_OF_LEDS == 5
	case LED4_ID:
		GPIO_writePin(LED4_PORT_CONNECTED, LED4_PIN_CONNECTED, state);
		break;
#endif
	}
}
