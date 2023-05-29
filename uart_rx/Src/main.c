#include <stdint.h>
#include "stm32f410rx.h"
#include <stdio.h>

#include "uart.h"


char key;


int main(void)
             {UART_RX_TX_init();
	          while(1)
	               {
	      key = readdata();
	               }

             }







