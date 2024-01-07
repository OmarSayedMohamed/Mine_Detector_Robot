/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/10/2023
//                              *Component Motor*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "Motor_interface.h"
#include "Motor_private.h"
#include "Motor_config.h"

void Motor_voidinit(void)
{
	// Make PortA Output
	DIO_voidSetPortDir(Motor_Port,PORT_DIR_OUT);
}

// Function to Control the Direction of the Motor

u8 MOTOR_u8DCRotate(u8 Copy_u8Direction,u8 Copy_u8Speed)
{
	u8 Local_u8ErrorState = OK;

	// Move Forward
	if (Copy_u8Direction == MOTOR_Fwd)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_HIGH);
	}

	// Move Back
	else if(Copy_u8Direction == MOTOR_Back)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_LOW);
	}

// Move Right
	else if(Copy_u8Direction == MOTOR_Right)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_LOW);
	}

	// Move Left
	else if(Copy_u8Direction == MOTOR_Left)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_HIGH);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_LOW);
	}

	// Stop
	else if(Copy_u8Direction == MOTOR_Stop)
	{
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor1_Pin2,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin1,PIN_VAL_LOW);
		DIO_voidSetPinVal(Motor_Port,Motor2_Pin2,PIN_VAL_LOW);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}


	return Local_u8ErrorState;
}

