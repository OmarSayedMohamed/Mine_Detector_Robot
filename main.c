/*
 * main.c
 *
 *  Created on: Nov 12, 2023
 *      Author: hp
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "Timer1.h"

#include "CLCD_interface.h"
#include "Ultra_interface.h"
#include "Mine_interface.h"
#include "Motor_interface.h"
#include "Buzzer.h"
#include "Led.h"




u8 Motor_u8Speed = 255; // Motor Speed
void Motion_voidFwd(void); // Motion Forward
void Motion_voidBack(void); // Motion Back
void Motion_voidLeft(void); // Motion Left
void Motion_voidRight(void); // Motion Right
void Motion_voidStop(void); // Stop Motors



int main(void)
{
	/*Initiate LCD*/
	CLCD_voidInit();

	/*Initiate Buzzer*/
	Buzzer_voidinit();

	/*Initiate Led*/
	Led_voidinit();

	/*Initiate Timer1*/
	TIMER1_voidInit();

	/*Initiate UltraSonic*/
	Ultra_voidInit();

	/*Initiate Mine Detector*/
	Mine_voidInit();

	/*EXT2 On Change for Metal Detector*/

	EXTI_voidEnableInterrupt(int2);
	GIE_voidEnable();

	/*Initiate Motor*/
	Motor_voidinit();

	// Checking all is Clear
	CLCD_voidSendCommand(Clear);
	CLCD_voidSendString(" Checking ...");
	delay_s(3);
	CLCD_voidSendCommand(Clear);
	CLCD_voidSendString(" All Clear");
	CLCD_voidSetPosition(1,1);
	CLCD_voidSendString("Enjoy ^-^");
	delay_s(3);

	while(1)
	{
		u8 Local_u8Obstacle = Ultra_u8GetReading(); // Variable to receive UltraSonic Reading
		u8 Local_u8Mines = Mine_u8GetReading(); // Variable to receive Mine Detector Reading

		/*
		 * Check if there is No Obstacles
		 * if there is Mine Motor Stop, Buzzer Turn On and Red Led will be active
		 * If there is no mine Motor Move Forward Buzzer Turn Off and Green Led will be active
		 */

		if (Local_u8Obstacle == NO_OBSTACLE)
		{
			if (Local_u8Mines == MINE)
			{
				Motion_voidStop();

				Buzzer_voidEnable();
				Led_voidLedGreenDisable();
				Led_voidLedYellowDisable();
				Led_voidLedRedEnable();

				CLCD_voidSendCommand(Clear);
				CLCD_voidSendString(" Mine Detect"); // To receive Message on LCD there is mine
				CLCD_voidSetPosition(1,1);
				CLCD_voidSendString(" Car Stop");
				delay_s(2);
			}
			else if (Local_u8Mines == NO_MINE)
			{
				Motion_voidBack();

				Buzzer_voidDisable();
				Led_voidLedGreenEnable();
				Led_voidLedYellowDisable();
				Led_voidLedRedDisable();

				CLCD_voidSendCommand(Clear);
				CLCD_voidSendString(" No Obstacle"); // To receive Message on LCD there is No mine
				CLCD_voidSetPosition(1,1);
				CLCD_voidSendString(" Car Move");
				delay_s(2);

			}

		}

		/*
		 * Check if there is Obstacles
		 * if there is Mine Motor Stop, Buzzer Turn On and Red Led will be active
		 * If there is no mine Motor Move Left,  Buzzer Turn Off and Yellow Led will be active
		 */
		else if (Local_u8Obstacle == OBSTACLE)
		{
			if (Local_u8Mines == MINE)
			{
				Motion_voidStop();

				Buzzer_voidEnable();
				Led_voidLedGreenDisable();
				Led_voidLedYellowDisable();
				Led_voidLedRedEnable();

				CLCD_voidSendCommand(Clear);
				CLCD_voidSendString(" Mine Detect"); // To receive Message on LCD there is mine
				CLCD_voidSetPosition(1,1);
				CLCD_voidSendString(" Car Stop");
				delay_s(2);

			}
			else if (Local_u8Mines == NO_MINE)
			{
				Motion_voidLeft();

				Buzzer_voidDisable();
				Led_voidLedGreenDisable();
				Led_voidLedYellowEnable();
				Led_voidLedRedDisable();

				CLCD_voidSendCommand(Clear);
				CLCD_voidSendString(" Obstacle Detect"); // To receive Message on LCD there is No mine
				CLCD_voidSetPosition(1,1);
				CLCD_voidSendString(" Move Left");
				delay_s(2);
			}
		}

		else
		{
			// Do Nothing
		}
	}
	return 0;
}

void Motion_voidFwd(void)
{
	MOTOR_u8DCRotate(MOTOR_Fwd,Motor_u8Speed);
}
void Motion_voidBack(void)
{
	MOTOR_u8DCRotate(MOTOR_Back,Motor_u8Speed);
}
void Motion_voidLeft(void)
{
	MOTOR_u8DCRotate(MOTOR_Left,Motor_u8Speed);
}
void Motion_voidRight(void)
{
	MOTOR_u8DCRotate(MOTOR_Right,Motor_u8Speed);
}
void Motion_voidStop(void)
{
	MOTOR_u8DCRotate(MOTOR_Stop,Motor_u8Speed);
}


