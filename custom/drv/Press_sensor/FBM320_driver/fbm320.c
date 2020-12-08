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

#include "fbm320.h"

static int fbm320_get_raw_temperature(struct fbm320_data *barom,
                                      u32 *raw_temperature);
static int fbm320_get_raw_pressure(struct fbm320_data *barom,
                                   u32 *raw_pressure);
static s32 fbm320_read_store_otp_data(struct fbm320_data *barom);
static int fbm320_version_identification(struct fbm320_data *barom);
static int fbm320_setup (struct fbm320_data *barom);

/**
 * { pointer of fbm320 data }
 */
struct fbm320_data *barom;


static int fbm320_get_raw_temperature(struct fbm320_data *barom,
                                      u32 *raw_temperature)
{
	int err;
	u8 buf[3] = 0;
	u8 bus_wr_data;

	bus_wr_data = fbm320_MEAS_TEMP;
	err = barom->bus_write(fbm320_TAKE_MEAS_REG, sizeof(u8),
	                       &bus_wr_data);
	barom->delay_usec(1000 * FBM320_PRESSURE_CONVERSION_TIME_OSR1024);
	err = barom->bus_read(fbm320_READ_MEAS_REG_U,
	                      3 * sizeof(u8), buf);

	//*raw_temperature = 0;
	//*raw_temperature += ((u32)buf[2]) << 16;
	//*raw_temperature += ((u32)buf[1]) << 8;
	//*raw_temperature += ((u32)buf[0]);
	*raw_temperature = (buf[0] * 256 * 256) + (buf[1] * 256) + buf[2];//20170925

#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("*raw_temperature:%d", *raw_temperature);
#endif
#endif

	return err;
}

static int fbm320_get_raw_pressure(struct fbm320_data *barom,
                                   u32 *raw_pressure)
{
	int err;
	u8 buf[3] = 0;
	u8 bus_wr_data;

	bus_wr_data = fbm320_MEAS_PRESS_OVERSAMP_0 |
	              (barom->oversampling_rate << 6);
	err = barom->bus_write(fbm320_TAKE_MEAS_REG, sizeof(u8), &bus_wr_data);

	/* wait for the end of conversion */
	switch (barom->oversampling_rate) {
	case osr_1024: barom->delay_usec(1000 * FBM320_PRESSURE_CONVERSION_TIME_OSR1024);
		break;
	case osr_2048: barom->delay_usec(1000 * FBM320_PRESSURE_CONVERSION_TIME_OSR2048);
		break;
	case osr_4096: barom->delay_usec(1000 * FBM320_PRESSURE_CONVERSION_TIME_OSR4096);
		break;
	case osr_8192: barom->delay_usec(1000 * FBM320_PRESSURE_CONVERSION_TIME_OSR8192);
		break;
	}

	err = barom->bus_read(fbm320_READ_MEAS_REG_U,
	                      3 * sizeof(u8), buf);

	//*raw_pressure = 0;
	//*raw_pressure += ((u32)buf[2]) << 16;
	//*raw_pressure += ((u32)buf[1]) << 8;
	//*raw_pressure += ((u32)buf[0]);
	*raw_pressure = (buf[0] * 256 * 256) + (buf[1] * 256) + buf[2];//20170925
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("*raw_pressure:%d", *raw_pressure);
#endif
#endif

	return err;
}

/* FBM320 temperature measurement
 * This function starts the temperature measurement and returns the value
 * in hundredth of a degree celsius.
 */
int fbm320_get_temperature(struct fbm320_data *barom, int *temperature)
{
	struct fbm320_calibration_data *cali = &barom->calibration;
	s32 RT, UT, DT, X01 = 0, X02, X03;
	u32 raw_temperature;
	int status;

	status = fbm320_get_raw_temperature(barom, &raw_temperature);
	if (status != 0)
		goto exit;

	UT = raw_temperature;
	DT = ((UT - 8388608) >> 4) + (cali->C0 << 4);
	switch (barom->hw_ver) {
	case hw_ver_b1:
		X01 = (cali->C1 + 4418) * DT >> 1;
		break;
	case hw_ver_b2:
	case hw_ver_b3:
	case hw_ver_b4:
		X01 = (cali->C1 + 4459) * DT >> 1;
		break;
	};
	X02 = ((((cali->C2 - 256) * DT) >> 14) * DT) >> 4;
	X03 = (((((cali->C3 * DT) >> 18) * DT) >> 18) * DT);
	cali->DT2 = (X01 + X02 + X03) >> 12;
	/* if NULL just update DT2. Used for pressure only measurements */
	RT =  ((2500 << 15) - X01 - X02 - X03) >> 15;

	if (temperature != NULL)
		*temperature = RT;

exit:

	
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("real_temperature:%d", *temperature);
#endif
#endif
	return status;
}

/*
 * This function starts the pressure measurement and returns the value
 * in hPa. Since the pressure depends on the ambient temperature,
 * a temperature measurement is executed according to the given temperature
 * measurememt period (default is 1 sec boundary). This period could vary
 * and needs to be adjusted accoring to the sensor environment, i.e. if big
 * temperature variations then the temperature needs to be read out often.
 */
int fbm320_get_pressure_data(struct fbm320_data *barom, int *pressure)
{
	struct fbm320_calibration_data *cali = &barom->calibration;
	s32 DT2, UP, X11 = 0, X12, X13 = 0, X21 = 0, X22 = 0, X23, X24, X25, X26 = 0, PP1, PP2, PP3, PP4, CF, X31, X32, RP;
	u32 raw_pressure;
	int  status;

	status = fbm320_get_temperature(barom, NULL);
	if (status != 0)
		goto exit;

	status = fbm320_get_raw_pressure(barom, &raw_pressure);
	if (status != 0)
		goto exit;

	/* calculation for real pressure value*/
	DT2 = cali->DT2;
	UP = raw_pressure;
	switch (barom->hw_ver) {
	case hw_ver_b1:
		X11 = (cali->C5 * DT2);
		break;
	case hw_ver_b2:
	case hw_ver_b3:
	case hw_ver_b4:
		X11 = ((cali->C5 - 4443) * DT2);
		break;
	};

	X12 = (((cali->C6 * DT2) >> 16) * DT2) >> 2;
	switch (barom->hw_ver) {
	case hw_ver_b1:
		X13 = ((X11 + X12) >> 10) + ((cali->C4 + 211288) << 4);
		X21 = ((cali->C8 + 7209) * DT2) >> 10;
		break;
	case hw_ver_b2:
	case hw_ver_b3:
	case hw_ver_b4:
		X13 = ((X11 + X12) >> 10) + ((cali->C4 + 120586) << 4);
		X21 = ((cali->C8 + 7180) * DT2) >> 10;
		break;
	};

	X22 = (((cali->C9 * DT2) >> 17) * DT2) >> 12;
	X23 = abs (X22 - X21);
	switch (barom->hw_ver) {
	case hw_ver_b1:
		X24 = (X23 >> 11) * (cali->C7 + 285594);
		X25 = ((X23 & 0x7FF) * (cali->C7 + 285594)) >> 11;
		if ((X22 - X21) < 0)
			X26 = ((0 - X24 - X25) >> 11) + cali->C7 + 285594;
		else
			X26 = ((X24 + X25) >> 11) + cali->C7 + 285594;
		break;
	case hw_ver_b2:
	case hw_ver_b3:
	case hw_ver_b4:
		X24 = (X23 >> 11) * (cali->C7 + 166426);
		X25 = ((X23 & 0x7FF) * (cali->C7 + 166426)) >> 11;
		if ((X22 - X21) < 0)
			X26 = ((0 - X24 - X25) >> 11) + cali->C7 + 166426;
		else
			X26 = ((X24 + X25) >> 11) + cali->C7 + 166426;
		break;
	};

	PP1 = ((UP - 8388608) - X13) >> 3;
	PP2 = (X26 >> 11) * PP1;
	PP3 = ((X26 & 0x7FF) * PP1) >> 11;
	PP4 = (PP2 + PP3) >> 10;
	CF = (2097152 + cali->C12 * DT2) >> 3;
	X31 = (((CF * cali->C10) >> 17) * PP4) >> 2;
	X32 = (((((CF * cali->C11) >> 15) * PP4) >> 18) * PP4);
	RP = ((X31 + X32) >> 15) + PP4 + 100000;
	*pressure = RP;

exit:

#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("real_pressure:%d", *pressure);
#endif
#endif
	
	return status;
}

/*Read calibration data saved in OTP memory */
static s32 fbm320_read_store_otp_data(struct fbm320_data *barom)
{
	u8 tmp[FBM320_CALIBRATION_DATA_LENGTH];
	s32 status;
	struct fbm320_calibration_data *cali = &(barom->calibration);

	status = barom->bus_read(FBM320_CALIBRATION_DATA_START0,
	                         (FBM320_CALIBRATION_DATA_LENGTH - 2) * sizeof(u8),
	                         (u8 *)tmp);
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("read start0 status:%d", status);
#endif
#endif
	
	if (status < 0)
		goto exit;
	status = barom->bus_read(FBM320_CALIBRATION_DATA_START1, sizeof(u8), (u8 *)tmp + 18 );
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("read start1 status:%d", status);
#endif
#endif
	
	if (status < 0)
		goto exit;
	status = barom->bus_read(FBM320_CALIBRATION_DATA_START2, sizeof(u8), (u8 *)tmp + 19);
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("read start2 status:%d", status);
#endif
#endif
	
	if (status < 0)
		goto exit;

	cali->R0 = (tmp[0] << 8 | tmp[1]); //read OTP data here
	cali->R1 = (tmp[2] << 8 | tmp[3]);
	cali->R2 = (tmp[4] << 8 | tmp[5]);
	cali->R3 = (tmp[6] << 8 | tmp[7]);
	cali->R4 = (tmp[8] << 8 | tmp[9]);
	cali->R5 = (tmp[10] << 8 | tmp[11]);
	cali->R6 = (tmp[12] << 8 | tmp[13]);
	cali->R7 = (tmp[14] << 8 | tmp[15]);
	cali->R8 = (tmp[16] << 8 | tmp[17]);
	cali->R9 = (tmp[18] << 8 | tmp[19]);

#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("R0:%d,R1:%d,R2:%d,R3:%d,R4:%d,R5:%d,R6:%d,R7:%d,R8:%d,R9:%d", 
			cali->R0,cali->R1,cali->R2,cali->R3,cali->R4,cali->R5,cali->R6,cali->R7,cali->R8,cali->R9);
#endif
#endif

	/* Coefficient reconstruction */
	cali->C0 = cali->R0 >> 4;
	cali->C1 = ((cali->R1 & 0xFF00) >> 5) | (cali->R2 & 7);
	cali->C2 = ((cali->R1 & 0xFF) << 1) | (cali->R4 & 1);
	cali->C3 = cali->R2 >> 3;
	cali->C5 = cali->R4 >> 1;
	cali->C6 = cali->R5 >> 3;
	cali->C8 = cali->R7 >> 3;
	cali->C9 = cali->R8 >> 2;
	cali->C10 = ((cali->R9 & 0xFF00) >> 6) | (cali->R8 & 3);
	cali->C11 = cali->R9 & 0xFF;

	switch (barom->hw_ver) {
	case hw_ver_b1:
		cali->C4 = ((u32)cali->R3 << 1) | (cali->R5 & 1);
		cali->C7 = ((u32)cali->R6 << 2) | ((cali->R0 >> 2) & 3);
		cali->C12 = ((cali->R5 & 6) << 2) | (cali->R7 & 7);
		break;
	case hw_ver_b2:
	case hw_ver_b3:
	case hw_ver_b4:
		cali->C4 = ((u32)cali->R3 << 2) | (cali->R0 & 3);
		cali->C7 = ((u32)cali->R6 << 3) | (cali->R5 & 7);
		cali->C12 = ((cali->R0 & 0x0C) << 1) | (cali->R7 & 7);
		break;
	};

#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("C0:%d,C1:%d,C2:%d,C3:%d,C4:%d,C5:%d,C6:%d,C7:%d,C8:%d,C9:%d,C10:%d,C11:%d,C12:%d", 
				cali->C0,cali->C1,cali->C2,cali->C3,cali->C4,cali->C5,cali->C6,cali->C7,cali->C8,cali->C9,cali->C10,cali->C11,cali->C12);
#endif
#endif

exit:
	
	return status;
}

static int fbm320_version_identification(struct fbm320_data *barom)
{
	int err;
	u8 buf[2] = {0};
	u8 version = 0;
	u8 bus_wr_data;

	bus_wr_data = FBM320_SOFTRESET_CMD;
	barom->bus_write(FBM320_SOFTRESET_REG, sizeof(u8), &bus_wr_data);
	barom->delay_usec(1000 * 15); /* The minimum start up time of fbm320 is
15ms */
	err = barom->bus_read(fbm320_TAKE_MEAS_REG, sizeof(u8), buf);
	err = barom->bus_read(FBM320_VERSION_REG, sizeof(u8), buf + 1);

	version = ((buf[0] & 0xC0) >> 6) | ((buf[1] & 0x70) >> 2);
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("version:%d", version);
#endif
#endif

	switch (version)	
	{
	case hw_ver_b1:
		barom->hw_ver = hw_ver_b1;
		//printk("%s: The version of sensor is B1.\n", FBM320_NAME);
		break;
	case hw_ver_b2:
		barom->hw_ver = hw_ver_b2;
		//printk("%s: The version of sensor is B2.\n", FBM320_NAME);
		break;
	case hw_ver_b3:
		barom->hw_ver = hw_ver_b3;
		//printk("%s: The version of sensor is B3.\n", FBM320_NAME);
		break;
	case hw_ver_b4:
		barom->hw_ver = hw_ver_b4;
		//printk("%s: The version of sensor is B4.\n", FBM320_NAME);
		break;
	default:
		barom->hw_ver = hw_ver_unknown;
		//printk("%s: The version of sensor is unknown.\n", FBM320_NAME);
		break;
	}
	return err;
}

static int fbm320_setup (struct fbm320_data *barom)
{
	int err;
	u32 raw_temperature, raw_pressure;
	s32 temperature, pressure;
	u8 chip_id_read;

	err = barom->bus_read(FBM320_CHIP_ID_REG, sizeof(u8), &chip_id_read);
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("chip_id_read:%d", chip_id_read);
#endif
#endif

	if (chip_id_read != FBM320_CHIP_ID) 
	{
	#ifdef XB_TEST
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("err_chip_id_chk");
	#endif
	#endif
		err = -1;
		goto err_chip_id_chk;
	}
	else
		barom->chip_id = chip_id_read;

	err = fbm320_version_identification(barom);
	if(err)
	{
	#ifdef XB_TEST
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("err_version_identification");
	#endif
	#endif
		err = -2;
		goto err_version_identification;
	}

	err = fbm320_read_store_otp_data(barom);
	if(err)
	{
	#ifdef XB_TEST
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("err_read_otp");
	#endif
	#endif
		err = -3;
		goto err_read_otp;
	}

err_chip_id_chk:
err_version_identification:
err_read_otp:

	return err;
}

int fbm320_init(struct fbm320_data *fbm320_barom)
{
	int err;

	barom = fbm320_barom;
	barom->oversampling_rate = OVERSAMPLING_RATE_DEFAULT; /*Setting default oversampling_rate value*/
	barom->delay_usec(1000*15); /* The minimum start up time of fbm320 is 15ms */
	err = fbm320_setup(barom);

	return err;
}
