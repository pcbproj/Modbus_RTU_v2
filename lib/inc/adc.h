#ifndef ADC_H
#define ADC_H

#include "stm32f4xx.h"


void ADC1_Init(void);
void ADC1_StartConversion(void);
uint16_t ADC1_Read(void);



#endif