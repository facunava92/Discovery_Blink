/*
 * delay.c
 *
 *  Created on: 24 de jun. de 2016
 *      Author: facun
 */
#include "delay.h"
#include "stdint.h"

void delay(uint16_t delay) {
	uint8_t i=0;
	while (delay-- > 0) {
		for (i = 100; i > 0; i--)
			asm("nop");
		// Instrucción en assembler para que el micro no haga nada
	}
}
