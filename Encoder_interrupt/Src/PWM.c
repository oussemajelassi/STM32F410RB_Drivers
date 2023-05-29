#include "stm32f410rx.h"
#include "PWM.h"
#define GPIOAEN   (1U<<0)
#define ALTEREN   (1U<<1)
#define AFMODE    (1U<<1)
#define PWMMODE   ((1U<<6)|(1u<<5))
#define TIM5EN    (1U<<3)
#define EDGEMODE  ((1U<<5)|(1U<<6))
#define OUTPUTEN  (1U<<0)
#define TIMEREN   (1U<<0)
void PWM_PA0_init(void)
  {
	/*Allow clock access to TIM5*/
		RCC->APB1ENR|=TIM5EN;
	/*allow clock access to GPIOA*/
	RCC->AHB1ENR|=GPIOAEN;
	/*Set PA0 TO ALTERNATE FUNC*/
	GPIOA->MODER|=ALTEREN;
	/*Match PA0 alternate func to TIMER5 channel2*/
	GPIOA->AFR[0]|=AFMODE;
	/*Set Prescaler value*/
	TIM5->PSC=15;
	/*Set frequency ==> ARR*/
	TIM5->ARR=999;
	/*Set duty cycle ==>CCR*/
	TIM5->CCR1=332;
	/*set PWM MODE ==>CCMR*/
	TIM5->CCMR1|=(1U<<5);
	TIM5->CCMR1|=(1U<<6);

	/*choose edge aligned mode or center aligned mode  ==>CR1*/
	//TIM5->CR1&=~EDGEMODE;
    /*Choose Counter Direction*/
	/*enable TIMER5 channeel1 AS OUTPUT*/
	TIM5->CCER|=OUTPUTEN;
	/*Clear Counter*/
	TIM5->CNT=0;
	/*enable timer*/
	TIM5->CR1|=TIMEREN;
  }


