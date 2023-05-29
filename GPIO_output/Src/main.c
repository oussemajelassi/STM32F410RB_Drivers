#include "stm32f410rx.h"




#define GPIOAEN (1U<<0)
#define pin5_output (1U<<5)


int main(void)
{RCC->AHB1ENR=(1U<<0);
GPIOA->MODER|=(1U<<10);
GPIOA->MODER&=~(1U<<11);
	while(1){GPIOA->BSRR=(1U<<5);
	         for(int i=0;i<10000;i++){}
	       //GPIOA->BSRR=0x00000000;
	         GPIOA->BSRR=(1U<<21);
             for(int i=0;i<10000;i++){}
	         }
}
