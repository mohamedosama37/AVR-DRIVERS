#ifndef ADC_interface_h
#define ADC_interface_h



typedef struct
{

	u8  ADCL ;
	u8  ADCH ;
	u8  ADCSRA ;
	u8  ADMUX ;

}AVR_ADC;

#define ADCx ((AVR_ADC *)  0x24)

#define LEFT_ADJUSMENT   0
#define RIGHT_ADJUSMENT  1


#define  ADC_ENABLE      0
#define  ADC_DISABE      1

#define INTERRUPT_ENABLE  0
#define INTERRUPT_DISABLE 1

#define PRESCAL_2        0
#define PRESCAL_4       1
#define PRESCAL_8       2
#define PRESCAL_16      3
#define PRESCAL_32      4
#define PRESCAL_64      5
#define PRESCAL_128     6

#define TRIGGER_FREERUNNING        0
#define TRIGGER_ANALOGCOMPARATOR   1
#define TRIGGER_EXTERNAL_INTERRUPT 2

#define INTERNAL_REFRENCE          0
#define EXTERNAL_REFRENCE          1
#define INTERN_EXTERNREF           2

#define SELECTED_PINO              0
#define SELECTED_PIN1              1
#define SELECTED_PIN2              2
#define SELECTED_PIN3              3
#define SELECTED_PIN4              4
#define SELECTED_PIN5              5
#define SELECTED_PIN6              6
#define SELECTED_PIN7              7






#define ADC_INTERNAL_MODE        0x3f
#define ADC_EXTERNAL_MODE        0x40
#define ADC_EXTANDINT_MODE       0xc0

#define ADC_PINO                 0xe0
#define ADC_PIN1                 0x01
#define ADC_PIN2                 0x02
#define ADC_PIN3                 0x03
#define ADC_PIN4                 0x04
#define ADC_PIN5                 0x05
#define ADC_PIN6                 0x06
#define ADC_PIN7                 0x07


#define ADC_LEFTADJ              0x20
#define ADC_RIGHTADJ             0xdf



u16 ADC_BlockReadConversion ();
void ADC_initalize ();

















#endif
