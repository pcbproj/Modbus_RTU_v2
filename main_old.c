/*********************************************************************
Добавление протокола Modbus в ранее написанную программу. 
Команды передаются от ПК, исполнитель - МК.  
МК засвечивает светодиоды по команде с ПК.
отправляет состояние кнопок и отсчеты ADC по запросам.  

модель данных MODBUS RTU у нас будет такая: 
для каждого блока своя таблица. 

LEDS = Coils
Кнопки = Discretes Inputs
ADC = Input Registers

*/

#include "main.h"


void SysTick_Handler(void){		// прервание от Systick таймера, выполняющееся с периодом 1 мкс

	timer_counter();

}


int main(void) {

	RCC_Init();

	GPIO_Init();

	USART6_Init();	// USART6 used for RS485 communication
	
	ADC1_Init();

	SysTick_Config(83);	// systick interrupt every 1 us
	
	while (1){
	
	
	
	
	}
}

/*************************** End of file ****************************/
