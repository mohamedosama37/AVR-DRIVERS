#include "Interrupt_interface.h"
#include "Interrupt_private.h"
#include "Interrupt_config.h"

static void (*ptr0CallBack)(void)=NULL;
static void (*ptr1CallBack)(void)=NULL;
static void (*ptr2CallBack)(void)=NULL;

void Initalize (void)

{
	
	GIFR &= 0x1f;
	
	if ( Init[0].Mode == ENABLE)
	{
		   if (Init[0].Event== RISING)
		   {
			  MCUCR|= 0x03;
			  GICR |= 0x40;
			   
		   } else if (Init[0].Event==FALLING)
		   {
			   MCUCR |= 0x02;
			   GICR  |=0x40;
		   }  else
		   {
              MCUCR  |=0x01;
			  GICR  |=0x40;
		   }
	}else
	{
		GICR &= 0xCf;
		
	}
	
	
	
	if (Init[1].Mode == ENABLE)
	{
		
		if (Init[1].Event== RISING)
		   {
			  MCUCR|= 0x0C;
			  GICR |= 0x80;
			   
		   } else if (Init[1].Event==FALLING)
		   {
			   MCUCR |= 0x08;
			   GICR  |=0x80;
		   }  else
		   {
              MCUCR  |=0x04;
			  GICR  |=0x80;
		   }	
	}else
	{
		
		GICR &= 0x7f;
	}
	
	if (Init[2].Mode == ENABLE)
	{
		
		if (Init[1].Event== RISING)
		   {
			  MCUCSR|= 0x40
			  GICR |= 0x20;
			   
		   } else 
		   {
			   MCUCSR &=0xBF;
			   GICR  |=0x20;
		   } 
		
	}else
	{
		GICR &= 0xDf;
	}
	
}



u8 Enable_Interrupt (u8 Copy_u8Interrupt)
{
	u8 Local_ErrorState=0;
	if ((Copy_u8Interrupt != INTO) && (Copy_u8Interrupt != INT1) && (Copy_u8Interrupt != INT2)
	{
		Local_ErrorState=1;
	}else
	{
		GIFR &= 0x1f;
		switch (Copy_u8Interrupt)
		{
			
		
        case INTO: MCUCR|= 0x03;
                   GICR |= 0x40;
		break;
		
		case INT1: MCUCR|= 0x0C;
	              GICR |= 0x80;
		break;
		
		
       	case INT2: MCUCSR|= 0x40
			       GICR |= 0x20;
		break;

		
		}
		
		
		
	return  Local_ErrorState;
		
	}
	
u8 DisEnable_Interrupt (u8 Copy_u8Interrupt)
{
	u8 Local_ErrorState=0;
	
	if ((Copy_u8Interrupt != INTO) && (Copy_u8Interrupt != INT1) && (Copy_u8Interrupt != INT2)
	{
		Local_ErrorState=1;
	}else
	{
		switch (Copy_u8Interrupt)
		{
		case INTO: GICR &= 0xCf;break;
		case INT1: GICR &= 0x7f;break;
		case INT2: GICR &= 0xDf;break;
	
	
	
	
	
	
}
	return Local_ErrorState;
	
}



u8 setInterruptLevel (u8 Copy_u8Interrupt , u8 Copy_u8Event)



{
	
	
	
	
	
	
	
	
	
	
	
	
}



u8 SetCallBackFn ( u8 Copy_u8Interrupt, void  (*Copy_pvidCallBack)(void))
{
	
	u8 LocalErrorState=0;
	if ( (Copy_u8Interrupt != INTO )&& ( Copy_u8Interrupt != INT1) && ( Copy_u8Interrupt != INT2))
	{
		
		LocalErrorState=1;
	}else
    {
        switch ( Copy_u8Interrupt)
		{
		   case INTO: ptr0CallBack=	Copy_pvidCallBack; break;
		   case INT1: ptr1CallBack=	Copy_pvidCallBack; break;
		   case INT2: ptr2CallBack=	Copy_pvidCallBack; break;
			
			
		}

    }
	
	return LocalErrorState;
	
}	


void __vector_3 (void)
{
	
	
	
	* ptr2CallBack();
	
	
}	


void __vector_2 (void)
{
	
	
	
	* ptr1CallBack();
	
	
}	



void __vector_1 (void)
{
	
	
	
	* ptr0CallBack();
	
	
}	