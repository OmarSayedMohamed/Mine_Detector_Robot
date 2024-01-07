/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/11/2023
//                              *Component Led*
/*******************************************************************************/

#ifndef Led_H_
#define Led_H_

/*
 * Options
 * 1- PORTA
 * 2- PORTB
 * 3- PORTC
 * 4- PORTD
 */

#define Led_Port      PORTB_REG


/*
 * Options
 * 1- PIN0
 * 2- PIN1
 * 3- PIN2
 * 4- PIN3
 * 5- PIN4
 * 6- PIN5
 * 7- PIN6
 * 8- PIN7
 */

#define Led_Red_Pin       PIN5   // Mine Detect Led
#define Led_Yellow_Pin    PIN6   // Obstacle Detect
#define Led_Green_Pin     PIN7   // All Clear


void Led_voidinit(void);

void Led_voidLedRedEnable(void);
void Led_voidLedGreenEnable(void);
void Led_voidLedYellowEnable(void);

void Led_voidLedRedDisable(void);
void Led_voidLedGreenDisable(void);
void Led_voidLedYellowDisable(void);












#endif
