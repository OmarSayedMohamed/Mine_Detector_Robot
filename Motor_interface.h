/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/10/2023
//                              *Component Motor*
/*******************************************************************************/
#ifndef Motor_INTERFACE_H_
#define Motor_INTERFACE_H_

#define MOTOR_Fwd    	1
#define MOTOR_Back  	2
#define MOTOR_Right   	3
#define MOTOR_Left  	4
#define MOTOR_Stop  	5

void Motor_voidinit(void);
u8 MOTOR_u8DCRotate(u8 Copy_u8Direction,u8 Copy_u8Speed);







#endif
