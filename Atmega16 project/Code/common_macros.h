 /******************************************************************************
 *
 * Module: Common - Macros
 *
 * File Name: common_macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef COMMON_MACROS
#define COMMON_MACROS

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define FIRST_TWO_BITS 				0x03
#define FIRST_THREE_BITS			0x07
#define FIRST_FOUR_BITS 			0x0F
#define FIRST_FIVE_BITS 			0x1F
#define FIRST_SIX_BITS 				0x3F
#define FIRST_SEVEN_BITS 			0x7F
#define LAST_TWO_BITS 				0xC0
#define LAST_THREE_BITS				0xE0
#define LAST_FOUR_BITS 				0xF0
#define LAST_FIVE_BITS				0xF8
#define LAST_SIX_BITS 				0xFC
#define LAST_SEVEN_BITS 			0xFE
#define ALL_EIGHT_BITS 				0xFF


/*******************************************************************************
 *                                 MACROS	                                   *
 *******************************************************************************/

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Set multiple bits in any register */
#define SET_BITS(REG,BITS) (REG|=BITS)

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Clear multiple bits in any register */
#define CLEAR_BITS(REG,BITS) (REG&=~BITS)

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Toggle multiple bits in any register */
#define TOGGLE_BITS(REG,BITS) (REG^=BITS)

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<((sizeof(REG) * 8)-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>((sizeof(REG) * 8)-num)) )

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/* Gets a certain bit whether 0 or 1 */
#define GET_BIT(REG, BIT) ((REG & (1 << BIT)) >> BIT)

#endif
