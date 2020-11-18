#include "STD_TYPES.h"
#include "ICU_interface.h"
#include "DIO_interface.h"

#define  TTCR1A   *((u8 *) 0x4F)
#define  TTCR1B    *((u8 *)0x4E)
#define  TCNT1H    *((u8 *)0x4D)
#define  TCNT1L    *((u16 *)0X4C)
#define  ICR1H     *((u8 *)0X47)
#define  ICR1L     *((u16 *)0x46)
#define  TIMSK     *((u8 *)0X59)

#define  SREG      *((u8 *)0x5f)


   u16  u8Ontime;
   u16 u8Offtime=0;
   u8  u8Flag=0;

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{

  //TCNT1H =0;
     TCNT1L =0;

   if (u8Flag==0)
   {
      u8Ontime=ICR1L;
      TTCR1B|= (1<<6);
      u8Flag=1;

   }else
   {
      u8Offtime= ICR1L;
      TTCR1B &= ~(1<<6);
      u8Flag=0;
   }
    


} 


void ICU_ENABLE ()
{
 
  TTCR1B |= 0x42;

 
  TCNT1H   =0;
  TCNT1L =0;

  ICR1L  =0;
  ICR1H  =0;
  TIMSK |= (1<<5);
  SREG  |= 0x80;

}

void ICU_GetFreqDtime(u16 * Copy_PeriodT , u16 * Copy_u8DutyT)
{
   u16 Local_u16Time =0;
   Local_u16Time= u8Ontime+ u8Offtime;
   * Copy_PeriodT = Local_u16Time;
   * Copy_u8DutyT = (100*u8Ontime)/Local_u16Time ;




}

