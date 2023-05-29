 /*
 * SPI.h
 *
 *  Created on: Mar 20, 2022
 *      Author: ousjl
 */

#ifndef SPI_H_
#define SPI_H_

void SPI_init(void);

void SPI_transmit(uint8_t * data,uint32_t size);
#endif /* SPI_H_ */
