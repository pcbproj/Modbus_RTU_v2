#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"

#include "main.h"

/*
Добавление протокола Modbus в ранее написанную программу. 
Команды передаются от ПК, исполнитель - МК.  
МК засвечивает светодиоды по команде с ПК.
отправляет состояние кнопок по запросу от МК.  

модель данных MODBUS RTU: 
для каждого блока своя таблица. 

LEDS = Coils
BUTTONS = Discretes Inputs

*/



void SysTick_Handler(void){		// прервание от Systick таймера, выполняющееся с периодом 1 мкс
	timer_counter();
}




void TIM2_IRQHandler(void){
	TIM2->SR &= ~(TIM_SR_UIF);	// clear UIF flag
	ModbusTimersIRQ();
	NVIC_ClearPendingIRQ(TIM2_IRQn);
}



void USART6_IRQHandler(void){
	if((USART6->SR & USART_SR_RXNE) != 0){
		ModbusReception();
		NVIC_ClearPendingIRQ(USART6_IRQn);
	}
}



int main(void) {
	uint8_t rs485_rx_byte;
	uint8_t rs485_tx_array[12] = {"RS485 RX OK\n"};

	uint8_t modbus_req_rx[256];
	uint8_t modbus_rx_len;
	uint8_t modbus_err;
	uint8_t modbus_answer_tx[256];
	uint8_t modbus_answer_len;
	uint16_t tim2_counter  = 0;

	RCC_Init();
	__enable_irq();								// enable global interrupts
	
	SysTick_Config(SYSTICK_TIMER_CONST);		// systick period 1 us

	GPIO_Init();
	USART6_InitIRQ();
	TIM2_InitOnePulseIRQ();

	LED1_OFF();
	LED2_OFF();
	LED3_OFF();

	ModbusTimerStart(DELAY_3_5_BYTE_US);

	while(1){
	
		modbus_err = RequestParsingOperationExec( modbus_req_rx, modbus_rx_len, modbus_answer_tx, &modbus_answer_len );

	}	// while(1)
}	// main()

/*************************** End of file ****************************/
