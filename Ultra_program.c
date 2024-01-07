/*******************************************************************************/
// Layer : HAL 
// Author : OMAR Sayed 
// Version : 01
// Date : 13/10/2023
//                              *Component Ultrasonic Sensor*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"
#include "DIO_interface.h"

#include "Timer1.h"
#include "EXTI_interface.h"
#include "ICU_interface.h"

#include "Ultra_interface.h"
#include "Ultra_private.h"
#include "Ultra_config.h"


static u16 Ultra_u16Distance = 0; // Variable to Read the distance
static u8  Ultra_u8Flag = NO_OBSTACLE; // Variable to Read the Flag of the Mine Detector

void Ultra_voidInit(void)
{
	// Set Trigger Pin Output
	DIO_voidSetPinDir(TRIGGER_PORT,TRIGGER_Pin,PIN_DIR_OUT);
	/* Set Echo Pin Input
	 * Input Pull Up
	 */
	DIO_voidSetPinDir(ECHO_PORT,ECHO_Pin,PIN_DIR_IN);
	DIO_voidSetPinVal(ECHO_PORT,ECHO_Pin,PIN_VAL_HIGH);

	// Run Function Trigger to run in the ISR of Timer1
	TIMER1_u8SetCallBack(&Ultra_voidTriggerReading);

	// Run Function Echo to run in the ISR of ICU
	ICU_voidSetCallBack(&Ultra_voidEchoReading);

}


void Ultra_voidTriggerReading(void)
{
	static u8 Local_u8Counter = 0;
	Local_u8Counter++;

	/*generate trigger pulse*/
	if(Local_u8Counter == CheckingTime)
	{
		DIO_voidSetPinVal(TRIGGER_PORT,TRIGGER_Pin,PIN_VAL_HIGH);
		delay_us(15);
		DIO_voidSetPinVal(TRIGGER_PORT,TRIGGER_Pin,PIN_VAL_LOW);
		ICU_voidInit();
	}

}

void Ultra_voidEchoReading(void)
{
	static u8 Local_u8Counter = 0;
	static u16 Local_u16PulseStart , Local_u16PulseEnd;
	Local_u8Counter++;

	/*Pulse is started*/
	if(Local_u8Counter % 2 == 1)
	{
		Local_u16PulseStart = Icu_u16GetReading();

		ICU_SetTriggerEdge(Falling);

	}
	/*Pulse is ended*/


	else
	{
		Local_u16PulseEnd = Icu_u16GetReading();

		// Calculate the Distance
		Ultra_u16Distance = (Local_u16PulseEnd - Local_u16PulseStart)/466;

		if(Ultra_u16Distance <= Min_Distance)
		{
			Ultra_u8Flag = OBSTACLE;
		}
		else
		{
			Ultra_u8Flag = NO_OBSTACLE;

		}
		ICU_voidInterruptDisable();


	}
}

// Function to return the obstacle flag
u8 Ultra_u8GetReading(void)
{
	return Ultra_u8Flag;
}
