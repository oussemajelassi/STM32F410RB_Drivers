#include "stm32f410rx.h"
#define GPIOAEN      (1U<<0)
#include "Input_Capture.h"



void TIM1_PA8_input_capture(void)
    {
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR|=GPIOAEN;
	/*Set PA8 to alternate func*/
	  GPIOA->MODER|=(1U<<17);
	/*Set PA8 to AF1*/
	  GPIOA->AFR[1]|=(1U<<0);
	/*Enable clock access to TIM1*/
	  RCC->APB2ENR|=(1U<<0);
	/*Set prescaler*/
	  TIM1->PSC=16000-1;
	  /*ARR*/
	  //TIM1->ARR=0xFFFF;
	/*Set timer to input capture*/
	 TIM1->CCMR1|=(1U<<0);
	 TIM1->CCMR1|=(1U<<6);
	/*Choose rising edge*/
	  /*Enable capture*/
	  TIM1->CCER|=(1U<<0);
	   /*Set reset mode*/

      /*Enable timer interrupt*/
	 // TIM1->DIER|=(1U<<0);
	  //TIM1->DIER|=(1U<<1);
	  /*enable nvic interrupts*/
	 /* NVIC_EnableIRQ(24);
	  NVIC_EnableIRQ(25);
	  NVIC_EnableIRQ(26);
	  NVIC_EnableIRQ(27);*/
	  /*Enable the timer*/
	  TIM1->CR1|=(1U<<0);
      }
