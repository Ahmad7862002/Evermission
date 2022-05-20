 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: Header file for GPIO driver for AVR
 *
 *******************************************************************************/

#ifndef GPIO_H_
#define GPIO_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define INDIVIDUAL_PIN_CONFIG_ENABLED TRUE
#define MULTIPLE_PINS_CONFIG_ENABLED  FALSE /* In this project, configuring multiple pins at the same time feature was not used */
#define PORT_CONFIG_ENABLED			  TRUE

#define NUM_OF_PORTS			4
#define NUM_OF_PINS_PER_PORT	8

#define PORTA_ID	0
#define PORTB_ID	1
#define PORTC_ID	2
#define PORTD_ID	3

#define PIN0_ID		0
#define PIN1_ID		1
#define PIN2_ID		2
#define PIN3_ID		3
#define PIN4_ID		4
#define PIN5_ID		5
#define PIN6_ID		6
#define PIN7_ID		7

/*******************************************************************************
 *                         User Defined Data Types                             *
 *******************************************************************************/

typedef enum{
	INPUT, OUTPUT = 0xFF
}GPIO_Direction;

typedef enum{
	LOGIC_LOW, LOGIC_HIGH = 0xFF
}GPIO_LogicValue;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

#if INDIVIDUAL_PIN_CONFIG_ENABLED
void GPIO_setupPinDirection(uint8 a_portNum, uint8 a_pinNum, GPIO_Direction a_direction);
void GPIO_writePin(uint8 a_portNum, uint8 a_pinNum, GPIO_LogicValue a_value);
uint8 GPIO_readPin(uint8 a_portNum, uint8 a_pinNum);
#endif

#if MULTIPLE_PINS_CONFIG_ENABLED
void GPIO_setupPinsDirection(uint8 a_portNum, uint8 a_pins, GPIO_Direction a_direction);
void GPIO_writePins(uint8 a_portNum, uint8 a_pins, GPIO_LogicValue a_value);
#endif

#if PORT_CONFIG_ENABLED
void GPIO_setupPortDirection(uint8 a_portNum, GPIO_Direction a_direction);
void GPIO_writePort(uint8 a_portNum, GPIO_LogicValue a_value);
uint8 GPIO_readPort(uint8 a_portNum);
#endif

#endif /* GPIO_H_ */
