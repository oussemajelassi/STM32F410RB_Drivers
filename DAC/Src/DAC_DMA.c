/*
 * uart_DMA.c
 *
 *  Created on: Mar 14, 2022
 *      Author: ousssama jlassi
 */

#include <DAC_DMA.h>
#include <stdint.h>
#include "stm32f410rx.h"

#define DMA1EN             (1U<<21)
#define DMA1_S5_EN         (1U<<0)
#define M2P                (1U<<6)
#define CH7                 ((1U<<27)|(1U<<25)|(1U<<26))
#define DMDIS              (1U<<2)
#define Stream5_EN         (1U<<0)
#define Memory_Increment   (1U<<10)
#define Trans_complete     (1U<<4)
#define MSIZE			   (1<<13)
#define PSIZE			   (1<<11)
#define DMA_transmitter_EN (1U<<7)
#define USART2EN           (1U<<17)
#define DAC1_DMA		   (1U<<12)
#define CIRC			   (1U<<8)


void DAC1_DMA1_init(uint32_t dest,uint32_t source, uint32_t len){
    /*Enable clock access to DMA1 */
	RCC->AHB1ENR|=DMA1EN;
	/*Disable DMA1 Stream 5   channel 7    */
	DMA1_Stream5->CR&=~DMA1_S5_EN;
	/*wait for it*/
	while(DMA1_Stream5->CR & DMA1_S5_EN){}
	/*Set transfert Direction*/
	DMA1_Stream5->CR|=M2P;
	/*Set the source buffer*/
	DMA1_Stream5->M0AR=source;
	/*Set the destination buffer*/
	DMA1_Stream5->PAR=dest;
	/*Set the total number of data to be transferred*/
	DMA1_Stream5->NDTR=len;
	/*Choose the channel*/
	DMA1_Stream5->CR|=CH7;
	/*Enable memory increment*/
	DMA1_Stream5->CR|=Memory_Increment;
	/*memory size*/
	DMA1_Stream5->CR|=MSIZE;
	/*periph data size*/
	DMA1_Stream5->CR|=PSIZE;
	/*Set circular mode*/
	DMA1_Stream5->CR|=CIRC;
	/*Configure FIFO (enable/disable)*/
	DMA1_Stream5->CR|=DMDIS;
	DMA1_Stream5->CR|=(1U<<1);
	DMA1_Stream5->CR|=(1U<<0);
	/*Transfer complete interrupt enable*/
	DMA1_Stream5->CR|=Trans_complete;
	/*Activate the stream*/
	DMA1_Stream5->CR|=Stream5_EN;

	}
