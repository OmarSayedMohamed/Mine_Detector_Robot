/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/11/2023
//                              *Component Buzzer*
/*******************************************************************************/

#ifndef Buzzer_H_
#define Buzzer_H_

/*
 * Options
 * 1- PORTA
 * 2- PORTB
 * 3- PORTC
 * 4- PORTD
 */

#define Buzzer_Port      PORTA_REG


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

#define Buzzer_Pin       PIN0



void Buzzer_voidinit(void);
void Buzzer_voidEnable(void);
void Buzzer_voidDisable(void);








#endif
