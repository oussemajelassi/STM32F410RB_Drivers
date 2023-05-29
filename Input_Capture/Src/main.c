#include "stm32f410rx.h"

#include <stdio.h>

#include "Timer.h"
#include "uart.h"
#include "output_compare.h"
#include "Input_Capture.h"
#include "Systick.h"
#define UIFFLAG (1U<<0)
#define pin5 (1U<<5)

unsigned int a;
unsigned int b;
int freq;
int period;
int previous;
int current;
                 int main(void)
{
                	 Timer_PA0_init__XHZ(2);
                	 TIM1_PA8_input_capture();
while(1){

while (!(TIM1->SR&(1U<<1))){}
period=(TIM1->CCR1)/1000;
TIM1->CNT=0;

        }


}





