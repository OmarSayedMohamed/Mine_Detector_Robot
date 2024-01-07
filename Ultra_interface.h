/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/10/2023
//                              *Component Ultrasonic Sensor*
/*******************************************************************************/
#ifndef Ultra_INTERFACE_H_
#define Ultra_INTERFACE_H_

#define OBSTACLE		1
#define NO_OBSTACLE		2



void Ultra_voidInit(void);

void Ultra_voidTriggerReading(void);

void Ultra_voidEchoReading(void);

u8 Ultra_u8GetReading(void);












#endif
