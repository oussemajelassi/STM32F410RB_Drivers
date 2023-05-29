/*
 * uart_DMA.c
 *
 *  Created on: Mar 14, 2022
 *      Author: ousssama jlassi
 */

#include <stdint.h>
#include "stm32f410rx.h"
#include "uart_DMA.h"

#define DMA1EN             (1U<<21)
#define DMA1_S6_EN         (1U<<0)
#define M2P                (1U<<6)
#define CH4                (1U<<27)
#define DMDIS              (1U<<2)
#define Stream6_EN         (1U<<0)
#define Memory_Increment   (1U<<10)
#define Trans_complete     (1U<<4)

#define DMA_transmitter_EN (1U<<7)
#define USART2EN           (1U<<17)


void uart_DMA1_init(uint32_t dest,uint32_t source, uint32_t len){
    /*Enable clock access to DMA1 */
	RCC->AHB1ENR|=DMA1EN;
	/*Disable DMA1 Stream 6*/
	DMA1_Stream6->CR&=~DMA1_S6_EN;
	/*wait for it*/
	while(DMA1_Stream6->CR & DMA1_S6_EN){}
	/*Set transfert Direction*/
	DMA1_Stream6->CR|=M2P;
	/*Set the source buffer*/
	DMA1_Stream6->M0AR=source;
	/*Set the destination buffer*/
	DMA1_Stream6->PAR=dest;
	/*Set the total number of data to be transferred*/
	DMA1_Stream6->NDTR=len;
	/*Choose the channel*/
	DMA1_Stream6->CR|=CH4;
	/*Enable memory increment*/
	DMA1_Stream6->CR|=Memory_Increment;
	/*Configure FIFO (enable/disable)*/
	DMA1_Stream6->CR&=~DMDIS;
	/*Transfer complete interrupt enable*/
	DMA1_Stream6->CR|=Trans_complete;
	/*Activate the stream*/
	DMA1_Stream6->CR|=Stream6_EN;
	/*USART2 Clock access enable*/
	RCC->APB1ENR|=USART2EN;
	/*UART2 DMA transmitter enable*/
	USART2->CR3|=DMA_transmitter_EN;
	/*NVIC interrupt enable*/
    NVIC_EnableIRQ(17);}
