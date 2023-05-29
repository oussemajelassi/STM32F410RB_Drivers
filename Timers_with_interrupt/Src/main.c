#include "stm32f410rx.h"

#include <stdio.h>

#include "timerinterrupt.h"
#include "uart.h"
#include "Encoder_mode.h"
#define UIFFLAG (1U<<0)
#define pin5 (1U<<5)


static void Asservir(void)
{


                          }

                 int main(void)
{                    Encoder_mode_TIM1();
                	 Timerinit_interrupt();
while(1){}
}



                 void TIM5_IRQHANDLER(void)
                 {/*Clear the flag*/
                	 TIM5->SR|=(1U<<0);
                  /*do something*/
                	 Asservir();
                 }
