/*******************************************************************************/
// Layer : MCAL
// Author : OMAR Sayed 
// Version : 01
// Date : 12/9/2023
//                              *Component ICU*
/*******************************************************************************/

#ifndef ICU_PRIVATE_H
#define ICU_PRIVATE_H

#define TCCR1A       *((volatile u8*)0x4F) // Timer-Counter-Control-Register1

#define TCCR1B       *((volatile u8*)0x4E)  // Timer-Counter-Control-Register2

// Select Pre_Scaler
#define TCCR1B_CS10     0
#define TCCR1B_CS11     1
#define TCCR1B_CS12     2

#define TCCR1B_ICES1    6  //Select Edge


#define TIMSK        *((volatile u8*)0x59)

#define TIMSK_TICIE1    5   // Input Capture Interrupt Enable

#define ICR1A        *((volatile u16*)0x46)


#define TCNT1        *((volatile u16*)0x4C)















#endif
