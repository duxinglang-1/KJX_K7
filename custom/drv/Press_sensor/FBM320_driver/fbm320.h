/*
 * Copyright (C) 2015 Formosa Measurement Technology Inc. Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

/* Revised history
 * 1.0: first release
 * 1.1: temperature sensor support as input device
 * 1.2: Supporting both versions of sensor as 1.0 and 1.2
 * 1.2.1: Supporting HW version b1, b2, b3, b4
 * 1.3: Modified work_structure function from "fbm320_get_pressure_data()" to "read_fbm320()"
 * 1.4: Support plain I2C communication
 *         Add fbm320_setup()
 */

#ifndef __FBM320_H__
#define __FBM320_H__

#define XB_TEST

#ifdef XB_TEST
#include "..\\..\\kjx\\inc\\kjx_prin.h"
#endif

#ifdef	__KERNEL__

#include <linux/types.h>
#include <linux/math64.h>
#define BMP280_64BITSUPPORT_PRESENT
/* singed integer type*/
typedef	int8_t s8;/**< used for signed 8bit */
typedef	int16_t s16;/**< used for signed 16bit */
typedef	int32_t s32;/**< used for signed 32bit */
typedef	int64_t s64;/**< used for signed 64bit */

typedef	u_int8_t u8;/**< used for unsigned 8bit */
typedef	u_int16_t u16;/**< used for unsigned 16bit */
typedef	u_int32_t u32;/**< used for unsigned 32bit */
typedef	u_int64_t u64;/**< used for unsigned 64bit */



#else /* ! __KERNEL__ */
/**********************************************************
* These definition uses for define the C
* standard version data types
***********************************************************/
#if defined(__STDC_VERSION__)

/************************************************
 * compiler is C11 C standard
************************************************/
#if (__STDC_VERSION__ == 201112L)

/************************************************/
#include <stdint.h>
/************************************************/

/*unsigned integer types*/
typedef	uint8_t u8;/**< used for unsigned 8bit */
typedef	uint16_t u16;/**< used for unsigned 16bit */
typedef	uint32_t u32;/**< used for unsigned 32bit */
typedef	uint64_t u64;/**< used for unsigned 64bit */

/*signed integer types*/
typedef	int8_t s8;/**< used for signed 8bit */
typedef	int16_t s16;/**< used for signed 16bit */
typedef	int32_t s32;/**< used for signed 32bit */
typedef	int64_t s64;/**< used for signed 64bit */
#define BMP280_64BITSUPPORT_PRESENT
/************************************************
 * compiler is C99 C standard
************************************************/

#elif (__STDC_VERSION__ == 199901L)

/* stdint.h is a C99 supported c library.
which is used to fixed the integer size*/
/************************************************/
#include <stdint.h>
/************************************************/

/*unsigned integer types*/
typedef	uint8_t u8;/**< used for unsigned 8bit */
typedef	uint16_t u16;/**< used for unsigned 16bit */
typedef	uint32_t u32;/**< used for unsigned 32bit */
typedef	uint64_t u64;/**< used for unsigned 64bit */

/*signed integer types*/
typedef int8_t s8;/**< used for signed 8bit */
typedef	int16_t s16;/**< used for signed 16bit */
typedef	int32_t s32;/**< used for signed 32bit */
typedef	int64_t s64;/**< used for signed 64bit */
#define BMP280_64BITSUPPORT_PRESENT
/************************************************
 * compiler is C89 or other C standard
************************************************/

#else /*  !defined(__STDC_VERSION__) */
/*!
* @brief By default it is defined as 32 bit machine configuration
*	define your data types based on your
*	machine/compiler/controller configuration
*/
#define  MACHINE_32_BIT

/*! @brief
 *	If your machine support 16 bit
 *	define the MACHINE_16_BIT
 */
#ifdef MACHINE_16_BIT
#include <limits.h>
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed long int s32;/**< used for signed 32bit */

#if defined(LONG_MAX) && LONG_MAX == 0x7fffffffffffffffL
typedef long int s64;/**< used for signed 64bit */
typedef unsigned long int u64;/**< used for unsigned 64bit */
#define BMP280_64BITSUPPORT_PRESENT
#elif defined(LLONG_MAX) && (LLONG_MAX == 0x7fffffffffffffffLL)
typedef long long int s64;/**< used for signed 64bit */
typedef unsigned long long int u64;/**< used for unsigned 64bit */
#define BMP280_64BITSUPPORT_PRESENT
#else
#warning Either the correct data type for signed 64 bit integer \
could not be found, or 64 bit integers are not supported in your environment.
#warning The API will only offer 32 bit pressure calculation.This will \
slightly impede accuracy(noise of ~1 pascal RMS will be added to output).
#warning If 64 bit integers are supported on your platform, \
please set s64 manually and "#define(BMP280_64BITSUPPORT_PRESENT)" manually.
#endif

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned long int u32;/**< used for unsigned 32bit */

/* If your machine support 32 bit
define the MACHINE_32_BIT*/
#elif defined MACHINE_32_BIT
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed int s32;/**< used for signed 32bit */
typedef	signed long long int s64;/**< used for signed 64bit */

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned int u32;/**< used for unsigned 32bit */
typedef	unsigned long long int u64;/**< used for unsigned 64bit */
/*!
* @brief If your machine support 64 bit
define the BMP280_64BITSUPPORT_PRESENT*/
#define BMP280_64BITSUPPORT_PRESENT

/* If your machine support 64 bit
define the MACHINE_64_BIT*/
#elif defined MACHINE_64_BIT
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed int s32;/**< used for signed 32bit */
typedef	signed long int s64;/**< used for signed 64bit */

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned int u32;/**< used for unsigned 32bit */
typedef	unsigned long int u64;/**< used for unsigned 64bit */
#define BMP280_64BITSUPPORT_PRESENT

#else
#warning The data types defined above which not supported \
define the data types manually
#endif
#endif

/*** This else will execute for the compilers
 *	which are not supported the C standards
 *	Like C89/C99/C11***/
#else
/*!
* @brief By default it is defined as 32 bit machine configuration
*	define your data types based on your
*	machine/compiler/controller configuration
*/
#define  MACHINE_32_BIT

/* If your machine support 16 bit
define the MACHINE_16_BIT*/
#ifdef MACHINE_16_BIT
#include <limits.h>
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed long int s32;/**< used for signed 32bit */

#if defined(LONG_MAX) && LONG_MAX == 0x7fffffffffffffffL
typedef long int s64;/**< used for signed 64bit */
typedef unsigned long int u64;/**< used for unsigned 64bit */
#define BMP280_64BITSUPPORT_PRESENT
#elif defined(LLONG_MAX) && (LLONG_MAX == 0x7fffffffffffffffLL)
typedef long long int s64;/**< used for signed 64bit */
typedef unsigned long long int u64;/**< used for unsigned 64bit */
#define BMP280_64BITSUPPORT_PRESENT
#else
#warning Either the correct data type for signed 64 bit integer \
could not be found, or 64 bit integers are not supported in your environment.
#warning The API will only offer 32 bit pressure calculation.This will \
slightly impede accuracy(noise of ~1 pascal RMS will be added to output).
#warning If 64 bit integers are supported on your platform, \
please set s64 manually and "#define(BMP280_64BITSUPPORT_PRESENT)" manually.
#endif

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned long int u32;/**< used for unsigned 32bit */

/*! @brief If your machine support 32 bit
define the MACHINE_32_BIT*/
#elif defined MACHINE_32_BIT
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed int s32;/**< used for signed 32bit */
typedef	signed long long int s64;/**< used for signed 64bit */

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned int u32;/**< used for unsigned 32bit */
typedef	unsigned long long int u64;/**< used for unsigned 64bit */
#define BMP280_64BITSUPPORT_PRESENT

/* If your machine support 64 bit
define the MACHINE_64_BIT*/
#elif defined MACHINE_64_BIT
/*signed integer types*/
typedef	signed char  s8;/**< used for signed 8bit */
typedef	signed short int s16;/**< used for signed 16bit */
typedef	signed int s32;/**< used for signed 32bit */
typedef	signed long int s64;/**< used for signed 64bit */

/*unsigned integer types*/
typedef	unsigned char u8;/**< used for unsigned 8bit */
typedef	unsigned short int u16;/**< used for unsigned 16bit */
typedef	unsigned int u32;/**< used for unsigned 32bit */
typedef	unsigned long int u64;/**< used for unsigned 64bit */
#define BMP280_64BITSUPPORT_PRESENT

#else
#warning The data types defined above which not supported \
define the data types manually
#endif/*MACHINE_16_BIT*/
#endif/*__STDC_VERSION__*/
#endif/*__KERNEL__*/

#define fbm320_DRV_NAME	"fbm320"
#define FBM320_NAME              "fbm320"
#define DRIVER_VERSION	"1.4"
#define FBM320_CHIP_ID  0x42
#define debug_fbm320  //Enable debug mode
/*Communication mode seeting*/
#define Communication_mode 1 // 0: SMBUS  1: Plain_I2C

/* Control registers address*/
#define NULL (0)
#define fbm320_TAKE_MEAS_REG	0xF4
#define fbm320_READ_MEAS_REG_U	0xF6
#define fbm320_READ_MEAS_REG_L	0xF7
#define fbm320_READ_MEAS_REG_XL	0xF8
#define FBM320_SOFTRESET_REG           0xE0
#define FBM320_CHIP_ID_REG	  0x6B
#define FBM320_VERSION_REG	  0xA5

/* CMD list */
#define fbm320_MEAS_TEMP		              0x2E /* 2.2ms wait for measurement */
#define fbm320_MEAS_PRESS_OVERSAMP_0	0x34 /* 2.2ms wait for measurement */
#define fbm320_MEAS_PRESS_OVERSAMP_1	0x74 /* 3.2ms wait for measurement */
#define fbm320_MEAS_PRESS_OVERSAMP_2	0xB4 /* 5.4ms wait for measurement */
#define fbm320_MEAS_PRESS_OVERSAMP_3	0xF4 /* 9.8ms wait for measurement */
#define FBM320_SOFTRESET_CMD                 0xB6

#define FBM320_PRESSURE_CONVERSION_TIME_OSR1024   2.5
#define FBM320_PRESSURE_CONVERSION_TIME_OSR2048   3.7
#define FBM320_PRESSURE_CONVERSION_TIME_OSR4096   6.0
#define FBM320_PRESSURE_CONVERSION_TIME_OSR8192   10.7
#define OVERSAMPLING_RATE_DEFAULT  osr_8192  /*Default value can be setted as 0..3*/

/* Calibration registers */
#define FBM320_CALIBRATION_DATA_START0	 0xAA /*Calibraton data address{0xF1, 0xD0, 0xBB:0xAA} */
#define FBM320_CALIBRATION_DATA_START1   0xD0
#define FBM320_CALIBRATION_DATA_START2   0xF1
#define FBM320_CALIBRATION_DATA_LENGTH	 20 /* bytes */


#define I2C_TRIES		5
#define AUTO_INCREMENT		0x80
#define DELAY_LOWBOUND		(50 * NSEC_PER_MSEC)
#define DELAY_DEFAULT		(200 * NSEC_PER_MSEC)

#define PRESSURE_MAX	125000
#define PRESSURE_MIN		30000
#define PRESSURE_FUZZ	5
#define PRESSURE_FLAT	5
#define TEMP_MAX		900
#define TEMP_MIN		-900

struct fbm320_calibration_data {
	u8 C11, C12;
	u16 R0, R1, R2, R3, R4, R5, R6, R7, R8, R9;
	u16 C0, C1, C2, C3, C5, C6, C8, C9, C10;
	u32 C4, C7;
	s32 DT2;
};

enum fbm320_osr {
	osr_1024 = 0x0,
	osr_2048 = 0x1,
	osr_4096 = 0x2,
	osr_8192 = 0x3
};

enum fbm320_hw_version {
	hw_ver_b1 = 0x0,
	hw_ver_b2 = 0x1,
	hw_ver_b3 = 0x3,
	hw_ver_b4 = 0x5,
	hw_ver_unknown = 0xFF
};

struct fbm320_data {
	enum fbm320_osr oversampling_rate;
	struct fbm320_calibration_data calibration;
	enum  fbm320_hw_version hw_ver;
	u8 chip_id;
	s8 (*bus_read)(u8 reg_addr, u8 cnt, u8 *reg_data);/**< bus read function pointer*/
	s8 (*bus_write)(u8 reg_addr, u8 cnt, u8 *reg_data);/**< bus write function pointer*/
	void (*delay_usec)(u32);/**< delay function pointer*/
};

int fbm320_get_temperature(struct fbm320_data *barom, int *temperature);
int fbm320_get_pressure_data(struct fbm320_data *barom, int *pressure);
int fbm320_init(struct fbm320_data *fbm320_barom);

#endif
