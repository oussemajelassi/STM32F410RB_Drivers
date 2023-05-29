/*
 * Timer.c
 *
 *  Created on: Jan 25, 2022
 *      Author: oussema
 */
#include "stm32f410rx.h"
#include "timerinterrupt.h"
/*********************************** I will use TIMER5 *****************************/
#define Timer5EN (1U<<3)
#define CNTEN  (1U<<0)
void Timerinit__1HZ(void){
	/***********************enable clock access to APB1	**************/
	RCC->APB1ENR|=Timer5EN;
    /***********************Set prescaler*****************************/
	TIM5->PSC=1599; // 1600 -1
	/***********************SET ARR***********************************/
	TIM5->ARR=9999; //10000-1  BECAUSE 16,000,000=1600*10000
	/***********************Clear counter*****************************/
	TIM5->CNT=0;
	/***********************ENABLE TIMER *****************************/
	TIM5->CR1|=CNTEN;

                         }

void Timerinit_interrupt(void){
	/***********************enable clock access to APB1	**************/
		RCC->APB1ENR|=Timer5EN;
	    /***********************Set prescaler*****************************/
		TIM5->PSC=1599; // 1600 -1
		/***********************SET ARR***********************************/
		TIM5->ARR=9999; //10000-1  BECAUSE 16,000,000=1600*10000
		/***********************Clear counter*****************************/
		TIM5->CNT=0;
		/***********************ENABLE TIMER *****************************/
		TIM5->CR1|=CNTEN;
     	/*enable interruption*/
	    TIM5->DIER|=(1U<<0);
	    /*enable nvic interruption*/
	    NVIC_EnableIRQ(50);

                         }


