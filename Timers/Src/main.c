#include "stm32f410rx.h"

#include <stdio.h>

#include "Timer.h"
#include "uart.h"

#define UIFFLAG (1U<<0)
#define pin5 (1U<<5)




                 int main(void)
{                    RCC->AHB1ENR|=(1U<<0);
                	 GPIOA->MODER|=(1U<<10);

                	 Timerinit__1HZ();
                	 UART_TX_init();

                	 while(1)
                	 {/**********wait until 1 SECOND HAS PASSED***************/
                		while(!(TIM5->SR & UIFFLAG)){}
                	  /**********clear the flag***************************/
                		TIM5->SR&=~UIFFLAG;
                		printf("1 sec passed");
                		GPIOA->ODR^=pin5;

                	 }



}
