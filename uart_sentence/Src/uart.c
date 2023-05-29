/*
 * uart.c
 *
 *  Created on: Jan 24, 2022
 *      Author: ousjl
 */

#include "uart.h"

#define GPIOAEN (1U<<0)
#define periph_freq 16000000
#define  baudrate     115200




void senddata(int a);
       char __io_putchar(char ch){
	                  senddata(ch);
	                   return(ch);
                           }


   static void set_baudrate_usart2(USART_TypeDef* usart,uint32_t freq , uint32_t baud)
          {
	   	   usart->BRR|=(1U<<0);
           usart->BRR|=(1U<<1);
           usart->BRR|=(1U<<3);
           usart->BRR|=(1U<<7);
          }

   void UART_TX_init(void)
        {/*************enable clock access to gpioA *******************/
   	   RCC->AHB1ENR|=GPIOAEN;


   	   /*************Set mode to alternate func***************/
   	   	   GPIOA->MODER|=(1U<<5);
           GPIOA->MODER&=~(1U<<4);
          /*****Configure to AF7 As indicated in the alternate function mapping */
          GPIOA->AFR[0]|=(1U<<8);
          GPIOA->AFR[0]|=(1U<<9);
          GPIOA->AFR[0]|=(1U<<10);

          /**************enable clock access to usart2******************/
          RCC->APB1ENR|=(1U<<17);

          /****************CONFIGURE BAUDRATE***********/
          set_baudrate_usart2(USART2,periph_freq,baudrate);
          /*********configure transfert direction */
          USART2->CR1|=(1U<<3);
          /***********enable uart module **************/
          USART2->CR1|=(1U<<13);
            }





   void senddata(int a)
        {/*make sure the Transmit data register is empty : check the STATUS REG */


           	   USART2->DR=a;
           	   while(!(USART2->SR)&&(1U<<6)) {}

        }
