#include "stm32f410rx.h"
#include "DAC.h"

#define AMP				((1U<<11)|(1U<<9)|(1U<<8)|(1U<<10))
#define TRI				(1U<<7)
#define software_Trig	((1U<<3)|(1U<<4)|(1U<<5))
#define Trig_EN			(1U<<2)
#define DAC_EN			(1U<<0)
#define GPIOA_EN		(1U<<0)
#define analog			((1U<<10)|(1U<<11))
#define DAC_Clock		(1U<<29)
#define buff_EN			(1U<<1)




	void DAC_init(void)
					{
			/***************GPIO CONFIG    PA5      ****************/

			/*allow clock access to GPIOA*/
			RCC->AHB1ENR|=GPIOA_EN;

			/*set PA5 to analog*/
			GPIOA->MODER|=analog;

			/*enable clock access to DAC */
			RCC->APB1ENR|=DAC_Clock;

			/*maximum amplitude value in the MAMPx[3:0] bits*/
			DAC1->CR|=AMP;
			/*select timer 5 as TRGO*/
			DAC1->CR|=(1U<<4);
			DAC1->CR|=(1U<<3);
			/*enable DMA request*/
			DAC1->CR|=(1U<<12);

			/*trigger enable*/
			DAC1->CR|=Trig_EN;


			/*enable buffer and channel CR1*/
			//DAC1->CR|=buff_EN;
			DAC1->CR|=DAC_EN;
					}






