/*
 * interrupt.h
 *
 *  Created on: Jan 20, 2022
 *      Author: ousjl
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "stm32f410rx.h"

void push_button_init(void);
#define LINE13 (1U<<13)

#endif /* INTERRUPT_H_ */
