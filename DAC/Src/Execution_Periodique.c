#include "stm32f410rx.h"
#include "Execution_Periodique.h"


    void Executionperiodique__XHZ(int X){

	/***********************enable clock access to timer5	**************/
	RCC->APB1ENR|=(1U<<3);

	/* System controller and external interrupt clock enable*/
	RCC->APB2ENR|=(1U<<15);

	/***********************Set prescaler*****************************/
	TIM5->PSC=0; // 16000 -1

	/***********************SET ARR***********************************/
	TIM5->ARR=1; //1000-1  BECAUSE 16,000,000=16000*1000
	/*****select UE as trigger output */
	TIM5->CR2|=(1U<<5);


    /***********************ENABLE TIMER *****************************/
    TIM5->CR1|=(1U<<0);

    }
