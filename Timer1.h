/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 11/9/2023
//                              *Component Timer1*
/*******************************************************************************/

#ifndef TIMER1_H_
#define TIMER1_H_

#define TCCR1A       *((volatile u8*)0x4F) // Timer-Counter-Control-Register1

#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1

#define TCCR1A_FOC1B    2
#define TCCR1A_FOC1A    3

#define TCCR1A_COM1B0   4
#define TCCR1A_COM1B1   5

#define TCCR1A_COM1A0   6
#define TCCR1A_COM1A1   7


#define TCCR1B       *((volatile u8*)0x4E)  // Timer-Counter-Control-Register2

#define TCCR1B_CS10     0
#define TCCR1B_CS11     1
#define TCCR1B_CS12     2

#define TCCR1B_WGM12    3
#define TCCR1B_WGM13    4

#define TIMSK       *((volatile u8*)0x59)  // Interrupt Enable
#define TIMSK_TOIE1    2

#define OCR1A        *((volatile u16*)0x4A)
#define ICR1A        *((volatile u16*)0x46)

#define OCR1B        *((volatile u16*)0x48)

#define TCNT1        *((volatile u16*)0x4C)

void TIMER1_voidInit(void);
void TIMER1_voidWriteValue(u16 Copy_u16Value);
u16 TIMER1_u16ReadValue(void);
void TIMER1_voidSetOCRValue(u16 Copy_u16Value);
void TIMER1_voidSetICCRValue(u16 Copy_u16Value);
u8 TIMER1_u8SetCallBack(void (*Copy_ptrtofunc) (void));

#endif
