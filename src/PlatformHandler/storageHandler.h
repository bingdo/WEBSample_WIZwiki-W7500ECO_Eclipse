/*
 * storageHandler.h
 *
 *  Created on: 2014. 9. 16.
 *      Author: Raphael Kwon
 */

#ifndef STORAGEHANDLER_H_
#define STORAGEHANDLER_H_

#include <stdint.h>
#include "W7500x_i2c.h"

int read_storage(uint8_t isConfig, void *data, uint16_t size);
int write_storage(uint8_t isConfig, void *data, uint16_t size);

extern I2C_ConfigStruct conf;
extern void delay(__IO uint32_t milliseconds);

#endif /* STORAGEHANDLER_H_ */
