/*
 * I2C.h
 *
 *  Created on: Feb 9, 2022
 *      Author: ousjl
 */

#ifndef I2C_H_
#define I2C_H_

void I2C_init(void);
void I2C_Read(char slaveadr,char memadr,char* data);
void I2C_Burst_read(char slaveadr,char memadr,int n ,char* data);
#endif /* I2C_H_ */
