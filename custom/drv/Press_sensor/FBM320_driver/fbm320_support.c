
/*---------------------------------------------------------------------------*/
/* Includes*/
/*---------------------------------------------------------------------------*/

#include "kal_release.h"
#include "dcl.h"
#include "us_timer.h"               /* For ust_get_current_time() API*/

#include "fbm320.h"


/* Private variables ---------------------------------------------------------*/
struct fbm320_data fbm320_barom;
/**
 * { I2C 7bit address setting for fbm320 }
 * 	If SDO pin is pulled low, I2C address is 6C.
 * 	If SDO pin is pulled high, I2C address is 6D.
 */
#define FBM320_I2C_SLAVE_ADDR 0x6C
#define	I2C_SLAVE_READ_ADDR		(FBM320_I2C_SLAVE_ADDR<<1 | 0x01)
#define I2C_SLAVE_WRITE_ADDR	(FBM320_I2C_SLAVE_ADDR<<1 | 0x0)


//#define BMP_SENSOR_SCK        	17	// gpio_baro_sensor_sck_pin
//#define BMP_SENSOR_SDA        	16	// gpio_baro_sensor_sda_pin
#define FBM320_SENSOR_SCK        	17	// gpio_baro_sensor_sck_pin
#define FBM320_SENSOR_SDA        	16	// gpio_baro_sensor_sda_pin                            	  	

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


#define SET_I2C_CLK_OUTPUT 		GPIO_InitIO(OUTPUT,FBM320_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_OUTPUT		GPIO_InitIO(OUTPUT,FBM320_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_INPUT		GPIO_InitIO(INPUT,FBM320_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_CLK_HIGH		GPIO_WriteIO(1,FBM320_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_CLK_LOW			GPIO_WriteIO(0,FBM320_SENSOR_SCK); {int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_HIGH		GPIO_WriteIO(1,FBM320_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define SET_I2C_DATA_LOW		GPIO_WriteIO(0,FBM320_SENSOR_SDA);{int j; for(j=0;j<i2c_delay;j++);}
#define GET_I2C_DATA_BIT		GPIO_ReadIO(FBM320_SENSOR_SDA)

/* Private function prototypes -----------------------------------------------*/
static kal_int8 FBM320_I2C_bus_read(u8 reg_addr, u8 cnt, u8 *reg_data);
static kal_int8 FBM320_I2C_bus_write(u8 reg_addr, u8 cnt, u8 *reg_data);
static void fbm320_sensor_write_1byte(kal_int8 add, kal_int8 data);


extern struct fbm320_data *barom;

void fbm320_i2c_udelay(kal_uint32 delay)
{
	kal_uint16 i;
	while (delay--) {
		for (i = 0; i < 66; i++) {}
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
static kal_int8 FBM320_I2C_bus_read(u8 reg_addr, u8 cnt, u8 *reg_data)
{
	kal_int32 i, j, k;

	for (k = 0; k < cnt; k++) {
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
	for (i = 7; i >= 0; i--) {
		if (I2C_SLAVE_WRITE_ADDR & (1 << i)) {
			SET_I2C_DATA_HIGH;
		} else {
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
	for (i = 7; i >= 0; i--) {
		if ((reg_addr) & (1 << i)) {
			SET_I2C_DATA_HIGH;
		} else {
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
	for (j = 0; j < delay_short; j++);
	SET_I2C_CLK_HIGH;
	for (j = 0; j < delay_short; j++);
	SET_I2C_DATA_HIGH;
	for (j = 0; j < delay_short; j++);

	//read start
	//SET_I2C_DATA_HIGH;
	//SET_I2C_CLK_HIGH;
	SET_I2C_DATA_LOW;
	for (j = 0; j < delay_short; j++);
	SET_I2C_CLK_LOW;

	//Third step -- Send read command
	for (i = 7; i >= 0; i--) {
		if ((I2C_SLAVE_READ_ADDR) & (1 << i)) {
			SET_I2C_DATA_HIGH;
		} else {
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

	for (k = 0; k < cnt; k++) {
		//----- Read data out now --------
		// Read  data
		SET_I2C_DATA_INPUT;

		for (i = 7; i >= 0; i--) {
			SET_I2C_CLK_HIGH;
			for (j = 0; j < delay_long; j++);
			if (GET_I2C_DATA_BIT) {
				*(reg_data + k) |= (1 << i);
			}
			SET_I2C_CLK_LOW;
			for (j = 0; j < delay_long; j++);
		}

		//Check if this is the last byte or not
		//if yes, send ACK, data=0
		//if no, send NACK, data=1
		if (k != cnt - 1) {
			//ACK
			SET_I2C_DATA_OUTPUT;
			SET_I2C_DATA_LOW;
			for (j = 0; j < delay_short; j++);
			SET_I2C_CLK_HIGH;
			for (j = 0; j < delay_long; j++);
			SET_I2C_CLK_LOW;
		} else {
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


static void fbm320_sensor_write_1byte(kal_int8 add, kal_int8 data)
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
	for (i = 7; i >= 0; i--) {
		if (I2C_SLAVE_WRITE_ADDR & (1 << i)) {
			SET_I2C_DATA_HIGH;
		} else {
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
	for (i = 7; i >= 0; i--) {
		if (add & (1 << i)) {
			SET_I2C_DATA_HIGH;
		} else {
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
	for (i = 7; i >= 0; i--) {
		if (data & (1 << i)) {
			SET_I2C_DATA_HIGH;
		} else {
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
static kal_int8 FBM320_I2C_bus_write(u8 reg_addr, u8 cnt, u8 *reg_data)
{
	int i = 0;
	for (i = 0; i < cnt; i++) {
		fbm320_sensor_write_1byte((reg_addr + i), *(reg_data + i));
	}

	return 0;
}

kal_int8 FBM320_Begin(void)
{
	kal_int32 com_rslt;

#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	GPIO_ModeSetup(FBM320_SENSOR_SCK, 0x00);
	GPIO_ModeSetup(FBM320_SENSOR_SDA, 0x00);

	GPIO_InitIO(1, FBM320_SENSOR_SCK);
	GPIO_InitIO(1, FBM320_SENSOR_SDA);

	GPIO_WriteIO(1, FBM320_SENSOR_SCK);
	GPIO_WriteIO(1, FBM320_SENSOR_SDA);

	fbm320_i2c_udelay(500);

	fbm320_barom.bus_write = FBM320_I2C_bus_write;
	fbm320_barom.bus_read = FBM320_I2C_bus_read;
	fbm320_barom.delay_usec = fbm320_i2c_udelay;

	com_rslt = fbm320_init(&fbm320_barom);

	kal_prompt_trace(MOD_WAP,  "FBM320_Begin; fbm320_ID:%x,com_rslt:%x", fbm320_barom.chip_id, com_rslt);

	if (com_rslt != 0) {
		return -1;
	}

	return com_rslt;
}


kal_int32 FBM320_ReadTemperature(void)
{
	kal_int32 actual_temp = 0;

	fbm320_get_temperature(barom, &actual_temp);

	return actual_temp;
}


kal_uint32 FBM320_ReadPressure(void)
{
	kal_int32 actual_press = 0;

	fbm320_get_pressure_data(barom, &actual_press);

	return actual_press;
}
