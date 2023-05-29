#include "stm32f410rx.h"

#include <stdio.h>
#include "PWM.h"
#include "Timer.h"
#include "uart.h"
#include "output_compare.h"
#include "Systick.h"
#define UIFFLAG (1U<<0)
#define pin5 (1U<<5)

unsigned int a;


                 int main(void)
{


                	 RCC->AHB1ENR|=(1U<<0);
                	 GPIOA->MODER|=(1U<<10);
               while(1) {
            	   GPIOA->ODR^=pin5;
            	   systickdelay (1);
            	   printf("1sec passsed");
               }


}
