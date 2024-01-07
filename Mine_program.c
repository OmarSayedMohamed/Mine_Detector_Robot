/*******************************************************************************/
// Layer : HAL 

// Author : OMAR Sayed 
// Version : 01
// Date : 13/10/2023
//                              *Component Mine Sensor*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "Mine_config.h"
#include "Mine_interface.h"
#include "Mine_private.h"

static u8 MineFlag = NO_MINE;
void Mine_Detection(void);

void Mine_voidInit(void)
{
	// External INT2 Enable for rising edge
	EXTI_voidSetSenseCtrl(rising_edge,int2);
	// Call Function Mine Detection for to run in the ISR
	EXTI_voidSetCallBack(int2,&Mine_Detection);
}

u8 Mine_u8GetReading(void)
{
	return MineFlag;
}

void Mine_Detection(void)
{
	static u8 Local_u8Counter = 0;

	TOG_BIT(Local_u8Counter,0);

	if(Local_u8Counter == 1)
	{
		MineFlag = MINE;
	}
	else
	{
		MineFlag = NO_MINE;
	}
}
