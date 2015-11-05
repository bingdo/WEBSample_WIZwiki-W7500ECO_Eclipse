/*
 * storageHandler.c
 *
 *  Created on: 2014. 9. 16.
 *      Author: Raphael Kwon
 */


#include <string.h>
#include "W7500x.h"
#include "storageHandler.h"
#include "flashHandler.h"

int read_storage(uint8_t isConfig, void *data, uint16_t size)
{
#if !defined(EEPROM_ENABLE)
	uint32_t address;

	if(isConfig == 1) {
#if !defined(MULTIFLASH_ENABLE)
		address = (FLASH_PAGE_SIZE*2) + CONFIG_PAGE_ADDR;
#else
		address = flash.flash_page_size + flash.config_page_addr;
#endif
	}
	else {
#if !defined(MULTIFLASH_ENABLE)
		address = 0x00000000 + CONFIG_PAGE_ADDR;
#else
		address = 0x00000000 + flash.config_page_addr;
#endif
	}

	return read_flash(address, data, size);
#else
	uint8_t address;
	int ret=0;
	uint8_t Receive_Data[256];

	if(isConfig == 1) {
		address = 0x00;
	}
	else {
		address = 0x90;
	}

    delay(10);
	ret = I2C_Read(address, &Receive_Data[0], size);

	memcpy(data, &Receive_Data[0], size);

    delay(10);
	if(isConfig == 1) {
		write_storage(1, Receive_Data, size);
	}
	else {
		write_storage(0, Receive_Data, size);
	}

	return ret;
#endif
}

int write_storage(uint8_t isConfig, void *data, uint16_t size)
{
#if !defined(EEPROM_ENABLE)
	uint32_t address;
	int ret;

    printf("[DB] isConfig:%d size:%d ", isConfig, size);

	if(isConfig == 1) {
#if !defined(MULTIFLASH_ENABLE)
		address = (FLASH_PAGE_SIZE*2) + CONFIG_PAGE_ADDR;
#else
		address = flash.flash_page_size + flash.config_page_addr;
#endif
	}
	else {
#if !defined(MULTIFLASH_ENABLE)
		address = 0x00000000 + CONFIG_PAGE_ADDR;
#else
		address = 0x00000000 + flash.config_page_addr;
#endif
	}

	erase_flash_page(address);
	erase_flash_page(address+FLASH_PAGE_SIZE);

	ret = write_flash(address, data, size);
#else
	int ret;
	uint8_t Transmit_Data[256];
	memcpy(&Transmit_Data[0], data, size);

	if(isConfig == 1) {
		ret = I2C_Write(0x00, &Transmit_Data[0], 16);
		delay(10);
		ret = I2C_Write(0x10, &Transmit_Data[16], 16);
		delay(10);
		ret = I2C_Write(0x20, &Transmit_Data[32], 16);
		delay(10);
		ret = I2C_Write(0x30, &Transmit_Data[48], 16);
		delay(10);
		ret = I2C_Write(0x40, &Transmit_Data[64], 16);
		delay(10);
		ret = I2C_Write(0x50, &Transmit_Data[80], 16);
		delay(10);
		ret = I2C_Write(0x60, &Transmit_Data[96], 16);
		delay(10);
		ret = I2C_Write(0x70, &Transmit_Data[112], 16);
		delay(10);
		ret = I2C_Write(0x80, &Transmit_Data[128], 5);
		delay(10);
	}
	else
	{
		ret = I2C_Write(0x90, &Transmit_Data[0], 16);
		delay(10);
		ret = I2C_Write(0xA0, &Transmit_Data[16], 16);
		delay(10);
		ret = I2C_Write(0xB0, &Transmit_Data[32], 16);
		delay(10);
		ret = I2C_Write(0xC0, &Transmit_Data[48], 16);
		delay(10);
		ret = I2C_Write(0xD0, &Transmit_Data[64], 5);
		delay(10);
	}
#endif

	return ret;
}
