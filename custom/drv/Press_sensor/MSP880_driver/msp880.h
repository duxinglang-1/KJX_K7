/******************** (C) COPYRIGHT 2016~2017 MEMSENSING **********************
* File Name          : msp880.h
* Author             : ShaoChenglong
* Version            : V1.0
* Date               : 2016-11-1
* Description        : MSP880 application
*******************************************************************************/

#ifndef _MSP880_H_
#define _MSP880_H_

#define KJX_MTK_TARGET
//#define XB_TEST

#ifdef KJX_MTK_TARGET
#include "MMIDataType.h"
#include "stdlib.h"
#include "kal_release.h"
#include "dcl.h"
#include "stdbool.h"
#include "..\\..\\kjx\\inc\\kjx_prin.h"
#else
#include "st_bas_gpio.h"
#include "st_bas_data.h"
#endif

#define MS_I2C_Addr  			 0x6C    /*SDO external pull high or float , pull down 0x6C   */
#define MS_I2C_Addr_Write  0
#define MS_I2C_Addr_Read   1

#define MS_PRESS_READ               0xF3 //press osr 8192
#define MS_TEMPERATURE_READ         0xB3 //Temperature osr 1024

#define MS_REG_SOFT_RESET           0x50
#define MS_REG_PRESS_MSB  			0x55
#define MS_REG_TEMPERATURE_MSB      0x58
#define MS_REG_CONFIGURE            0x5B
#define MS_REG_OTP_PARA             0x14

#ifdef KJX_MTK_TARGET

typedef signed char	int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

#define BMP_SENSOR_SCK        	17	// gpio_acc_sensor_sck_pin
#define BMP_SENSOR_SDA        	16	// gpio_acc_sensor_sda_pin

#if (defined(MCU_245_76M)|| defined(MCU_312M)|| defined(MCU_260M))
   #define i2c_delay   	10 //40
#elif defined(MCU_364M)
   #define i2c_delay	10 //20
#elif defined(MCU_208M)
   #define i2c_delay   	0 //40
#elif defined(MCU_104M)
   #define i2c_delay   	0
#elif defined(MCU_52M)
   #define i2c_delay   	0
#endif

#if (defined(MCU_245_76M)|| defined(MCU_312M)|| defined(MCU_260M))
   #define delay_short 30//100
   #define delay_long  60//200
#elif defined(MCU_364M)
   #define delay_short 35
   #define delay_long  70
#elif defined(MCU_208M)
   #define delay_short 20//100
   #define delay_long  40//200
#elif defined(MCU_104M)
   #define delay_short 10
   #define delay_long  20
#elif defined(MCU_52M)
   #define delay_short 0		//No test
   #define delay_long  0		//No test
#endif

#define MS_SCL_OUT 			GPIO_InitIO(OUTPUT,BMP_SENSOR_SCK);{int j; for(j=0;j<i2c_delay;j++);}
#define MS_SCL_IN 			GPIO_InitIO(INPUT,BMP_SENSOR_SCK);{int j; for(j=0;j<i2c_delay;j++);}
#define MS_SDA_OUT			GPIO_InitIO(OUTPUT,BMP_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define MS_SDA_IN			GPIO_InitIO(INPUT,BMP_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define MS_I2C_CLK_HIGH		GPIO_WriteIO(1,BMP_SENSOR_SCK);{int j; for(j=0;j<i2c_delay;j++);}
#define MS_I2C_CLK_LOW		GPIO_WriteIO(0,BMP_SENSOR_SCK);{int j; for(j=0;j<i2c_delay;j++);}
#define MS_I2C_DATA_HIGH	GPIO_WriteIO(1,BMP_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define MS_I2C_DATA_LOW		GPIO_WriteIO(0,BMP_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define MS_I2C_GET_BIT		GPIO_ReadIO(BMP_SENSOR_SDA)

#else
#define MS_I2C_CLK_HIGH				GPIO_SetBits(GPIOA, GPIO_Pin_8)
#define MS_I2C_CLK_LOW				GPIO_ResetBits(GPIOA, GPIO_Pin_8)
#define MS_I2C_DATA_HIGH			GPIO_SetBits(GPIOC, GPIO_Pin_9)
#define MS_I2C_DATA_LOW				GPIO_ResetBits(GPIOC, GPIO_Pin_9)
#define MS_I2C_GET_BIT        GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9)
#define MS_SDA_OUT						GPIO_InitOutPP(GPIOC, GPIO_Pin_9);
#define MS_SDA_IN             GPIO_InitIN(GPIOC, GPIO_Pin_9);
#define MS_SCL_OUT	          GPIO_InitOutPP(GPIOA, GPIO_Pin_8);
#define MS_SCL_IN             GPIO_InitIN(GPIOA, GPIO_Pin_8);
#endif

void msp_read_press(uint32_t *press);
void msp_read_temperature(uint32_t *temperature);
int msp_register_read_continuously(uint8_t addr, uint8_t count, uint8_t *data);
int32_t i2c_read_block_data(uint8_t base_addr, uint8_t count, uint8_t *data);
int32_t i2c_read_byte_data(uint8_t addr, uint8_t *data);
bool msp_ReadBytes(uint8_t* Data, uint8_t RegAddr);
bool msp_WriteBytes(uint8_t RegAddr, uint8_t Data);
void ms_SendByte(uint8_t Data);
void SW_i2c_start(void);
void SW_i2c_stop(void);
void ms_Restart(void);
void SW_i2c_one_clk(void);
bool ms_ChkAck(void);
uint8_t ms_ReadByteNAck(void);
void msa_DelayMS(uint32_t delay);
void st_delay_us(uint32_t delay);



#endif /* _MSP880_H_ */

/************************ (C) COPYRIGHT MEMSENSING *****END OF FILE****/
