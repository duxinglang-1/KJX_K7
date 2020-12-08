/******************** (C) COPYRIGHT 2016~2017 MEMSENSING **********************
* File Name          : st_bas_msp880.c
* Author             : ShaoChenglong
* Version            : V1.0
* Date               : 2016-11-1
* Description        : Msp880 data handle
*******************************************************************************/
#include "st_bas_msp880.h"
#include "msp880.h"
#include "math.h"
MSP880_OTP_Typedef MSP880_OTP_Structure;
MSP880_Press_Typedef MSP880_Press_Structure;
MSP880_Temperature_Typedef  MSP880_Temperature_Structure;

/*******************************************************************************
* Function Name  : ST_USER_GetPressParam
* Description    : MSA300 press data read
* Input          : MSP880_Press_Typedef
* Output         : None
* Return         : None
*******************************************************************************/
void ST_USER_GetPressParam(MSP880_Press_Typedef *Press)
{	
	msp_read_press(&Press->Data_Read);
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("press:%d", Press->Data_Read);
#endif
#endif
}

/*******************************************************************************
* Function Name  : ST_USER_GetAllParam
* Description    : MSA300 data read
* Input          : MSP880_Pre_Typedef
* Output         : None
* Return         : None
*******************************************************************************/
void ST_USER_GetTemperatureParam(MSP880_Temperature_Typedef *Temperature)
{	
	msp_read_temperature(&Temperature->Data_Read);
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("temp:%d", Temperature->Data_Read);
#endif
#endif
}

/*******************************************************************************
* Function Name  : MSP880_Para_Calculate
* Description    : MSP880 parameter calculate
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void MSP880_Para_Calculate(MSP880_Press_Typedef *Press , MSP880_Temperature_Typedef *Temperature)
{
	double deltaT, deltaT_square,Ptemp, Btemp ,Ttemp, Height_factor ;

	Height_factor = 1.0/5.255;
	//convert to ¡æ
	Ttemp = (double)Temperature->Data_Read/128;
	
	Temperature->Temperature[Temperature->Cnt] = MSP880_OTP_Structure.Temp_a * Ttemp * Ttemp + \
																							 MSP880_OTP_Structure.Temp_b * Ttemp + \
																							 MSP880_OTP_Structure.Temp_c;
	deltaT = Temperature->Temperature[Temperature->Cnt] - MSP880_OTP_Structure.Tbase;
	deltaT_square = deltaT * deltaT;
	
	Ptemp = (double)Press->Data_Read/8388608;
	Btemp = MSP880_OTP_Structure.s0 * (1 + MSP880_OTP_Structure.stc1 * deltaT + MSP880_OTP_Structure.stc2 * deltaT_square) * \
					(Ptemp - (MSP880_OTP_Structure.f0 + MSP880_OTP_Structure.ftc1 * deltaT + MSP880_OTP_Structure.ftc2 * deltaT_square));
	Press->Press[Press->Cnt] = Btemp + MSP880_OTP_Structure.ks * Btemp * Btemp;
	Press->Press[Press->Cnt] *= 100000;

	Press->Standard_Pressure = 101325;
	Press->Height[Press->Cnt] = 44330 * (1 - pow(Press->Press[Press->Cnt]/Press->Standard_Pressure,Height_factor ));	
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("Press->Cnt:%d, press:%.2f, Height:%.2f, Temperature->Cnt:%d, temp:%.2f", Press->Cnt, Press->Press[Press->Cnt], Press->Height[Press->Cnt], Temperature->Cnt, Temperature->Temperature[Temperature->Cnt]);
#endif
#endif
}

/*******************************************************************************
* Function Name  : MSP880_Configuration
* Description    : MSP880 parameter init and setting
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void MSP880_Configuration(void)
{
	uint8_t  temp_data[22];
	int32_t s0_hex, stc1_hex, stc2_hex, ftc1_hex, ftc2_hex , f0_hex, \
	ks_hex, Tbase_hex, Temp_a_hex, Temp_b_hex, Temp_c_hex ;

	msp_register_read_continuously(0X11, 2, temp_data);
	
#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("reg_11:%d,reg_12:%d", temp_data[0],temp_data[1]);
#endif
#endif

	if(msp_register_read_continuously(MS_REG_OTP_PARA, 22, temp_data) == 0)
	{
	#ifdef XB_TEST
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("read register fail!");
	#endif
	#endif
		return;
	}

#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", temp_data[0],temp_data[1],temp_data[2],temp_data[3],temp_data[4],temp_data[5],temp_data[6],temp_data[7],temp_data[8],temp_data[9],
					temp_data[10],temp_data[11],temp_data[12],temp_data[13],temp_data[14],temp_data[15]
					);
#endif
#endif

	s0_hex   = temp_data[0]<<8|temp_data[1];

	stc1_hex = temp_data[2]<<8|temp_data[3];
	if(stc1_hex >= 32768)
		stc1_hex -= 65536;

	stc2_hex = (temp_data[4]&0x3F)<<8|temp_data[5];
	if(stc2_hex >= 8192)
		stc2_hex -= 16384;

	ftc1_hex = temp_data[6]<<8|temp_data[7];
	if(ftc1_hex >= 32768)
		ftc1_hex -= 65536;

	ftc2_hex = (temp_data[8]&0x3F)<<8|temp_data[9];
	if(ftc2_hex >= 8192)
		ftc2_hex -= 16384;	

	f0_hex = temp_data[10]<<8|temp_data[11];
	if(f0_hex >= 32768)
		f0_hex -= 65536;

	ks_hex = temp_data[12]<<8|temp_data[13];
	if(ks_hex >= 32768)
		ks_hex -= 65536;

	Tbase_hex = (temp_data[14]&0x0F)<<8|temp_data[15];
	if(Tbase_hex >= 2048)
		Tbase_hex -= 4096;

	Temp_a_hex = (temp_data[16]%16)<<8|temp_data[17];
	if(Temp_a_hex >= 2048)
		Temp_a_hex -= 4096;

	Temp_b_hex = (temp_data[18]%16)<<8|temp_data[19];

	Temp_c_hex = (temp_data[20]%16)<<8|temp_data[21];
	if(Temp_c_hex >= 2048)
		Temp_c_hex -= 4096;

	MSP880_OTP_Structure.s0     = (double)s0_hex/8192;
	MSP880_OTP_Structure.stc1   = (double)stc1_hex/4194304;
	MSP880_OTP_Structure.stc2   = (double)stc2_hex/536870912;
	MSP880_OTP_Structure.ftc1   = (double)ftc1_hex/4194304;
	MSP880_OTP_Structure.ftc2   = (double)ftc2_hex/536870912;
	MSP880_OTP_Structure.f0		= (double)f0_hex/32768;
	MSP880_OTP_Structure.ks     = (double)ks_hex/65536;
	MSP880_OTP_Structure.Tbase  = (double)Tbase_hex/16;
	MSP880_OTP_Structure.Temp_a = (double)Temp_a_hex/204800;	
	MSP880_OTP_Structure.Temp_b = (double)Temp_b_hex/2048;		
	MSP880_OTP_Structure.Temp_c = (double)Temp_c_hex/16;

#ifdef XB_TEST
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("s0:%f,stc1:%f,stc2:%f,ftc1:%f,ftc2:%f,f0:%f,ks:%f,Tbase:%f,Temp_a:%f,Temp_b:%f,Temp_c:%f",
			MSP880_OTP_Structure.s0,
			MSP880_OTP_Structure.stc1,
			MSP880_OTP_Structure.stc2,
			MSP880_OTP_Structure.ftc1,
			MSP880_OTP_Structure.ftc2,
			MSP880_OTP_Structure.f0,
			MSP880_OTP_Structure.ks,
			MSP880_OTP_Structure.Tbase,
			MSP880_OTP_Structure.Temp_a,
			MSP880_OTP_Structure.Temp_b,
			MSP880_OTP_Structure.Temp_c);
#endif
#endif
}

/************************ (C) COPYRIGHT MEMSENSING *****END OF FILE****/
