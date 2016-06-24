/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

#define BIT24 0x1000000
#define BIT26 0x4000000
//#define BIT28 0x1000000
//#define BIT30 0x1000000
#define BIT12 0x1000
#define BIT13 0x2000
#define BIT14 0x4000
#define BIT15 0x8000

void delay(uint16_t delay);

void main(void) {
	// CONFIGURACIÓN
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	// Habilito el Clock del bus GPIO

	GPIOD->MODER |= BIT24;
	GPIOD->MODER |= BIT26;					// Configuro como salida el bit 13

	while (1) {
		delay(5000);
		GPIOD->ODR ^= BIT12;
		GPIOD->ODR ^= BIT13;
	}
}

void delay(uint16_t delay) {
	uint8_t i=0;
	while (delay-- > 0) {
		for (i = 1000; i > 0; i--)
			asm("nop");
		// Instrucción en assembler para que el micro no haga nada
	}
}
