#include "stm32f410rx.h"

#include <stdio.h>

#include "Timer.h"
#include "uart.h"
#include "output_compare.h"
#define UIFFLAG (1U<<0)
#define pin5 (1U<<5)

unsigned int a;


                 int main(void)
{
                	 Timer_PA0_init__1HZ();
                	 while(1)
                	 {
                		 a=(GPIOA->IDR)&(1U<<0);
                	 }



}
