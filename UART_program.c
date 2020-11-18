#include "STD_TYPES.h"
#include "UART_private.h"
#include "UART_interface.h"
#define NULL 0

static int Busy_flag=0;
static int Busy_flag2=0;

static int count=0;
static int rx_count=0;

static void (*ptr_rx)(void)=NULL;
static void (*ptr_tx)(void)=NULL;

struct t
{
	
	u8* Buffer;
	u8 size ;
	
	
	
}tx_buffer;

struct r
{
	
	u8* Buffer;
	u8 size ;
	
	
}rx_buffer;


void UART_init( initail * uartx)
{
	switch ( uartx ->SPEED_MODE)
	{
		case DOUBLE_SPEED: UCSRA |=ENABLE_DOUBLE_SPEED; break;
		case NORMAL_SPEED: UCSRA &=ENABLE_NORMAL_SPEED; break;
		default :  UCSRA &=ENABLE_NORMAL_SPEED; break;
	}
	
	if  ( uartx -> OPERATION_MODE == SYNCHRONS )
	{
	    UCSRC |= ENABLE_SYNCHR;
		
	}
	
	switch ( uartx -> PARITY_TYPE )

	{
		case NO_PARITY : UCSRC |=0x80;break;
        case ODD_PARITY : UCSRC |=0xb0;break;
	    case EVEN_PARITY : UCSRC |=0xa0;break;

	}	
	
	if (uartx -> STOP_TYPE == TWO_STOPBIT)
	{
		UCSRC |= 0x88;
	}
		switch (uartx ->DATA_TYPE)
		{
		case BIT_8DATA: UCSRC|=0x80;
		                UCSRC&=0xf8;
						UCSRC|=0x83;
						break;
		case BIT_7DATA:	UCSRC|=0x80;
		                UCSRC&=0xf8;
						UCSRC|=0x82;
						break;
     	case BIT_6DATA:	UCSRC|=0x80;
		               UCSRC&=0xf8;
						UCSRC|=0x81;
						break;	
		case BIT_5DATA:	UCSRC|=0x80;
		               UCSRC&=0xf8;
						break;	
      	case BIT_9DATA:	UCSRC|=0x80;
		               UCSRC&=0xf8;
					   UCSRC|=0x87;
						break;	
						
			
		}
		
		
		switch(uartx ->BUAD_RATE)
		{
			
		case BAUDRATE_9600:UBRRL&=0x00;
		                  UBRRL=51;
						  break;
		case BAUDRATE_4800:UBRRL&=0x00;
		                  UBRRL=103;
						  break;
		case BAUDRATE_2400:UBRRL&=0x00;
		                  UBRRL=207;
						  break;
			
		}
		
		if (uartx ->INTERRUPT_MODE ==ENABLE_INTERRUPT)
		{
			
		UCSRB |= 0x80;
		UCSRB |= 0x40;	
			
		}
		
		if (uartx ->TRANSMITTER_MODE== ENABLE_TRANSMITTER)
		{
			
		UCSRB |= 0x08;
			
		}
		
			if (uartx ->TRANSMITTER_MODE== ENABLE_TRANSMITTER)
		{
			
		UCSRB |= 0x08;
			
		}
		   if (uartx ->RECEIVER_MODE == ENABLE_RECEIVER )
	  	{
			
		UCSRB |= 0x10;
			
		}
	
}


u8 UART_Sendbuffer( u8 * Copy_buffer , u8 size)
{
	u8 Local_status=0;
	
	if (Busy_flag ==0)
{
        	if ( Copy_buffer!=NULL && size !=0)
	      {
	       	Busy_flag=1;
		    tx_buffer.Buffer=Copy_buffer;
		    tx_buffer.size=size;
		    UDR =tx_buffer.Buffer[count];
		   count++;
		
       	}else
	           {
		
	                 Local_status=1;
	         }
}else
{

  Local_status=1;
}	
	
	return Local_status;
	
	
	
	
}


u8 UART_Receivebuffer(u8 * Copy_buffer,  u8 size)
{
	
	u8 Local_status=0;
	
		if (Busy_flag2 ==0)
{
        	if ( Copy_buffer!=NULL && size !=0)
	      {
	       	Busy_flag2 =1;
		    tx_buffer.Buffer=Copy_buffer;
		    tx_buffer.size=size;
		
       	}else
	           {
		
	                 Local_status=1;
	         }
}else
{

  Local_status=1;
}	
	
	
	
	
	
	
}

void __vector_15 (void)__attribute__((signal));
void __vector_15 (void)
{
	if (count==tx_buffer.size)
	{
		count=0;
		tx_buffer.Buffer=NULL;
		Busy_flag=0;
		* ptr_tx();
		
		
	}else
	{
		UDR= tx_buffer.Buffer[count];
		count++;
		
	}
	
	
	
	
}




void __vector_13 (void)__attribute__((signal));
void __vector_13 (void)
{
	if (count==rx_buffer.size)
	{
		rx_count=0;
		rx_buffer.Buffer=NULL;
		Busy_flag2=0;
		* ptr_rx();
		
		
	}else
	{
		rx_buffer.Buffer[count]=UDR;
		count++;
		
	}
	
	
	
	
}



void UART_TXsetcallbkfn( void(*p)(void))
{
	ptr_tx= p;
	
}


void UART_RXsetcallbkfn( void(*p)(void))
{
	ptr_rx= p;
	
}