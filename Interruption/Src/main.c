#include "stm32f410rx.h"
#include "interrupt.h"
#include <stdio.h>

/*The System Configuration Controller manages the selection of the GPIO to the external interrupt*/
int flag=1;
#define sysconfig (1U<<14)
#define gpiorccenable (1U<<2)


#define PORTC  (1U<<13)
#define EXTI13  (1U<<13)

uint32_t a;
void EXTI15_10_IRQHandler(void);

static void exti_callback(void);
 int compteur=0;

void push_button_init(void)
    {/*disable global interrupts*/
     __disable_irq();

	/*select pc13 as input*/

		/*enable clock access to GPIOC*/
	    RCC->AHB1ENR|=gpiorccenable;
	/*********************enable clock access to sys config*************************/
		RCC->APB2ENR|=sysconfig;

	/***********************enable clock access to exti************/
		RCC->APB2ENR |= (1U << 15);

		GPIOC->PUPDR |= (1U << 26) ;

	/*SELECT PORT C FOR EXTI13*/
	SYSCFG->EXTICR[3] |= (1U<<5);

    /*unmask EXTI13*/
	EXTI->IMR = 0x2000;

	/*Select falling edge trigger*/
	EXTI->FTSR = (1U<<13);

	/*enable exti13 line in nvic*/
    NVIC_EnableIRQ(40);
    /*enable glabal interrupts*/
    __enable_irq();

    }



int main (void){
	push_button_init();
	GPIOC->PUPDR=(1U<<27);


while(1){
  a = GPIOC->IDR;
}
}



/********************        to find the handler check the startup up folder      *********************/


void exti_callback(void){
     compteur+=1;
                         }
void EXTI15_10_IRQHandler(void)// ****** c'est la fonction à executer lors d'une interruption***********


{/*check if exti 13 is causing the interruption ==>       pending register     */
	//if (EXTI->PR & LINE13)

	   /*remove pending*/
		EXTI->PR|=LINE13; // pending register bit is cleared when programmed to 1
		/*desired function*/
		exti_callback();


 }


void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}



