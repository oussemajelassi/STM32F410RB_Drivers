#include "stm32f410rx.h"
#include "Systick.h"
#define systick_val      16000000
#define ENABLE_SYSTICK   (1U<<0)
#define INTER_Clock      (1U<<2)
void  systickdelay(int s)
{
         /*******************Enable Timer***********/
	     SysTick->CTRL|=ENABLE_SYSTICK;
	     /*******************choose internal clock**/
	     SysTick->CTRL|=INTER_Clock;
	     /*******************Set the number of cycles per seconds****/
	     SysTick->LOAD=systick_val;
	     /*Clear SysTick timer*/
	     SysTick->VAL=0;

	     for (int i=0;i<s;i++)
	       {
	    	while (SysTick->CTRL&(1U<<16)){}

	       }

	     SysTick->CTRL=0;
}
