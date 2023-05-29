#include <stdint.h>
#include "stm32f410rx.h"


#define GPIOAEN (1U<<0)
#define periph_freq 16000000
#define  baudrate     115200
void UART_TX_init(void);
void senddata(int a);



/*static uint16_t calculer_baudrate(uint32_t freq , uint32_t baud)
         {return(freq+((baud/2U)/baud));

         }
*/


static void set_baudrate_usart2(USART_TypeDef* usart,uint32_t freq , uint32_t baud)
          {usart->BRR|=(1U<<0);
           usart->BRR|=(1U<<1);
           usart->BRR|=(1U<<3);
           usart->BRR|=(1U<<7);
          }
int main(void)
             {UART_TX_init();
	          while(1)
	               {
	        	    senddata((uint8_t )'a');
	               }

             }


void UART_TX_RX_init(void)
     {/*************enable clock access to gpioA *******************/
	   RCC->AHB1ENR|=GPIOAEN;


	   /*************Set PA2 mode to alternate func***************/
	   GPIOA->MODER|=(1U<<5);
       GPIOA->MODER&=~(1U<<4);

       /******************Set PA3 mode toalternate func****************/


       /*****Configure PA2 to AF7 As indicated in the alternate function mapping */
       GPIOA->AFR[0]|=(1U<<8);
       GPIOA->AFR[0]|=(1U<<9);
       GPIOA->AFR[0]|=(1U<<10);

       /***********Configure PA3 to PA7 as indicated in the alternate func mapping******/
       GPIOA->AFR[0]|=(1U<<12);
       GPIOA->AFR[0]|=(1U<<13);
       GPIOA->AFR[0]|=(1U<<14);

       /**************enable clock access to usart2******************/
       RCC->APB1ENR|=(1U<<17);

       /****************CONFIGURE BAUDRATE***********/
       set_baudrate_usart2(USART2,periph_freq,baudrate);
       /*********configure transfert direction */
       //***********we can make it tx and rx same time********
       USART2->CR1|=(1U<<3);
       USART2->CR1|=(1U<<2);
       /***********enable uart module **************/
       USART2->CR1|=(1U<<13);
         }

char Receivedata(void){

/*************************return the received char ==> DATA REGISTER    *************/
return (USART2->DR);
/*********make sure the reveived data register is not empty ==> status register***********/
while(((USART2->SR)&(1U<<5))!=0){}
}

void senddata(int a)
     {/*make sure the Transmit data register is empty : check the STATUS REG */


        	   USART2->DR=a;
        	   while(!(USART2->SR)&&(1U<<6)) {}

     }


