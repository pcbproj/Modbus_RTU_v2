#include "timer.h"



void TIM2_InitOnePulseIRQ(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* settings timer TIM2*/
	TIM2->PSC = 41;					// TIM2 clock 1 MHz
	TIM2->CR1 |= TIM_CR1_OPM;		// One pulse counting mode 
	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->EGR  |= TIM_EGR_UG;
	TIM2->SR   &= ~TIM_SR_UIF;
	NVIC_EnableIRQ(TIM2_IRQn);		// timer 2 interrupt enable
}





void TIM2_Start(uint16_t cycles_number){
	TIM2->ARR = cycles_number - 1;
	TIM2->CNT = 0x00000000;
	TIM2->SR &= ~(TIM_SR_UIF);		// clear UIF flag
	TIM2->CR1  |= TIM_CR1_CEN;		// timer 2 clock enable
}


//============================================





void TIM2_StartIRQ(uint16_t cycles_number){
	TIM2->ARR = cycles_number - 1;
	TIM2->CNT = 0x00000000;
	TIM2->SR &= ~(TIM_SR_UIF);		// clear UIF flag
	TIM2->CR1  |= TIM_CR1_CEN;		// timer 2 clock enable
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);		// timer 2 interrupt enable
}





void TIM2_Init(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* settings timer TIM2*/
	TIM2->PSC = 41;					// TIM2 clock 1 MHz
	TIM2->CR1 &= ~(TIM_CR1_DIR);	// TIM2 upcounter
	//TIM2->ARR = 999;				// counts number for 1 kHz timer interrupt 
	//TIM2->CR1  |= TIM_CR1_CEN;
	//TIM2->EGR  |= TIM_EGR_UG; 
}





void TIM2_InitOnePulse(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* settings timer TIM2*/
	TIM2->PSC = 41;					// TIM2 clock 1 MHz
	TIM2->CR1 &= ~(TIM_CR1_DIR);	// TIM2 upcounter
	TIM2->CR1 |= TIM_CR1_OPM;		// One pulse counting mode 
	//TIM2->ARR = 999;				// counts number for 1 kHz timer interrupt 
	//TIM2->CR1  |= TIM_CR1_CEN;
	//TIM2->EGR  |= TIM_EGR_UG; 
}




void TIM2_InitIRQ(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	/* settings timer TIM2*/
	TIM2->PSC = 41;					// TIM2 clock 1 MHz
	TIM2->ARR = 999;
	TIM2->EGR  |= TIM_EGR_UG;
	TIM2->CR1  |= TIM_CR1_CEN;
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);		// timer 2 interrupt enable
	
	
}












void TIM2_StopClear(void){
	TIM2->CNT = 0x00000000;
	TIM2->EGR  |= TIM_EGR_UG;		// timer 2 counter clear
	TIM2->SR &= ~(TIM_SR_UIF);		// clear UIF flag
	TIM2->CR1  &= ~(TIM_CR1_CEN);		// timer 2 clock stop
}


void TIM2_Clear(void){
	TIM2->CNT = 0x00000000;
	TIM2->EGR  |= TIM_EGR_UG;		// timer 2 counter clear
	TIM2->SR &= ~(TIM_SR_UIF);		// clear UIF flag
}



uint8_t TIM2_Done(void){
	if( TIM2->SR & TIM_SR_UIF ) {
		TIM2->SR &= ~(TIM_SR_UIF);	// clear UIF-flag
		return 1;
	}
	else return 0;
}