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
	uint8_t Receive_Data[EEPROM_BLOCK_SIZE];

	if(size > EEPROM_BLOCK_SIZE)
		size = EEPROM_BLOCK_SIZE;

	memset(&Receive_Data[0], 0x00, EEPROM_BLOCK_SIZE);
	address = 0x00;

    delay(10);
	ret = I2C_Read(isConfig, address, &Receive_Data[0], size);

	memcpy(data, &Receive_Data[0], size);

	delay(10);
	write_storage(isConfig, Receive_Data, size);

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
	uint8_t page, rest, i, address;
	uint8_t Transmit_Data[EEPROM_BLOCK_SIZE];

	memset(&Transmit_Data[0], 0x00, EEPROM_BLOCK_SIZE);
	memcpy(&Transmit_Data[0], data, size);

	if(size > EEPROM_BLOCK_SIZE)
		size = EEPROM_BLOCK_SIZE;

	page = size/EEPROM_PAGE_SIZE;
	rest = size%EEPROM_PAGE_SIZE;

	address = 0;

	if(size < EEPROM_PAGE_SIZE)
	{
		ret = I2C_Write(isConfig, address, &Transmit_Data[0], size);
	    delay(10);
	}
	else
	{
		for(i=0; i<page; i++)
		{
			address += i*EEPROM_PAGE_SIZE;
			ret = I2C_Write(isConfig, address, &Transmit_Data[address], EEPROM_PAGE_SIZE);
		    delay(10);
		}

		if(rest != 0)
		{
			i++;
			address += i*EEPROM_PAGE_SIZE;
			ret = I2C_Write(isConfig, address, &Transmit_Data[address], rest);
		    delay(10);
		}
	}
#endif

	return ret;
}
