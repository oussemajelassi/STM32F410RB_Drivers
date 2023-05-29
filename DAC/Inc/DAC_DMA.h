/*
 * uart_DMA.h
 *
 *  Created on: Mar 15, 2022
 *      Author: ousjl
 */

#ifndef DAC_DMA_H_
#define DAC_DMA_H_

#include <stdint.h>
void DAC1_DMA1_init(uint32_t dest,uint32_t source, uint32_t len);

#endif /* DAC_DMA_H_ */
