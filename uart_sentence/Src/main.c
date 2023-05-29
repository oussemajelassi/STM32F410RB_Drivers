#include <stdint.h>
#include "stm32f410rx.h"
#include <stdio.h>

#include "uart.h"



/*static uint16_t calculer_baudrate(uint32_t freq , uint32_t baud)
         {return(freq+((baud/2U)/baud));

         }
*/



int main(void)
             {UART_TX_init();
	          while(1)
	               {
	        	    printf("oussemaaa\n\r");
	               }

             }







