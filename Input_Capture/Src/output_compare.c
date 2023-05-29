/*
 * output_compare.c
 *
 *  Created on: Jan 26, 2022
 *      Author: ousjl
 */


#include "stm32f410rx.h"
#include "Timer.h"
#include "output_compare.h"
/*********************************** I will use TIMER5 *****************************/
#define Timer5EN     (1U<<3)
#define CNTEN        (1U<<0)
#define COMPAREEN    ((1U<<4)|(1U<<5))
#define GPIOAEN      (1U<<0)
#define ComparemodeEN (1U<<0)
#define PA5ALTEREN    (1U<<1)





void Timer_PA0_init__XHZ(int X){
	/*enable clock access to GPIOA*/
     RCC->AHB1ENR|=GPIOAEN;

	/*Set PA0 to alternate function*/
    GPIOA->MODER|=PA5ALTEREN;

    /*set PA0 to alternate func tim5 channel*/
    GPIOA->AFR[0]|=(1U<<1);

    /***********************enable clock access to TIMER5	**************/
	RCC->APB1ENR|=Timer5EN;

    /***********************Set prescaler*****************************/
	TIM5->PSC=1599; // 1600 -1

    /***********************SET ARR***********************************/
	TIM5->ARR=(10000/X) -1; //10000-1  BECAUSE 16,000,000=1600*10000

    /*********Set timer5 to output compare toggle mode*********/
	TIM5->CCMR1=COMPAREEN;

	/*enable tim5 channel 1 to compare mode*/
	TIM5->CCER|=ComparemodeEN;


	/***********************Clear counter*****************************/
	TIM5->CNT=0;
	/***********************ENABLE TIMER *****************************/
	TIM5->CR1|=CNTEN;

                         }



