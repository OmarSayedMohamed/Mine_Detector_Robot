/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/10/2023
//                              *Component Ultrasonic Sensor*
/*******************************************************************************/
#ifndef Ultra_CONFIG_H_
#define Ultra_CONFIG_H_


/*Check every 0.5ms       (500us/(256*0.125us)) */
#define CheckingTime 	    16


/*Minimum distance between obstacle in cm*/
#define Min_Distance		30



/*
 * Options
 * 1- PORTA
 * 2- PORTB
 * 3- PORTC
 * 4- PORTD
 */

#define   TRIGGER_PORT  PORTD_REG
#define   ECHO_PORT     PORTD_REG

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

#define   TRIGGER_Pin   PIN5
#define   ECHO_Pin      PIN6











#endif
