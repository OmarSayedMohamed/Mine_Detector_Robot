/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 18/9/2023
//                              *Component Delay*
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


void delay_s (u32 Copy_u32Time)
{
	u32 itertator;
	Copy_u32Time *=100000;
	for ( itertator =0 ; itertator <Copy_u32Time ; itertator ++);
}

void delay_ms (u32 Copy_u32Time)
{
	u32 itertator;
	Copy_u32Time *=100;
	for ( itertator =0 ; itertator <Copy_u32Time ; itertator ++);
}

void delay_us (u32 Copy_u32Time)
{
	u32 itertator;
	for ( itertator =0 ; itertator <Copy_u32Time ; itertator ++);
}
