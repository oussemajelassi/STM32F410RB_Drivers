#include "stm32f410rx.h"
#include <stdint.h>
/* NSS   = 	PA4
 * SCK   = 	PA5
 * MISO  =  PA6
 * MOSI	 =	PA7
 */

#define GPIOAEN 			(1U<<0)
#define Alternate_func		((1U<<11)|(1U<<13)|(1U<<15))
#define AF5					((1U<<20)|(1U<<22)|(1U<<24)|(1U<<26)|(1U<<28)|(1U<<30))
#define PA4_output			(1U<<8)
#define SPI_Clock_EN		(1U<<12)
#define SPI_EN				(1U<<6)
#define Master				(1U<<2)
#define SSM					(1U<<9)
#define SSI					(1U<<8)
#define Busy				(1U<<7)
#define TXE					(1U<<1)


void SPI_init(void)
			{
		/*******************GPIO INIT******************/
			/*Clock access TO GPIOA*/
		RCC->AHB1ENR|=GPIOAEN;
			/* PA5 PA6 PA7 set to alternate function*/
		GPIOA->MODER|=Alternate_func;
			/* PA5 PA6 PA7 set to AF5*/
		GPIOA->AFR[0]|=AF5;
			/*PA4 to output*/
		GPIOA->MODER|=PA4_output;

		/***********************SPI CONFIGURATION***********************/
			/*Clock access to SPI*/
		RCC->APB2ENR|=SPI_Clock_EN;
			/*select baud rate         ** FPCK/4 **   */
		SPI1->CR1|=(1U<<3);
			/*Master/slave*/
		SPI1->CR1|=Master;
			/*Clock polarity and clock phase will be at reset state*/
			/*enable full duplex*/
			/*enable software slave management*/
		SPI1->CR1|=SSM;
			/*enable internal slave select*/
		SPI1->CR1|=SSI;
			/*enable SPI*/
		SPI1->CR1|=SPI_EN;


			}



void SPI_transmit(uint8_t * data,uint32_t size)
    {/*wait until bus is not busy*/
	while(SPI1->SR&Busy){}
	 /*Put the data on the DR*/
	   for (int i=0;i<size;i++)
	   	   {SPI1->DR=data[i];
	   	   /*wait until transmit complete*/
	   	   while(!(SPI1->SR)&(TXE)){}
	   	   }

    }
