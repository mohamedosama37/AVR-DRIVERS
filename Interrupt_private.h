#ifndef Interrupt_private_h
#define Interrupt_private_h





#define MCUCSR  *((u8*)0x54)
#define GICR   *((u8*)0x5B)
#define SREG   *((u8*)0x5f)
#define MCUCR   *((u8*)0x55)
#define GIFR   *((u8*)0x5A)








 void __vector_3 (void)__attribute__((signal));
  void __vector_1 (void)__attribute__((signal));
   void __vector_2 (void)__attribute__((signal));



#endif