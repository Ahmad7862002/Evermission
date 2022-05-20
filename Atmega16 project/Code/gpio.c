 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: GPIO driver for AVR
 *
 *******************************************************************************/

#include "gpio.h"
#include "registers.h"	/* Contains all the registers needed in the gpio driver */
#include "common_macros.h"	/* Contains macros like SET_BIT */

#if INDIVIDUAL_PIN_CONFIG_ENABLED
/*******************************************************************************
• Description
       -Sets the Direction (OUTPUT or INPUT) of a certain pin given the port number
        and pin number. If the port number or the pin number is entered wrongly
        nothing will occur
• Inputs:
		 -a_portNum: Number from 0 -> 3 corresponding to the PORT ID
		 -a_pinNUm: Number from 0 -> 7 corresponding to the PIN ID
		 -a_direction: 0 corresponds to INPUT, any other positive number corresponds
		 	 	 	   to OUPUT
• Return: None
 *******************************************************************************/
void GPIO_setupPinDirection(uint8 a_portNum, uint8 a_pinNum, GPIO_Direction a_direction){
	if((a_pinNum >= NUM_OF_PINS_PER_PORT) || (a_portNum >= NUM_OF_PORTS)){
		/* Do Nothing */
	}
	else{
		/* Setup the pin direction as required */
		if(a_direction){
			SET_BIT(DDRX(a_portNum), a_pinNum);
		}
		else{
			CLEAR_BIT(DDRX(a_portNum), a_pinNum);
		}
	}
}

/*******************************************************************************
• Description
       -Sets the port register (LOGIC_HIGH or LOGIC_LOW) of a certain pin given the port
        number and pin number. If the port number or the pin number is entered wrongly
        nothing will occur. Note that if you want to make the pin output 5v logic high
        you must setup the direction of the pin to be OUTPUT. If the pin was set to
        be INPUT, internal PULL UP feature will work.
• Inputs:
		 -a_portNum: Number from 0 -> 3 corresponding to the PORT ID
		 -a_pinNUm: Number from 0 -> 7 corresponding to the PIN ID
		 -a_value: 0 corresponds to LOGIC_LOW, any other positive number is equivalent
		 	 	 	   to LOGIC_HIGH
• Return: None
 *******************************************************************************/
void GPIO_writePin(uint8 a_portNum, uint8 a_pinNum, GPIO_LogicValue a_value)
{
	if(a_portNum >= NUM_OF_PORTS || a_portNum >= NUM_OF_PINS_PER_PORT){
		/*Do nothing*/
	}
	else{
		if(a_value){
			SET_BIT(PORTX(a_portNum), a_pinNum);
		}
		else{
			CLEAR_BIT(PORTX(a_portNum), a_pinNum);
		}
	}
}

/*******************************************************************************
• Description
       -Reads the pin register (LOGIC_HIGH or LOGIC_LOW) of a certain pin given the port
        number and pin number. If the port number or the pin number is entered wrongly
        nothing will occur.Note
		that the function will return 0 if the port num or the pin number
		is not entered correctly
• Inputs:
		 -a_portNum: Number from 0 -> 3 corresponding to the PORT ID
		 -a_pinNUm: Number from 0 -> 7 corresponding to the PIN ID
• Return:
		 -funcOutput: If pin register contains 1 (LOGIC HIGH) the function returns
		 	 	 	  1, otherwise the function returns 0 in all other cases. Note
		 	 	 	  that the function will return 0 if the port num or the pin number
		 	 	 	  is not entered correctly
 *******************************************************************************/
uint8 GPIO_readPin(uint8 a_portNum, uint8 a_pinNum)
{
	uint8 funcOutput = LOGIC_LOW;
	if(a_portNum >= NUM_OF_PORTS || a_pinNum >= NUM_OF_PINS_PER_PORT){
		/* Do nothing */
	}
	else{
		funcOutput = GET_BIT(PINX(a_portNum), a_pinNum);
	}
	return funcOutput;
}
#endif

#if MULTIPLE_PINS_CONFIG_ENABLED
/*******************************************************************************
• Description
       -Sets the direction  (OUTPUT or INPUT) of a group of pins given the port
        number and pin number. If the port number or the pin number is entered wrongly
        nothing will occur.
• Inputs:
		 -a_portNum: Number from 0 -> 3 corresponding to the PORT ID
		 -a_pins: Hexadecimal number or binary number corresponding to the pins wanted.
		 	 	  For example, if a_pins = 0x0F (or 0b00001111), that means that the
		 	 	  first four pins are the only pins in that port which will be
		 	 	  configured by the function
		 -a_direction: 0 corresponds to INPUT, any other positive number corresponds
		 	 	 	   to OUPUT.
• Return: None

Example:
If
a_portNum = PORTA_ID (0)
a_pins = 0x0F (0b00001111)
a_direction = INPUT
That means that the first 4 pins in PORTA are set to INPUT
 *******************************************************************************/
void GPIO_setupPinsDirection(uint8 a_portNum, uint8 a_pins, GPIO_Direction a_direction){
	if(a_portNum >= NUM_OF_PORTS){
		/* Do Nothing */
	}
	else{
		if(a_direction){
			SET_BITS(DDRX(a_portNum), a_pins);
		}
		else{
			CLEAR_BITS(DDRX(a_portNum), a_pins);
		}
	}
}

/*******************************************************************************
• Description
       -Sets the port register (LOGIC_HIGH or LOGIC_LOW) of given pins given the port
        number and the hexadecimal number or the binary number corresponding to the pins
        wanted to be configured. If the port number or the pin number is entered wrongly
        nothing will occur. Note that if you want to make the pins output 5v logic high
        you must setup the direction of the pins to be OUTPUT. If the pins were set to
        be INPUT, internal PULL UP feature will work.
• Inputs:
		 -a_portNum: Number from 0 -> 3 corresponding to the PORT ID
		 -a_pins: Hexadecimal number or binary number corresponding to the pins wanted.
		 	 	  For example, if a_pins = 0x0F (or 0b00001111), that means that the
		 	 	  first four pins are the only pins in that port which will be
		 	 	  configured by the function
		 -a_value: 0 corresponds to LOGIC_LOW, any other positive number corresponds
		 	 	 	   to LOGIC_HIGH.
• Return: None

Example:
If
a_portNum = PORTA_ID (0)
a_pins = 0x0F (0b00001111)
a_direction = LOGIC_HIGH
That means that the port register in the first 4 pins in PORTA are set to LOGIC_HIGH
 *******************************************************************************/
void GPIO_writePins(uint8 a_portNum, uint8 a_pins, GPIO_LogicValue a_value)
{
	if(a_portNum >= NUM_OF_PORTS){
		/*Do nothing*/
	}
	else{
		if(a_value){
			SET_BITS(PORTX(a_portNum), a_pins);
		}
		else{
			CLEAR_BITS(PORTX(a_portNum), a_pins);
		}
	}
}
#endif

#if PORT_CONFIG_ENABLED
/*******************************************************************************
• Description
       -Sets the direction (OUTPUT or INPUT) of all pins in the port given the
        port number and the direction. If the port number is invalid nothing will occur.
• Inputs:
		 -a_portNum: Number from 0 -> 3 corresponding to the PORT ID
		 -a_direction: 0 corresponds to INPNUT and any other positive number is
		 	 	 	   equivalent to OUTPUT
• Return: None
 *******************************************************************************/
void GPIO_setupPortDirection(uint8 a_portNum, GPIO_Direction a_direction)
{
	if(a_portNum >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		DDRX(a_portNum) = a_direction;
	}
}

/*******************************************************************************
• Description
       -Sets the port register (LOGIC_HIGH or LOGIC_LOW) of all pins in the port
        given the port number and the value. If the port number is invalid nothing will occur.
• Inputs:
		 -a_portNum: Number from 0 -> 3 corresponding to the PORT ID
		 -a_value: 0 corresponds to LOGIC_LOW and any other positive number is
		 	 	 	   equivalent to LOGIC_HIGH
• Return: None
 *******************************************************************************/
void GPIO_writePort(uint8 a_portNum, GPIO_LogicValue a_value)
{
	if(a_portNum >= NUM_OF_PORTS){
		/*Do nothing*/
	}
	else{
		PORTX(a_portNum) = a_value;
	}
}

/*******************************************************************************
• Description
       -Reads the pin register (LOGIC_HIGH or LOGIC_LOW) of all pins in the port
        given the port number and the value. If the port number is invalid nothing will occur.
• Inputs:
		 -a_portNum: Number from 0 -> 3 corresponding to the PORT ID
• Return:
		 -funcOutput: The functions return what is read from the pin register
		 	 	 	  of the given port. If the port number is invalid the
		 	 	 	  functions return 0 (LOGIC_LOW);
 *******************************************************************************/
uint8 GPIO_readPort(uint8 a_portNum)
{
	uint8 funcOutput = LOGIC_LOW;
	if(a_portNum >= NUM_OF_PORTS){
		/* Do nothing */
	}
	else{
		funcOutput = PINX(a_portNum);
	}
	return funcOutput;
}
#endif
