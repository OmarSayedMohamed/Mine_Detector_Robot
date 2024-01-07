/*******************************************************************************/
// Layer : MCAL

// Author : OMAR Sayed 
// Version : 01
// Date : 12/9/2023
//                              *Component ICU*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ICU_interface.h"
#include "ICU_private.h"
#include "ICU_config.h"

static void (*Globalptrtofunc)  (void) = NULL;
void ICU_voidInit(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1); // enable ICU
	SET_BIT(TCCR1B,TCCR1B_ICES1); // rising edge
}

void ICU_voidInterruptEnable(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1); // enable ICU
}

void ICU_voidInterruptDisable(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1); // enable ICU
}

void ICU_SetTriggerEdge(u8 Copy_u8Edge)
{
	if (Copy_u8Edge == Rising)
		SET_BIT(TCCR1B,TCCR1B_ICES1);


	else if (Copy_u8Edge == Falling)
		CLR_BIT(TCCR1B,TCCR1B_ICES1);


}

u16 Icu_u16GetReading(void)
{
	return ICR1A;
}

void ICU_voidSetCallBack(void(*ptrtofunc) (void))
{
	if (ptrtofunc !=NULL)
	{
		Globalptrtofunc=ptrtofunc;
	}
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if (Globalptrtofunc !=NULL)
	{
		Globalptrtofunc ();

	}
}
