/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/11/2023
//                              *Component Buzzer*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "Buzzer.h"



void Buzzer_voidinit(void)
{
	// Make PortA Pin0 Output
	DIO_voidSetPinDir(Buzzer_Port,Buzzer_Pin,PORT_DIR_OUT);
}

void Buzzer_voidEnable(void)
{
	// Enable Buzzer
	DIO_voidSetPinVal(Buzzer_Port,Buzzer_Pin,PIN_VAL_HIGH);
}

void Buzzer_voidDisable(void)
{
	// Disable Buzzer
	DIO_voidSetPinVal(Buzzer_Port,Buzzer_Pin,PIN_VAL_LOW);
}



