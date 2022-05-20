/*
 * main.c
 *
 *  
 */

#include "led.h"
#include "SW.h"

int main(void){
	LED_init();
	SW_init();
	while(1){
		if(SW_isButtonPressed()){
			LED_sendState(LED0_ID, LED_ON);
			LED_sendState(LED1_ID, LED_ON);
			LED_sendState(LED2_ID, LED_ON);
		}
		else{
			LED_sendState(LED0_ID, LED_OFF);
			LED_sendState(LED1_ID, LED_OFF);
			LED_sendState(LED2_ID, LED_OFF);
		}
	}
}
