#include "stm32f410rx.h"

#include <stdio.h>

#include "Timer.h"
#include "uart.h"
#include "output_compare.h"
#include "Input_Capture.h"
#define UIFFLAG (1U<<0)

#define pin5 (1U<<5)
#include "encoder_interrupt.h"
int a;
uint32_t ticks;
static void TIM1_CALLBACK(void){
	                  ticks+=TIM1->CNT;
	                  TIM1->CNT=0;
}
                 int main(void)
{Encoder_mode_TIM1_interrupt();
UART_TX_init();

while(1){a=read_encoder();
	printf(read_encoder());
}
}



                 void TIM1_IRQHandler(void)
                 {/*clear the interruption flag*/
                	 TIM1->SR&=~(1U<<12);
                  /*reset the counter*/
                  TIM1_CALLBACK();
                 }
