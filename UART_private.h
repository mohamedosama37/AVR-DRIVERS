#ifndef UART_private_h
#define UART_private_h


#define  UBRRL    *((u8 *)0x29)
#define  UCSRB    *((u8 *)0x2A)
#define  UCSRA    *((u8 *)0x2B)
#define  UDR      *((u8 *)0x2C)
#define  UCSRC    *((u8 *)0x40)
	
	


#define ENABLE_DOUBLE_SPEED 0x40
#define ENABLE_NORMAL_SPEED 0xbf
#define ENABLE_SYNCHR   0xc0
#define ENABLE_ASYNCHR  0x


typedef struct
{
	u8 SPEED_MODE;
	u8 OPERATION_MODE;
	u8 PARITY_TYPE;
	u8 STOP_TYPE;
	u8 DATA_TYPE;
	u8 BUAD_RATE;
	u8 INTERRUPT_MODE;
	u8 TRANSMITTER_MODE;
	u8 RECEIVER_MODE ;
}initail;








#endif