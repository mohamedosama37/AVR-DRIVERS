#ifndef Interrupt_config_h
#define Interrupt_config_h












typedef struct
{
	
	u8 Mode ;
	u8 Event;
}Int;

Int Init[3]={{ENABLE,RISING},{DISENABLE,RISING},{DISENABLE,RISING}};
















#endif