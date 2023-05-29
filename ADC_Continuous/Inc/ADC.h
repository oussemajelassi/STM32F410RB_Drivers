/*
 * ADC.h
 *
 *  Created on: Mar 18, 2022
 *      Author: ousjl
 */
#include <stdint.h>
#ifndef ADC_H_
#define ADC_H_

void ADC_init(void);
void Start_Conversion(void);
uint32_t read_ADC(void);

#endif /* ADC_H_ */
