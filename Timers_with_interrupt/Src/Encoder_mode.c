#include"stm32f410rx.h"
#include "Encoder_mode.h"

uint32_t read_encoder(void)
{
return (TIM1->CNT);
}


void Encoder_mode_TIM1(void)
   {/*enable clock acess to GPIOA*/
	RCC->AHB1ENR|=(1U<<0);
	/*set PA8 AND PA9 TO alternate func*/
	GPIOA->MODER|=(1U<<17);
	GPIOA->MODER|=(1U<<19);
	/*Set PA8 and PA9 alternate func to AF1*/
	GPIOA->AFR[1]|=(1U<<0);
	GPIOA->AFR[1]|=(1U<<4);

	/*enable clock access to timer*/
		RCC->APB2ENR|=(1U<<0);




	/*Set the channels menish fehem barsha chyaamel lhak*/
	TIM1->CCMR1|=(1U<<8);
	TIM1->CCMR1|=(1U<<0);
	/*set both channels to input*/

	/*Set encoder mode*/
	TIM1->SMCR|=(1U<<0);
	TIM1->SMCR|=(1U<<1);
	/*Set ARR Value*/
	LPTIM1->ARR=0xFFFF;

	/*enable timer*/
	TIM1->CR1|=(1U<<0);
	/*Clear Timer*/
	TIM1->CNT=0;




	}
