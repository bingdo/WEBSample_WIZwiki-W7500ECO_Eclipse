/*
*
@file		util.h
@brief
*/


#ifndef __BOARDUTIL_H__ 
#define __BOARDUTIL_H__ 

#include <stdint.h>
#include "types.h"

//#define FACTORY_FW
//#define FACTORY_FW_ONCE
//#define FACTORY_FW_FLASH
//#define F_SPI_FLASH
#ifdef F_SPI_FLASH
	//#define F_SPI_FLASH_ONLY
#endif
#define _FS_DEBUG_

// ADC
typedef enum
{
  A0 = 0,
  A1 = 1,
  A2 = 2,
  A3 = 3
} ADC_Type;

//Data IO
typedef enum
{
  D0 = 0,
  D1 = 1,
  D2 = 2,
  D3 = 3,
  D4 = 4,
  D5 = 5,
  D6 = 6,
  D7 = 7,
  D8 = 8,
  D9 = 9,
  D10 = 10,
  D11 = 11,
  D12 = 12,
  D13 = 13,
  D14 = 14,
  D15 = 15
} IO_Type;

#define IOn							 16

// Data IO Direction
typedef enum
{
  NotUsed 	= 0,
  Input 	= 1,
  Output 	= 2
} IO_Direction_Type;

// Data IO Status
typedef enum
{
  Off 	= 0,
  On 	= 1
} IO_Status_Type;

#define D0_PIN							GPIO_Pin_5
#define D0_GPIO_PORT					GPIOA
#define D0_PAD							PAD_PA

#define D1_PIN							GPIO_Pin_6
#define D1_GPIO_PORT					GPIOA
#define D1_PAD							PAD_PA

#define D2_PIN							GPIO_Pin_7
#define D2_GPIO_PORT					GPIOA
#define D2_PAD							PAD_PA

#define D3_PIN							GPIO_Pin_8
#define D3_GPIO_PORT					GPIOA
#define D3_PAD							PAD_PA

#define D4_PIN							GPIO_Pin_9
#define D4_GPIO_PORT					GPIOA
#define D4_PAD							PAD_PA

#define D5_PIN							GPIO_Pin_10
#define D5_GPIO_PORT					GPIOA
#define D5_PAD							PAD_PA

#define D6_PIN							GPIO_Pin_8
#define D6_GPIO_PORT					GPIOC
#define D6_PAD							PAD_PC

#define D7_PIN							GPIO_Pin_9
#define D7_GPIO_PORT					GPIOC
#define D7_PAD							PAD_PC

#define D8_PIN							GPIO_Pin_0
#define D8_GPIO_PORT					GPIOC
#define D8_PAD							PAD_PC

#define D9_PIN							GPIO_Pin_1
#define D9_GPIO_PORT					GPIOC
#define D9_PAD							PAD_PC

#define D10_PIN							GPIO_Pin_2
#define D10_GPIO_PORT					GPIOC
#define D10_PAD							PAD_PC

#define D11_PIN							GPIO_Pin_3
#define D11_GPIO_PORT					GPIOC
#define D11_PAD							PAD_PC

#define D12_PIN							GPIO_Pin_12
#define D12_GPIO_PORT					GPIOC
#define D12_PAD							PAD_PC

#define D13_PIN							GPIO_Pin_13
#define D13_GPIO_PORT					GPIOC
#define D13_PAD							PAD_PC

#define D14_PIN							GPIO_Pin_14
#define D14_GPIO_PORT					GPIOC
#define D14_PAD							PAD_PC

#define D15_PIN							GPIO_Pin_15
#define D15_GPIO_PORT					GPIOC
#define D15_PAD							PAD_PC

#endif
