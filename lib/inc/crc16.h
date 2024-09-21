#ifndef CRC16_H
#define CRC16_H

#include <stdlib.h>
#include <stdio.h>
#include "stm32f407xx.h"

#define BYTE_LEN	8
#define POLY_16		0xA001


uint16_t CRC16_Calc(uint8_t input_mass[], uint8_t	mass_len);


#endif
