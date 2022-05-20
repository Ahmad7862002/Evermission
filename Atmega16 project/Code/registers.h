 /******************************************************************************
 *
 * Module: REGISTERS
 *
 * File Name: registers.h
 *
 * Description: Header file for most used registers in Atemga16
 *
 *******************************************************************************/

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_types.h"

/*******************************************************************************
 *                         User Defined Data Types                             *
 *******************************************************************************/

/* The below user defined data type can access a certain bit in an 8 bit variable
 * and can access a the whole variable at the same time
 */
typedef union{
	uint8 accessBits;
	struct{
		uint8 bit0: 1;
		uint8 bit1: 1;
		uint8 bit2: 1;
		uint8 bit3: 1;
		uint8 bit4: 1;
		uint8 bit5: 1;
		uint8 bit6: 1;
		uint8 bit7: 1;
	}Bits;
}Reg8Bits;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define DATA_DIRECTION_A 			(*((volatile Reg8Bits* const)(0x3A)))
#define OUTPUT_REG_A 				(*((volatile Reg8Bits* const)(0x3B)))
#define INPUT_REG_A 				(*((volatile const Reg8Bits* const)(0x39)))

#define DATA_DIRECTION_B 			(*((volatile Reg8Bits* const)(0x37)))
#define OUTPUT_REG_B 				(*((volatile Reg8Bits* const)(0x38)))
#define INPUT_REG_B 				(*((volatile const Reg8Bits* const)(0x36)))

#define DATA_DIRECTION_C 			(*((volatile Reg8Bits* const)(0x34)))
#define OUTPUT_REG_C 				(*((volatile Reg8Bits* const)(0x35)))
#define INPUT_REG_C 				(*((volatile const Reg8Bits* const)(0x33)))

#define DATA_DIRECTION_D 			(*((volatile Reg8Bits* const)(0x31)))
#define OUTPUT_REG_D 				(*((volatile Reg8Bits* const)(0x32)))
#define INPUT_REG_D 				(*((volatile const Reg8Bits* const)(0x30)))

#define DDRA_REG					(*((volatile Reg8Bits* const)(0x3A)))
#define PORTA_REG					(*((volatile Reg8Bits* const)(0x3B)))
#define PINA_REG	 				(*((volatile const Reg8Bits* const)(0x39)))
#define DDRB_REG		 			(*((volatile Reg8Bits* const)(0x37)))
#define PORTB_REG	 				(*((volatile Reg8Bits* const)(0x38)))
#define PINB_REG	 				(*((volatile const Reg8Bits* const)(0x36)))
#define DDRC_REG		 			(*((volatile Reg8Bits* const)(0x34)))
#define PORTC_REG	 				(*((volatile Reg8Bits* const)(0x35)))
#define PINC_REG	 				(*((volatile const Reg8Bits* const)(0x33)))
#define DDRD_REG		 			(*((volatile Reg8Bits* const)(0x31)))
#define PORTD_REG	 				(*((volatile Reg8Bits* const)(0x32)))
#define PIND_REG	 				(*((volatile const Reg8Bits* const)(0x30)))

#define DDRA 						(*((volatile uint8* const)(0x3A)))
#define PORTA 						(*((volatile uint8* const)(0x3B)))
#define PINA		 				(*((volatile const uint8* const)(0x39)))

#define DDRB			 			(*((volatile uint8* const)(0x37)))
#define PORTB		 				(*((volatile uint8* const)(0x38)))
#define PINB		 				(*((volatile const uint8* const)(0x36)))

#define DDRC			 			(*((volatile uint8* const)(0x34)))
#define PORTC		 				(*((volatile uint8* const)(0x35)))
#define PINC		 				(*((volatile const uint8* const)(0x33)))

#define DDRD			 			(*((volatile uint8* const)(0x31)))
#define PORTD		 				(*((volatile uint8* const)(0x32)))
#define PIND		 				(*((volatile const uint8* const)(0x30)))

#define OCR0						(*((volatile uint8* const)(0x5C)))

#define GICR						(*((volatile uint8* const)(0x5B)))
#define IVCE   	0
#define IVSEL   1
#define INT2    5
#define INT0    6
#define INT1    7

#define GIFR						(*((volatile uint8* const)(0x5A)))
#define INTF2   5
#define INTF0   6
#define INTF1   7

#define TIMSK						(*((volatile uint8* const)(0x59)))
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

#define TIFR						(*((volatile uint8* const)(0x58)))
#define TOV0    0
#define OCF0    1
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5
#define TOV2    6
#define OCF2    7

#define MCUCR						(*((volatile uint8* const)(0x55)))
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define SM0     4
#define SM1     5
#define SE      6
#define SM2     7

#define MCUCSR						(*((volatile uint8* const)(0x54)))
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3
#define JTRF    4
#define ISC2    6
#define JTD     7

#define TCCR0						(*((volatile uint8* const)(0x53)))
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

#define TCNT0						(*((volatile uint8* const)(0x52)))

#define TCCR1A						(*((volatile uint8* const)(0x4F)))
#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR1B						(*((volatile uint8* const)(0x4E)))
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCNT1						(*((volatile uint16* const)(0x4C)))

#define OCR1A						(*((volatile uint16* const)(0x4A)))

#define OCR1B						(*((volatile uint16* const)(0x48)))

#define ICR1						(*((volatile uint16* const)(0x46)))

#define TCCR2						(*((volatile uint8* const)(0x45)))
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7

#define TCNT2						(*((volatile uint8* const)(0x44)))

#define OCR2						(*((volatile uint8* const)(0x43)))

#define WDTCR						(*((volatile uint8* const)(0x41)))
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDE     3
#define WDTOE   4

#define SFIOR						(*((volatile uint8* const)(0x50)))

#define EEARH						(*((volatile uint8* const)(0x3F)))
#define EEARL						(*((volatile uint8* const)(0x3E)))
#define EEAR						(*((volatile uint16* const)(0x3E)))

#define EEDR						(*((volatile uint8* const)(0x3D)))

#define EECR						(*((volatile uint8* const)(0x3C)))
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3

#define SPDR						(*((volatile uint8* const)(0x2F)))

#define SPSR						(*((volatile uint8* const)(0x2E)))
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPCR						(*((volatile uint8* const)(0x2D)))
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define UDR							(*((volatile uint8* const)(0x2C)))

#define UCSRA						(*((volatile uint8* const)(0x2B)))
#define MPCM    0
#define U2X     1
#define PE      2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UCSRB						(*((volatile uint8* const)(0x2A)))
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UBRRL						(*((volatile uint8* const)(0x29)))

#define ACSR						(*((volatile uint8* const)(0x28)))
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7

#define ADMUX						(*((volatile uint8* const)(0x27)))
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

#define ADCSRA						(*((volatile uint8* const)(0x26)))
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADC							(*((volatile uint16* const)(0x24)))

#define UBRRH						(*((volatile uint8* const)(0x40)))

#define UCSRC						(*((volatile uint8* const)(0x40)))
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL   6
#define URSEL   7

#define TWDR						(*((volatile uint8* const)(0x23)))

#define TWAR						(*((volatile uint8* const)(0x22)))
#define TWGCE   0
#define TWA0    1
#define TWA1    2
#define TWA2    3
#define TWA3    4
#define TWA4    5
#define TWA5    6
#define TWA6    7

#define TWSR						(*((volatile uint8* const)(0x21)))
#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#define TWBR						(*((volatile uint8* const)(0x20)))

#define TWCR						(*((volatile uint8* const)(0x56)))
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

#define	DIFF_BET_GPIO_REG	-3

/*******************************************************************************
 *                                  MACROS                                     *
 *******************************************************************************/

/* The following 3 macros expect the port number (port id) (from 0 to 3) and
 * sets the value of the called register depending on the fact that the ATmega16
 * GPIO registers of each port have equal address difference in RAM
 */
#define DDRX(X) 		(*((volatile uint8* const)(0x3A + (DIFF_BET_GPIO_REG * (X)))))
#define PORTX(X) 		(*((volatile uint8* const)(0x3B + (DIFF_BET_GPIO_REG * (X)))))
#define PINX(X) 		(*((volatile uint8* const)(0x39 + (DIFF_BET_GPIO_REG * (X)))))


#endif /* REGISTERS_H_ */
