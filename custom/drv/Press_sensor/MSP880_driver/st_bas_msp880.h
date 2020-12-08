/******************** (C) COPYRIGHT 2016~2017 MEMSENSING **********************
* File Name          : st_bas_msp880.h
* Author             : ShaoChenglong
* Version            : V1.0
* Date               : 2016-11-1
* Description        : MSP880 data Handle
*******************************************************************************/

#ifndef _ST_BAS_MSP880_H_
#define _ST_BAS_MSP880_H_

#include <stdint.h>  

#define Press_Buff_Length 			 512
#define Temperature_Buff_Length  512

typedef struct{
	double s0;
	double stc1;
	double stc2;
	double ftc1;
	double ftc2;
	double f0;
	double ks;
	double Tbase;
	double Temp_a;
	double Temp_b;
	double Temp_c;
}MSP880_OTP_Typedef,*pMSP880_OTP_Typedef;

extern MSP880_OTP_Typedef MSP880_OTP_Structure;

typedef struct{
	uint32_t Data_Read;
	uint32_t Cnt;
	double Standard_Pressure;
	int Measured_Standard_Value[2];
	double Press[Press_Buff_Length];
	double Height[Press_Buff_Length];
}MSP880_Press_Typedef,*pMSP880_Press_Typedef;

extern MSP880_Press_Typedef MSP880_Press_Structure;

typedef struct{
	uint32_t Data_Read;
	uint32_t Cnt;
	double Temperature[Temperature_Buff_Length];
}MSP880_Temperature_Typedef,*pMSP880_Temperature_Typedef;

extern MSP880_Temperature_Typedef  MSP880_Temperature_Structure;

void ST_USER_GetPressParam(MSP880_Press_Typedef *Press);
void ST_USER_GetTemperatureParam(MSP880_Temperature_Typedef *Temperature);
void MSP880_Para_Calculate(MSP880_Press_Typedef *Press , MSP880_Temperature_Typedef *Temperature);
void MSP880_Configuration(void);


#endif /* _ST_BAS_MSP880_H_ */

/************************ (C) COPYRIGHT MEMSENSING *****END OF FILE****/
