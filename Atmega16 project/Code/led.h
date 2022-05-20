/*
 * led.h
 *
 *  
 *     
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"

#define LED_NUMBER_OF_LEDS	3

#if LED_NUMBER_OF_LEDS >= 1
#define LED0_ID		0
#define LED0_PORT_CONNECTED		PORTC_ID
#define LED0_PIN_CONNECTED		PIN5_ID
#endif
#if LED_NUMBER_OF_LEDS >= 2
#define LED1_ID		1
#define LED1_PORT_CONNECTED		PORTC_ID
#define LED1_PIN_CONNECTED		PIN6_ID
#endif
#if LED_NUMBER_OF_LEDS >= 3
#define LED2_ID		2
#define LED2_PORT_CONNECTED		PORTC_ID
#define LED2_PIN_CONNECTED		PIN7_ID
#endif
#if LED_NUMBER_OF_LEDS >= 4
#define LED3_ID		3
#define LED3_PORT_CONNECTED		PORTC_ID
#define LED3_PIN_CONNECTED		PIN5_ID
#endif
#if LED_NUMBER_OF_LEDS == 5
#define LED4_ID		4
#define LED4_PORT_CONNECTED		PORTC_ID
#define LED4_PIN_CONNECTED		PIN5_ID
#endif

typedef enum{
	LED_OFF, LED_ON
}LED_states;

void LED_init(void);
void LED_sendState(uint8 LED_id, LED_states state);

#endif /* LED_H_ */
