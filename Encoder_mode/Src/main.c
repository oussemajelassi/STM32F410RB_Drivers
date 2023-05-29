#include "stm32f410rx.h"

#include <stdio.h>

#include "Timer.h"
#include "uart.h"
#include "output_compare.h"
#include "Input_Capture.h"
#define UIFFLAG (1U<<0)
#include "Encoder_mode.h"
#define pin5 (1U<<5)

int a;


                 int main(void)
{Encoder_mode_TIM1();
UART_TX_init();

while(1){a=read_encoder();
	printf(read_encoder());



}
}
