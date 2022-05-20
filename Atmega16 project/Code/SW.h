/*
 * SW.h
 *
 *  Created on: 28 Dec 2021
 */

#ifndef SW_H_
#define SW_H_

#include "std_types.h"

#define SW_WITH_EXTERNAL_INTERRUPTS	FALSE
#define SW_ENABLE_PULLUP			FALSE

#if SW_WITH_EXTERNAL_INTERRUPTS
#define SW_INT_PIN_CONNECTED		INT0_ID
#define SW_LOGIC					RISING_EDGE
#else
#define SW_PORT_CONNECTED			PORTA_ID
#define SW_PIN_CONNECTED			PIN3_ID
#define SW_POSITIVE_LOGIC			TRUE
#endif

void SW_init(void);
#if SW_WITH_EXTERNAL_INTERRUPTS
void SW_setCallBack(void (*ptr2Func)(void));
#else
uint8 SW_isButtonPressed(void);
#endif

#endif /* SW_H_ */
