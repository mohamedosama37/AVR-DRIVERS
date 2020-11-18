#ifndef Interrupt_interface_h
#define Interrupt_interface_h





#define ENABLE    1
#define DISENABLE 0
#define RISING    0
#define FALLING   2
#define ALL       3

#define INTO      0
#define INT1      1
#define INT2     2


void Initalize (void);
u8 Enable_Interrupt (u8 Copy_u8Interrupt);
u8 DisEnable_Interrupt (u8 Copy_u8Interrupt);

u8 SetCallBackFn ( u8 Copy_u8Interrupt, void  (*Copy_pvidCallBack)(void));



#endif