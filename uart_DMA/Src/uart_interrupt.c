#include "stm32f410rx.h"
#include"uart_interrupt.h"
#include "uart.h"


#define GPIOAEN (1U<<0)
#define periph_freq 16000000
#define  baudrate     115200
#define    RXNE_interrupt_enable (1U<<5)


void       UART_RX_TX_interrupt_init(void)
           {/*************enable clock access to gpioA *******************/
      	   RCC->AHB1ENR|=(1U<<0);


      	   /*************Set PA2 mode to alternate func***************/
       	     GPIOA->MODER|=(1U<<5);
             GPIOA->MODER&=~(1U<<4);
             /*****Configure PA2 to AF7 As indicated in the alternate function mapping */
             GPIOA->AFR[0]|=(1U<<8);
             GPIOA->AFR[0]|=(1U<<9);
             GPIOA->AFR[0]|=(1U<<10);
             /**********Set PA3 mode to alternate func**************/
             GPIOA->MODER|=(1U<<7);
             GPIOA->MODER&=~(1U<<6);

             /***********Configure PA3 TO AF7***********/
             GPIOA->AFR[0]|=(1U<<12);
             GPIOA->AFR[0]|=(1U<<13);
             GPIOA->AFR[0]|=(1U<<14);

             /**************enable clock access to usart2******************/
             RCC->APB1ENR|=(1U<<17);

             /****************CONFIGURE BAUDRATE***********/
             set_baudrate_usart2(USART2,periph_freq,baudrate);
             /*********configure transfert direction */
             USART2->CR1|=((1U<<3)|(1U<<2));
             /***********enable uart module **************/
             USART2->CR1|=(1U<<13);

           /*enable receiver interruption*/
             USART2->CR1|=RXNE_interrupt_enable;
           /*enable nvic interruption*/
             NVIC_EnableIRQ(38);

           }




static void set_baudrate_usart2(USART_TypeDef* usart,uint32_t freq , uint32_t baud)
          {usart->BRR|=(1U<<0);
           usart->BRR|=(1U<<1);
           usart->BRR|=(1U<<3);
           usart->BRR|=(1U<<7);
          }
