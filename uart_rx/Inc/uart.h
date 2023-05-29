/*
 * uart.h
 *
 *  Created on: Jan 24, 2022
 *      Author: ousjl
 */
#include "stm32f410rx.h"
#include <stdint.h>

#ifndef UART_H_
#define UART_H_

void UART_TX_init(void);
char readdata(void);
void UART_RX_TX_init(void);

#endif /* UART_H_ */
