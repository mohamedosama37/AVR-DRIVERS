#include "STD_TYPES.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#define  NULL  0

static void (*ptr1)(void)= NULL;
static u8  i=0;
static u8  j=1;
static u8  flag=0;
static u16 var;
static u16 var1;
u16 ADC_Result[8];
u16 ADC_MASK[8]=[ADC_PIN0,ADC_PIN1,ADC_PIN2,ADC_PIN3,ADC_PIN4,ADC_PIN5,ADC_PIN6, ADC_PIN7];


void __vector_16 (void)__attribute__((signal));
void __vector_16 (void)
{
	if (i<=6)
	{
	flag=0;	
     ADC_Result[i]= ADCx->ADCH	;
	 ADCx->ADMUX  &=0x3f;
     ADCx->ADMUX  |=ADC_MASK[j];
	 i++;
	 j++;
	 ADCx->ADCSRA  |=0x40;
	 
	}
	else
	{
	  ADC_Result[i]= ADCx->ADCH	;
	  ADCx->ADMUX  &=0x3f;
      ADCx->ADMUX  |=ADC_MASK[0];
	  i=0;
	  j=1;	
	  flag=1;
     ptr1();	  
	}

}

void ADC_initalize ()
{
 switch (REFRENECE_MODE )
  {
    case INTERNAL_REFRENCE:     ADCx->ADMUX  &=0x3f    ;
                                 break;

                            	ADCx->ADMUX  &=ADC_INTERNAL_MODE ;
								break;
	case EXTERNAL_REFRENCE:       ADCx->ADMUX  &=0x3f               ;
                                  ADCx->ADMUX |=ADC_EXTERNAL_MODE   ;
                                break;								  
	case INTERN_EXTERNREF :     ADCx->ADMUX  &=0x3f               ;
	                            ADCx->ADMUX   |=ADC_EXTANDINT_MODE ;
								break;
  }
  switch (SELECTED_PIN )
  {
	 case SELECTED_PINO:    ADCx->ADMUX &= ADC_PINO; break;
							 
	 case SELECTED_PIN1:     ADCx->ADMUX &= 0xe0;
                           	 ADCx->ADMUX |= ADC_PIN1;
							 break;
     case SELECTED_PIN2: ADCx->ADMUX &= 0xe0;
	                     ADCx->ADMUX |= ADC_PIN2;
						 break;
     case SELECTED_PIN3: ADCx->ADMUX &= 0xe0;
	                     ADCx->ADMUX |= ADC_PIN3;
						 break;
     case SELECTED_PIN4: ADCx->ADMUX &= 0xe0;
	                     ADCx->ADMUX |= ADC_PIN4;
						 break;
     case SELECTED_PIN5: ADCx->ADMUX &= 0xe0;
	                     ADCx->ADMUX |= ADC_PIN5;
						  break;
     case SELECTED_PIN6: ADCx->ADMUX &= 0xe0;
	                     ADCx->ADMUX |= ADC_PIN6;
						 break;
     case SELECTED_PIN7: ADCx->ADMUX &= 0xe0;
	                     ADCx->ADMUX |= ADC_PIN7;
						 break;
  }
   switch (ADJUSMENT_SELECT)
   {
	   
	 case LEFT_ADJUSMENT :ADCx->ADMUX |= ADC_LEFTADJ ; break;
     case RIGHT_ADJUSMENT:ADCx->ADMUX &= ADC_RIGHTADJ;	break; 
   }

	   
  switch (PRESCAL_SELECT)
  {
	  case PRESCAL_2  : ADCx->ADCSRA &= 0xf8;
	                    ADCx->ADCSRA |= 0x01;
						break;
						
	  case PRESCAL_4  : ADCx->ADCSRA &= 0xf8;
	                    ADCx->ADCSRA |= 0x02;
						break;
	  case PRESCAL_8  : ADCx->ADCSRA &= 0xf8;
	                    ADCx->ADCSRA |= 0x03;
						break;
	  case PRESCAL_16 :  ADCx->ADCSRA &= 0xf8;
	                     ADCx->ADCSRA |= 0x04;
						 break;
	  case PRESCAL_32 : ADCx->ADCSRA &= 0xf8;
	                    ADCx->ADCSRA |= 0x05;
						break;
	  case PRESCAL_64 : ADCx->ADCSRA &= 0xf8;
	                    ADCx->ADCSRA |= 0x06;
						break;
	  case PRESCAL_128: ADCx->ADCSRA &= 0xf8;
	                    ADCx->ADCSRA |= 0x07;
                        break;	  
  }
  switch (INTERRUPT_MODE)
	   {

         case INTERRUPT_ENABLE : ADCx->ADCSRA |= 0x08;break;
         case INTERRUPT_DISABLE: ADCx->ADCSRA &= 0xf7;break;


	   }	   
 	
	   switch (INITIALMODE)
	   {
		   
		   case  ADC_ENABLE: ADCx->ADCSRA |=0x80; break;
		   case  ADC_DISABE: ADCx->ADCSRA &=0x7f; break;
	   }
  
	
	
}


u16 ADC_BlockReadConversion()
{

	u16 res;
	ADCx->ADCL     = 0;
	ADCx->ADCH     = 0; 
	ADCx->ADCSRA  |=0x40;
	while(! ((ADCx->ADCSRA) & 0x10))
	{
		
    }
	ADCx-> ADCSRA |=0x10;

     var=ADCx->ADCL;
     var1=ADCx->ADCH;
     var1= flag1 <<8;
     res= var|var1;
     res= res>>6;
	
	
}


void ADC_Refresh(void)
{
	ADCx->ADCSRA  |=0x40;
	
}


void setCallBkFn (void (*Copy_CallBkFn)(void) )
{
	ptr1=Copy_CallBkFn;
	
	
}


u16 ADC_ReadConvert(u8 Copy_PinNB, u16* Copy_ptr)
{
	
	u8 Local_Errorstate=0;
	if ( !((Copy_PinNB >=0) && ( Copy_PinNB < 8 )))
	{
		
		Local_Errorstate=1;
		
		
	}else
	{
		* Copy_ptr= ADC_Result[Copy_PinNB];
	}
	
	
	
	
}

u8 ADC_getStatus (void )
{
	return flag;
	
	
	
}