#include "adc.h"



void ADC1_Init(void){

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;			// ADC1 clock enable
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;		// GPIOA clock enable for ADC1_IN port
												
	GPIOA->MODER |= GPIO_MODER_MODE5;			// GPIOA_PA5 in alternative mode (ADC1_CH5)
	ADC1->CR1 &= ~ADC_CR1_RES;					// Selected 12-bit ADC sample
												
	ADC1->SMPR2 |= ADC_SMPR2_SMP5_0;			// выбираем время конвертирования 15 тактов для канал 5
	ADC1->SQR1  &= ~(ADC_SQR1_L);				// conversion Sequence length = 1 
	ADC1->SQR3  |= (5 << ADC_SQR3_SQ1_Pos);		// use first place in conversion sequence for channel 5 of ADC1

	ADC1->CR2	|= ADC_CR2_CONT;				//	conversion continuous mode
	ADC1->CR2	|= ADC_CR2_ADON;				// ADC enable

	ADC1->CR2	|= ADC_CR2_SWSTART;				// Software start of conversion

}



void ADC1_StartConversion(void){
	ADC1->CR2 |= ADC_CR2_SWSTART;	// ADC1 start conversion regular channels
}



uint16_t ADC1_Read(void){
	//while( !( ADC1->SR & ADC_SR_EOC ) ){};	
	return ADC1->DR;
}
