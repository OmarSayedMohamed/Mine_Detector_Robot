/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 12/9/2023
//                              *Component ICU*
/*******************************************************************************/

#ifndef ICU_INTERFACE_H
#define ICU_INTERFACE_H

#define Rising          1
#define Falling         0

void ICU_voidInit(void);

void ICU_voidInterruptEnable(void);

void ICU_voidInterruptDisable(void);

void ICU_SetTriggerEdge(u8 Copy_u8Edge);

u16 Icu_u16GetReading(void);

void ICU_voidSetCallBack(void(*ptrtofunc) (void));











#endif
