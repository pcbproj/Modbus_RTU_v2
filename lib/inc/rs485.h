#ifndef RS485_H
#define RS485_H

/**************************

Module RS485 use module USART6 for communication

**************************/

#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"

#define RS485_USART_NUM		6	// USART6 used for communicate through RS485

/***** DE pin ***********
	DE = 1 -> TX mode
	DE = 0 -> RX mode
*************************/

// WARNING: при изменении порта DE_PORT требуется поправить ф-ию DE_PinInit(void)
#define DE_PORT				GPIOD
#define DE_PIN_NUM			7


#define DE_High()		( DE_PORT -> BSRR |= 1 << DE_PIN_NUM )
#define DE_Low()		( DE_PORT -> BSRR |= 1 << ( DE_PIN_NUM + 16 ) )




void RS485_Init(uint8_t USART_number);	// инициализация RS485 и соответствующего для него модуля USART
void DE_PinInit(void);



/******
Функция использует модуль USART под номером USART_number для коммуникации
требуется указать номер USART, через который будет выполняться обмен данными
*******/
void RS485_TxArray(uint8_t USART_number, uint8_t tx_array[], uint8_t TxByteNumber);




/******
Функция использует модуль USART под номером USART_number для коммуникации
требуется указать номер USART, через который будет выполняться обмен данными
Функция возвращает принятый байт
*******/
uint8_t RX485_RxByte(uint8_t USART_number, uint8_t *rx_byte);




#endif