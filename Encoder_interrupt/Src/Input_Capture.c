#include "stm32f410rx.h"
#define GPIOAEN      (1U<<0)
#include "Input_Capture.h"



void TIM1_PA8_input_capture(void)
    {
	/*Enable cloch access to GPIOA*/
	RCC->AHB1ENR|=GPIOAEN;
	/*Set PA8 to alternate func*/
	  GPIOA->MODER|=(1U<<17);
	/*Set PA8 to AF1*/
	  GPIOA->AFR[1]|=(1U<<0);
	/*Enable clock access to TIM1*/
	  RCC->APB2ENR|=(1U<<0);
	/*Set prescaler*/
	  TIM1->PSC=16000-1;
	/*Set timer to input capture*/
	 TIM1->CCMR1|=(1U<<0);
	/*Choose rising edge*/
	  /*Enable capture*/
	 TIM1->CCER|=(1U<<0);
	/*Enable the timer*/
	TIM1->CR1|=(1U<<0);



    }
