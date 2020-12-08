 /*
****************************************************************************
* Copyright (C) 2015 - 2016 Bosch Sensortec GmbH
*
* bmp280_support.c
* Date: 2016/07/01
* Revision: 1.0.6
*
* Usage: Sensor Driver support file for BMP280 sensor
*
****************************************************************************
* License:
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*   Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
*
*   Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
*
*   Neither the name of the copyright holder nor the names of the
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER
* OR CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
*
* The information provided is believed to be accurate and reliable.
* The copyright holder assumes no responsibility
* for the consequences of use
* of such information nor for any infringement of patents or
* other rights of third parties which may result from its use.
* No license is granted by implication or otherwise under any patent or
* patent rights of the copyright holder.
**************************************************************************/
/*---------------------------------------------------------------------------*/
/* Includes*/
/*---------------------------------------------------------------------------*/

#include "kal_release.h"
#include "dcl.h"
#include "us_timer.h"               /* For ust_get_current_time() API*/

#include "bmp280.h"


/* Private variables ---------------------------------------------------------*/
struct bmp280_t bmp280;

#define	I2C_SLAVE_READ_ADDR		0xED
#define I2C_SLAVE_WRITE_ADDR	    0xEC


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


#define SET_I2C_CLK_OUTPUT 		GPIO_InitIO(OUTPUT,BMP_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_OUTPUT		GPIO_InitIO(OUTPUT,BMP_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_INPUT		GPIO_InitIO(INPUT,BMP_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_CLK_HIGH		GPIO_WriteIO(1,BMP_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_CLK_LOW			GPIO_WriteIO(0,BMP_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_HIGH		GPIO_WriteIO(1,BMP_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_LOW		GPIO_WriteIO(0,BMP_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define GET_I2C_DATA_BIT		GPIO_ReadIO(BMP_SENSOR_SDA)

/* Private function prototypes -----------------------------------------------*/
static kal_int8 BMP280_I2C_bus_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);
static kal_int8 BMP280_I2C_bus_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt);

void bmp280_i2c_udelay(kal_uint32 delay)
{
	kal_uint16 i;
	while(delay--)
	{
		for(i=0;i<66;i++){}
	}
}

/**
 * @brief The function is used as I2C bus read
 *
 * @param dev_addr The device address of the sensor
 * @param reg_addr Address of the first register, where data is going to be read
 * @param reg_data This is the data read from the sensor, which is held in an array
 * @param cnt The no of data to be read
 *
 * @return Status of the I2C read
 */
static kal_int8 BMP280_I2C_bus_read(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt)
{
	   kal_int32 i, j, k;
	
	   for (k = 0; k < cnt; k++)
	   {
		  *(reg_data + k) = 0;
	   }
	
	   //START
	   SET_I2C_DATA_OUTPUT;
	   SET_I2C_CLK_OUTPUT;
	   SET_I2C_DATA_HIGH;
	   SET_I2C_CLK_HIGH;
	   SET_I2C_DATA_LOW;
	   for (j = 0; j < delay_short; j++);
	   SET_I2C_CLK_LOW;
	
	   //Need to confirm this delay
	   for (j = 0; j < delay_long; j++);
	
	   //First step--Send write command
	   for (i = 7; i >= 0; i--)
	   {
		  if (I2C_SLAVE_WRITE_ADDR&(1 << i))
		  {
			 SET_I2C_DATA_HIGH;
		  }
		  else
		  {
			 SET_I2C_DATA_LOW;
		  }
		  for (j = 0; j < delay_short; j++);
		  SET_I2C_CLK_HIGH;
		  for (j = 0; j < delay_long; j++);
		  SET_I2C_CLK_LOW;
		  for (j = 0; j < delay_short; j++);
	   }
	
	   //Waiting for ACK from motion sensor
	   SET_I2C_DATA_LOW;
	   SET_I2C_DATA_INPUT;
	   for (j = 0; j < delay_short; j++);
	   SET_I2C_CLK_HIGH;
	   for (j = 0; j < delay_long; j++);
	   SET_I2C_CLK_LOW;
	   SET_I2C_DATA_OUTPUT;
	
	   //Second step -- Send register address
	   for (i = 7; i >= 0; i--)
	   {
		  if ((reg_addr) &(1 << i))
		  {
			 SET_I2C_DATA_HIGH;
		  }
		  else
		  {
			 SET_I2C_DATA_LOW;
		  }
		  SET_I2C_CLK_HIGH;
		  for (j = 0; j < delay_long; j++);
		  SET_I2C_CLK_LOW;
		  for (j = 0; j < delay_short; j++);
	   }
	
	   //Waiting for ACK from motion sensor
	   SET_I2C_DATA_LOW;
	   SET_I2C_DATA_INPUT;
	   for (j = 0; j < delay_short; j++);
	   SET_I2C_CLK_HIGH;
	   for (j = 0; j < delay_long; j++);
	   SET_I2C_CLK_LOW;
	   SET_I2C_DATA_OUTPUT;
	
	   //write stop
	   SET_I2C_DATA_LOW;
	   SET_I2C_CLK_LOW;
	   for(j = 0; j < delay_short; j++);
	   SET_I2C_CLK_HIGH;
	   for(j = 0; j < delay_short; j++);
	   SET_I2C_DATA_HIGH;
	   for(j = 0; j < delay_short; j++);
	
	   //read start
	   //SET_I2C_DATA_HIGH;
	   //SET_I2C_CLK_HIGH;
	   SET_I2C_DATA_LOW;
	   for(j = 0; j < delay_short; j++);
	   SET_I2C_CLK_LOW;
	
	   //Third step -- Send read command
	   for (i = 7; i >= 0; i--)
	   {
		  if ((I2C_SLAVE_READ_ADDR) &(1 << i))
		  {
			 SET_I2C_DATA_HIGH;
		  }
		  else
		  {
			 SET_I2C_DATA_LOW;
		  }
		  SET_I2C_CLK_HIGH;
		  for (j = 0; j < delay_long; j++);
		  SET_I2C_CLK_LOW;
		  for (j = 0; j < delay_short; j++);
	   }
	
	   //Waiting for ACK from motion sensor
	   SET_I2C_DATA_LOW;
	   SET_I2C_DATA_INPUT;
	   for (j = 0; j < delay_short; j++);
	   SET_I2C_CLK_HIGH;
	   for (j = 0; j < delay_long; j++);
	   SET_I2C_CLK_LOW;
	   SET_I2C_DATA_OUTPUT;
	
	   for (k = 0; k < cnt; k++)
	   {
		  //----- Read data out now --------
		  // Read  data
		  SET_I2C_DATA_INPUT;
	
		  for (i = 7; i >= 0; i--)
		  {
			 SET_I2C_CLK_HIGH;
			 for (j = 0; j < delay_long; j++);
			 if (GET_I2C_DATA_BIT)
			 {
				*(reg_data + k) |= (1 << i);
			 }
			 SET_I2C_CLK_LOW;
			 for (j = 0; j < delay_long; j++);
		  }
	
		//Check if this is the last byte or not
		//if yes, send ACK, data=0
		//if no, send NACK, data=1
		  if (k != cnt - 1)
		  {
			 //ACK
			 SET_I2C_DATA_OUTPUT;
			 SET_I2C_DATA_LOW;
			 for (j = 0; j < delay_short; j++);
			 SET_I2C_CLK_HIGH;
			 for (j = 0; j < delay_long; j++);
			 SET_I2C_CLK_LOW;
		  }
		  else
		  {
			 //NACK
			 SET_I2C_DATA_OUTPUT;
			 SET_I2C_DATA_HIGH;
			 for (j = 0; j < delay_short; j++);
			 SET_I2C_CLK_HIGH;
			 for (j = 0; j < delay_long; j++);
			 SET_I2C_CLK_LOW;
		  }
	   }
	
	
	   //STOP
	   SET_I2C_DATA_OUTPUT;
	   SET_I2C_CLK_LOW;
	   SET_I2C_DATA_LOW;
	   for (j = 0; j < delay_short; j++);
	   SET_I2C_CLK_HIGH;
	   for (j = 0; j < delay_short; j++);
	   SET_I2C_DATA_HIGH;
	
	   return 0;
}


void bmp_sensor_write_1byte(kal_int8 add, kal_int8 data)
{
   kal_int32 i, j;

   //Start
   SET_I2C_DATA_OUTPUT;
   SET_I2C_CLK_OUTPUT;
   SET_I2C_DATA_HIGH;
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_short; j++);
   SET_I2C_DATA_LOW;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_LOW;

   //First step--Send write command
   for (i = 7; i >= 0; i--)
   {
      if (I2C_SLAVE_WRITE_ADDR &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   //Second step -- Send register address
   for (i = 7; i >= 0; i--)
   {
      if (add &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   //Third step -- Send the data
   for (i = 7; i >= 0; i--)
   {
      if (data &(1 << i))
      {
         SET_I2C_DATA_HIGH;
      }
      else
      {
         SET_I2C_DATA_LOW;
      }
      SET_I2C_CLK_HIGH;
      for (j = 0; j < delay_long; j++);
      SET_I2C_CLK_LOW;
      for (j = 0; j < delay_short; j++);
   }

   //Waiting for ACK from motion sensor
   SET_I2C_DATA_LOW;
   SET_I2C_DATA_INPUT;
   for (j = 0; j < delay_short; j++);
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_long; j++);
   SET_I2C_CLK_LOW;
   SET_I2C_DATA_OUTPUT;

   //STOP
   //SET_I2C_DATA_OUTPUT;
   SET_I2C_CLK_HIGH;
   for (j = 0; j < delay_short; j++);
   SET_I2C_DATA_LOW;
   for (j = 0; j < delay_short; j++);
   SET_I2C_DATA_HIGH;
}

/**
 * @brief The function is used as I2C bus write
 *
 * @param dev_addr The device address of the sensor
 * @param reg_addr Address of the first register, where data is to be written
 * @param reg_data It is a value held in the array, which is written in the register
 * @param cnt The no of bytes of data to be written
 *
 * @return Status of the I2C write
 */
static kal_int8 BMP280_I2C_bus_write(u8 dev_addr, u8 reg_addr, u8 *reg_data, u8 cnt)
{
	   int i = 0;
	   for (i = 0; i < cnt; i++)
	   {
		  bmp_sensor_write_1byte((reg_addr + i), *(reg_data + i));
	   }
	
	   return 0;
}

kal_int8 BMP280_Begin(void)
{
  kal_int8 com_rslt;

   GPIO_ModeSetup(BMP_SENSOR_SCK, 0x00);
   GPIO_ModeSetup(BMP_SENSOR_SDA, 0x00);
   
   GPIO_InitIO(1,BMP_SENSOR_SCK);
   GPIO_InitIO(1,BMP_SENSOR_SDA);
   
   GPIO_WriteIO(1,BMP_SENSOR_SCK);
   GPIO_WriteIO(1,BMP_SENSOR_SDA);

    bmp280_i2c_udelay(500);
    
  bmp280.bus_write = BMP280_I2C_bus_write;
  bmp280.bus_read = BMP280_I2C_bus_read;
  bmp280.dev_addr = BMP280_I2C_ADDRESS;					
  bmp280.delay_msec = bmp280_i2c_udelay;

  com_rslt = bmp280_init(&bmp280);
  
  kal_prompt_trace(MOD_WAP,  "BMP280_Begin; bmp280 ID:%x,com_rslt:%x", bmp280.chip_id, com_rslt);
  
  if (com_rslt != 0)
  {
    return -1;
  }

  /*	For reading the pressure and temperature data it is required to
   *	set the work mode
   *	The measurement period in the Normal mode is depends on the setting of
   *	over sampling setting of pressure, temperature and standby time
   *
   *    OSS                        pressure OSS    temperature OSS
   *    ultra low power            x1            x1
   *    low power                  x2            x1
   *    standard resolution        x4            x1
   *    high resolution            x8            x2
   *    ultra high resolution     x16            x2
   */
  com_rslt += bmp280_set_work_mode(BMP280_ULTRA_HIGH_RESOLUTION_MODE);

  com_rslt += bmp280_set_filter(BMP280_FILTER_COEFF_16);

  // Set CTRL_MEAS REG [0xF4] 0000 0011
  com_rslt += bmp280_set_power_mode(BMP280_NORMAL_MODE);

  com_rslt += bmp280_set_standby_durn(BMP280_STANDBY_TIME_500_MS);


  return com_rslt;
}


kal_int32 BMP280_ReadTemperature(void)
{  
	kal_int32 v_data_uncomp_tem_s32 = BMP280_INIT_VALUE;
	kal_int32 v_actual_temp_s32 = BMP280_INIT_VALUE;

	bmp280_read_uncomp_temperature(&v_data_uncomp_tem_s32);

	v_actual_temp_s32 = bmp280_compensate_temperature_int32(v_data_uncomp_tem_s32);

	return v_actual_temp_s32;  
}  


kal_uint32 BMP280_ReadPressure(void)
{
	kal_int32 v_data_uncomp_pres_s32 = BMP280_INIT_VALUE;
	kal_uint32 v_actual_press_u32 = BMP280_INIT_VALUE;

	bmp280_read_uncomp_pressure(&v_data_uncomp_pres_s32);
	v_actual_press_u32 = bmp280_compensate_pressure_int32(v_data_uncomp_pres_s32);

    return v_actual_press_u32;
}
