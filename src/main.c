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
#include "delay.h"
#include "Bits.h"


void delay(uint16_t delay);

void main(void) {
	// CONFIGURACIÓN
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	// Habilito el Clock del bus GPIO

	GPIOD->MODER |= BIT24, BIT26, BIT28, BIT28;				// Configuro como salida el bit 12,13,14,15

	while (1) {

		GPIOD->ODR ^= BIT12;
		delay(1000);
		GPIOD->ODR ^= BIT12;
		GPIOD->ODR ^= BIT13;
		delay(1000);
		GPIOD->ODR ^= BIT13;
		GPIOD->ODR ^= BIT14;
		delay(1000);
		GPIOD->ODR ^= BIT14;
		GPIOD->ODR ^= BIT15;

	}
}

