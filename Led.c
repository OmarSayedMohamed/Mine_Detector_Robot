/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/11/2023
//                              *Component Led*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "Led.h"


void Led_voidinit(void)
{
	// Make PortB Pins 5,6,7 Output
	DIO_voidSetPinDir(Led_Port,Led_Red_Pin,PIN_DIR_OUT);
	DIO_voidSetPinDir(Led_Port,Led_Green_Pin,PIN_DIR_OUT);
	DIO_voidSetPinDir(Led_Port,Led_Yellow_Pin,PIN_DIR_OUT);
}

void Led_voidLedGreenEnable(void)
{
	// Enable Green Led
	DIO_voidSetPinVal(Led_Port,Led_Green_Pin,PIN_VAL_HIGH);
}

void Led_voidLedRedEnable(void)
{
	// Enable Red Led
	DIO_voidSetPinVal(Led_Port,Led_Red_Pin,PIN_VAL_HIGH);
}

void Led_voidLedYellowEnable(void)
{
	// Enable Yellow Led
	DIO_voidSetPinVal(Led_Port,Led_Yellow_Pin,PIN_VAL_HIGH);
}

void Led_voidLedRedDisable(void)
{
	// Disable Red Led
	DIO_voidSetPinVal(Led_Port,Led_Red_Pin,PIN_VAL_LOW);
}

void Led_voidLedGreenDisable(void)
{
	// Disable Green Led
	DIO_voidSetPinVal(Led_Port,Led_Green_Pin,PIN_VAL_LOW);
}

void Led_voidLedYellowDisable(void)
{
	// Disable Yellow Led
	DIO_voidSetPinVal(Led_Port,Led_Yellow_Pin,PIN_VAL_LOW);
}



