#include <stdint.h>
#include "stm32f410rx.h"
#include <stdint.h>

#include "uart.h"
#include "uart_DMA.h"


char key;
char key1;

#define DMA1_TCIF6     (1U<<21)
#define DMA1_CTCIF6    (1U<<21)

char message [31]="hello my name is Oussema \n\r";
int main(void)
             {
	UART_TX_init();
	uart_DMA1_init((uint32_t) &USART2->DR,(uint32_t) message,27);


	          while(1)
	               {


	               }

             }
void dma_callback(){
	/*Do something*/

                  }




void  DMA1_Stream6_IRQHandler(void){
	/*Check if the transfer is complete*/
	if(DMA1->HISR&(DMA1_TCIF6)){
	/*clear the flag*/
	DMA1->HISR|=DMA1_CTCIF6;
	/*do something*/
	dma_callback();
	                           }
                                   }




