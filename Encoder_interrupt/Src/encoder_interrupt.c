#include"stm32f410rx.h"

#include "encoder_interrupt.h"
uint32_t read_encoder(void)
{
return (TIM1->CNT);
}


void Encoder_mode_TIM1_interrupt(void)
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
	/*Set channel 4 to PWM mode1*/
    TIM1->CCMR2|=(1U<<14);
    TIM1->CCMR2|=(1U<<13);
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
    /*enable timer interrupt*/
	TIM1->DIER|=(1U<<0);
	/*enable interruption in nvic*/
    NVIC_EnableIRQ(27);
    /*timer 1 break interrupt enable*/
    NVIC_EnableIRQ(26);
    /*timer 1 trigger and commutation enable*/
    NVIC_EnableIRQ(25);
    /*TIM1 Break interrupt*/
    NVIC_EnableIRQ(24);
    /*Set CCR4 for channel 4*/
    TIM1->CCR4=4000;
    /* Capture/Compare 4 output enable*/
    TIM1->CCER|=(1U<<12);
    /* Capture/Compare 4 interrupt enable*/
    TIM1->DIER|=(1U<<4);
    /*update event enable*/
	}
