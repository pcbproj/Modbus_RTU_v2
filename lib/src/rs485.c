#include "rs485.h"

// инициализация RS485 и соответствующего для него модуля USART
void RS485_Init(uint8_t USART_number){	
	
	DE_PinInit();
	
	switch(USART_number){
	case 1:
		USART1_Init();
		break;
	case 2:
		USART2_Init();
		break;
	case 6:
		USART6_Init();
		break;
	default:
		__NOP(); // do nothing
	}
}



void DE_PinInit(void){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	DE_PORT -> MODER |= (1 << DE_PIN_NUM*2);
	DE_Low();	// switch to RX mode
}


/******
Функция использует USART n для коммуникации
требуется уаказть номер USART, через который будет выполняться обмен данными
*******/
void RS485_TxArray(uint8_t USART_number, uint8_t tx_array[], uint8_t TxByteNumber){
	uint8_t *tx = tx_array;
	DE_High();	// switch to TX mode
	
	Delay_us(10);

	switch(USART_number){
	case 1:
		usart1_send(tx,TxByteNumber);
		break;
	case 2:
		usart2_send(tx,TxByteNumber);
		break;
	case 6:
		usart6_send(tx,TxByteNumber);
		break;
	default: 
		__NOP();

	}
	Delay_us(10);
	DE_Low();	// switch to RX mode
}




/******
Функция использует USART n для коммуникации
требуется уаказать номер USART, через который будет выполняться обмен данными
Принятый байт сохраняеся в параметр rx_byte
Функция возвращает код ошибки
*******/
uint8_t RX485_RxByte(uint8_t USART_number, uint8_t *rx_byte){
	uint8_t ok_err;
	DE_Low();	// switch to Rx mode
	Delay_us(10);	
	
	ok_err = usart_receive_byte(USART_number, rx_byte);

	Delay_us(10);

	return ok_err;
}