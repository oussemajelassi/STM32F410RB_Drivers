/*
 * ADC.c
 *
 *  Created on: Mar 18, 2022
 *      Author: ousjl
 */
#include <stdint.h>
#include "stm32f410rx.h"
#include "ADC.h"

#define ADC_Clock 			(1U<<8)
#define GPIOA_Clock 		(1U<<0)
#define PA1_analog			((1U<<2)|(1U<<3))
#define SEQ1_Ch1			(1U<<0)
#define length				(1U<<20)
#define ADC_EN				(1U<<0)
#define Start_bit			(1U<<30)
#define EOC 				(1U<<1)
#define CONT				(1U<<1)


void ADC_init(void)
   {
	/*I will use channel 1 == PA1*/
	/*enable clock access to GPIOA*/
	RCC->AHB1ENR|=GPIOA_Clock;
	/*Set PA1 to analog*/
	GPIOA->MODER|=PA1_analog;

	/*******************************Configure ADC*********************/
	/*enable clock access to ADC APB2*/
	RCC->APB2ENR|=ADC_Clock;
	/************Conversion sequence start ===  what is the first channel********/
	// I will use channel 1 first so SEQ 1 is channel 1
	// If i wanted to use for example channel 4 as SEQ2 i should configure SEQ2 as channel 4
	ADC1->SQR3|=SEQ1_Ch1;
	/*Conversion sequence length     ===  How many channels*/
	ADC1->SQR1&=~length;


	/*Enable ADC module*/
	ADC1->CR2|=ADC_EN;

   }


void Start_Conversion(void)
	{/*Set Continuous mode*/
	 ADC1->CR2|=CONT;

	/*Start the conversion*/
	ADC1->CR2|=Start_bit;

	}

uint32_t read_ADC(void)
	{/*wait for conversion to be complete*/
	while(!(ADC1->SR)&EOC){}
	/*return the result*/
	return (ADC1->DR);
    }

