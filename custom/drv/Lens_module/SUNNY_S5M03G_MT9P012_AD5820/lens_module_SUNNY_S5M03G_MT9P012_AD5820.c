/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "stdio.h"
#include "string.h"
#include "kal_release.h"
#include "camera_sccb.h"
#include "lens_module.h"
#include "sensor_comm_def.h"
#include "isp_if.h"
#include "isp_comm_if.h"
#include "lens_module_SUNNY_S5M03G_MT9P012_AD5820.h"

#define SUNNY_S5M03G_DBG

#define SUNNY_S5M03G_DBG
kal_uint16 SunnyS5m03gMt9p012Ad5820CurrPos;
kal_uint16 SunnyS5m03gMt9p012Ad5820HomePos;
kal_uint16 SunnyS5m03gMt9p012Ad5820MacroPos;

extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);

AF_LENS_TIMING_STRUCT SunnyS5m03gMt9p012Ad5820CameraLensTiming={
	2, 2,
	{
		{16, 8}, {4, 8},
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00}
	}
};

void SunnyS5m03gMt9p012Ad5820WriteLensReg(kal_uint16 MSB, kal_uint16 LSB)
{
 LensWriteCmosSensor(MSB, LSB);
	
}	/* write_cmos_sensor() */

kal_uint32 SunnyS5m03gMt9p012Ad5820ReadLensReg(kal_uint16 MSB)
{
	
    kal_uint16 GetByte;
	GetByte=LensReadCmosSensor(MSB);
    return GetByte;

}	/* read_cmos_sensor() */

/*************************************************************************
* FUNCTION
*************************************************************************/
void SunnyS5m03gMt9p012Ad5820LensAfSetPara(kal_uint32 Thres)
{
	kal_uint16 RegValueH, RegValueL;
	RegValueH = 	(0x00|(Thres>>4));
	RegValueL =  ((Thres<<4) & 0xf0);
	SunnyS5m03gMt9p012Ad5820WriteLensReg(RegValueH,RegValueL);
}


void SunnyS5m03gMt9p012Ad5820SetStep(kal_uint32 Duty)
{
    if(Duty<SunnyS5m03gMt9p012Ad5820MacroPos)
    {
        SunnyS5m03gMt9p012Ad5820LensAfSetPara(Duty);
    }
    else
    {
        SunnyS5m03gMt9p012Ad5820LensAfSetPara(SunnyS5m03gMt9p012Ad5820MacroPos);
	}
}

/*************************************************************************
* FUNCTION
*	lens_init
*
* DESCRIPTION
*	This function initialize the vcm comtrol IO
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 SunnyS5m03gMt9p012Ad5820AociLensInit(void)
{
	kal_uint16 RegValueH, RegValueL;
	/* init af status and pos */
	SunnyS5m03gMt9p012Ad5820HomePos = pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_home_idx].pos;
	SunnyS5m03gMt9p012Ad5820MacroPos= pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_macro_idx].pos;	
	SunnyS5m03gMt9p012Ad5820CurrPos = SunnyS5m03gMt9p012Ad5820HomePos;

	RegValueH = (0x00|(SunnyS5m03gMt9p012Ad5820CurrPos>>4));
	RegValueL =  ((SunnyS5m03gMt9p012Ad5820CurrPos<<4) & 0xf0);
	SunnyS5m03gMt9p012Ad5820WriteLensReg(RegValueH,RegValueL);

	/* ... */
	return 1;
}	/* lens_init() */

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820LensPowerOn
*
* DESCRIPTION
*	This function is to turn on vcm af lens power.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SunnyS5m03gMt9p012Ad5820LensPowerOn(void)
{
    //lens_af_power_on(KAL_TRUE);
    LensAfPowerOn(IMAGE_SENSOR_MAIN,KAL_TRUE);
    CameraSccbOpen(CAMERA_SCCB_LENS, SUNNY_S5M03G_MT9P012_AD5820_SCCB_SLAVE_ADDR, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);

    kal_sleep_task(1);

    SunnyS5m03gMt9p012Ad5820WriteLensReg(0,0); //PWDN = LOW and Home
}

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820LensPowerOff
*
* DESCRIPTION
*	This function is to turn off vcm af lens power.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SunnyS5m03gMt9p012Ad5820LensPowerOff(void)
{
	kal_uint16 RegValueH, RegValueL;
	kal_uint16 AfPowerOffSlowBack=64;
	kal_int32 Time1,Time2;

	Time1=drv_get_current_time();
    do
    {
	SunnyS5m03gMt9p012Ad5820SetStep(SunnyS5m03gMt9p012Ad5820CurrPos);
	SunnyS5m03gMt9p012Ad5820CurrPos=SunnyS5m03gMt9p012Ad5820CurrPos-AfPowerOffSlowBack;
	kal_sleep_task(8);//33ms - 1 frame
	Time2=drv_get_duration_ms(Time1);
	if(Time2>400) //400ms time out
		break;
    }
    while (SunnyS5m03gMt9p012Ad5820CurrPos>=AfPowerOffSlowBack); 

	RegValueH = 	(0x80|(SunnyS5m03gMt9p012Ad5820CurrPos>>4));
	RegValueL =  ((SunnyS5m03gMt9p012Ad5820CurrPos<<4) & 0xf0);
	SunnyS5m03gMt9p012Ad5820WriteLensReg(RegValueH,RegValueL);
	LensAfPowerOn(IMAGE_SENSOR_MAIN,KAL_FALSE);
	CameraSccbClose(CAMERA_SCCB_LENS);
}

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820LensStandBy
*
* DESCRIPTION
*	This function is to let vcm af lens stand by.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SunnyS5m03gMt9p012Ad5820LensStandBy(void)
{
}

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820GetLensId
*
* DESCRIPTION
*	This function return the vcm id
*
* PARAMETERS
*	*lens_id : address pointer of vcm id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SunnyS5m03gMt9p012Ad5820GetLensId(kal_uint32 *LensId)
{
	/* LENS_VCM_LEBRO_ID	*/
}	/* SunnyS5m03gMt9p012Ad5820GetLensId() */

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820LensAfHomeCheck
*
* DESCRIPTION
*	This function is to check if lens stay at home position
*
* PARAMETERS
*	NONE
*
* RETURNS
*	KAL_TRUE/KAL_FALSE.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool SunnyS5m03gMt9p012Ad5820LensAfHomeCheck(void)
{
    if(SunnyS5m03gMt9p012Ad5820CurrPos==SunnyS5m03gMt9p012Ad5820HomePos)
    {
		return KAL_TRUE;
    }
	else
    {
		return KAL_FALSE;
    }
}

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820GetLensAfCurrentPos
*
* DESCRIPTION
*	This function is to get lens parameter
*
* PARAMETERS
*	NONE
*
* RETURNS
*	get current lens position
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 SunnyS5m03gMt9p012Ad5820GetLensAfCurrentPos(void)
{
  return SunnyS5m03gMt9p012Ad5820CurrPos;
}

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820LensAfStepCw
*
* DESCRIPTION
*	This function is to move lens cw number steps, go infinite
*
* PARAMETERS
*	set lens cw move steps
*
* RETURNS
*	NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SunnyS5m03gMt9p012Ad5820LensAfStepCw(kal_uint32 Number)
{
    if((SunnyS5m03gMt9p012Ad5820CurrPos+Number)<SunnyS5m03gMt9p012Ad5820MacroPos)
    {
        SunnyS5m03gMt9p012Ad5820CurrPos+=Number;
    }
	else
    {
        SunnyS5m03gMt9p012Ad5820CurrPos = SunnyS5m03gMt9p012Ad5820MacroPos;
    }
    SunnyS5m03gMt9p012Ad5820SetStep(SunnyS5m03gMt9p012Ad5820CurrPos);
}	/* lens_step_motor_step_cw() */

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820LensAfStepCcw
*
* DESCRIPTION
*	This function is to move lens ccw number steps, go macro
*
* PARAMETERS
*	set lens ccw move steps
*
* RETURNS
*	NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SunnyS5m03gMt9p012Ad5820LensAfStepCcw(kal_uint32 Number)
{
   if(SunnyS5m03gMt9p012Ad5820CurrPos>=Number)
{
      SunnyS5m03gMt9p012Ad5820CurrPos-=Number;
   }
	else
    {
	SunnyS5m03gMt9p012Ad5820CurrPos = SunnyS5m03gMt9p012Ad5820HomePos;
    }
   SunnyS5m03gMt9p012Ad5820SetStep(SunnyS5m03gMt9p012Ad5820CurrPos);
}	/* lens_step_motor_step_ccw() */

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820LensAfMoveTo
*
* DESCRIPTION
*	This function is to move lens to target pos
*
* PARAMETERS
*	set lens move to target pos
*
* RETURNS
*	NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SunnyS5m03gMt9p012Ad5820LensAfMoveTo( kal_int32 TargetPos )
{
    kal_uint16 AfSlowStep=64,Hyper2InfinityTimes,i=1;
	
    if (SunnyS5m03gMt9p012Ad5820CurrPos>TargetPos)
{
        if ((TargetPos==256)|(TargetPos==112))
    {
            Hyper2InfinityTimes=(SunnyS5m03gMt9p012Ad5820CurrPos-TargetPos)/AfSlowStep;
	
            for(i=1;i<=Hyper2InfinityTimes;i++)
         {
                SunnyS5m03gMt9p012Ad5820CurrPos=SunnyS5m03gMt9p012Ad5820CurrPos-AfSlowStep;
                SunnyS5m03gMt9p012Ad5820SetStep(SunnyS5m03gMt9p012Ad5820CurrPos);
         kal_sleep_task(8);
         }
    }
}
    
    SunnyS5m03gMt9p012Ad5820CurrPos = TargetPos;
    if( TargetPos > SunnyS5m03gMt9p012Ad5820MacroPos )
    {
        SunnyS5m03gMt9p012Ad5820CurrPos = SunnyS5m03gMt9p012Ad5820MacroPos;
    }
    SunnyS5m03gMt9p012Ad5820SetStep(SunnyS5m03gMt9p012Ad5820CurrPos);
}

/*************************************************************************
* FUNCTION
*	SunnyS5m03gMt9p012Ad5820GetAfLensStatus
*
* DESCRIPTION
*	This function is to get current lens status
*
* PARAMETERS
*	NONE
*
* RETURNS
*	lens status
*
* GLOBALS AFFECTED
*
*************************************************************************/
LENS_AF_STATUS SunnyS5m03gMt9p012Ad5820GetAfLensStatus( void )
{
	return AF_STATUS_READY;
}


MM_ERROR_CODE_ENUM SunnyS5m03gMt9p012Ad5820LensOpen(void)
{	
    SunnyS5m03gMt9p012Ad5820LensPowerOn();     
    return MM_ERROR_NONE;		
}



MM_ERROR_CODE_ENUM SunnyS5m03gMt9p012Ad5820LensFeatureControl(kal_uint32 FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                                                                    kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{	
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

	
	switch (FeatureId)
	{
		case LENS_FEATURE_GET_LENS_ID:
			SunnyS5m03gMt9p012Ad5820GetLensId(&(((P_LENS_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue));
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_CURRENT_POS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue=SunnyS5m03gMt9p012Ad5820GetLensAfCurrentPos();
			*pRealFeatureParaOutLen=4;
		break;
		case LENS_FEATURE_GET_LENS_HOME_CHECK:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = SunnyS5m03gMt9p012Ad5820LensAfHomeCheck();
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_STATUS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = SunnyS5m03gMt9p012Ad5820GetAfLensStatus();
			*pRealFeatureParaOutLen=1;			
		break;				
		case LENS_FEATURE_GET_LENS_TIMING_INFO:
			kal_mem_cpy( (AF_LENS_TIMING_STRUCT *)pFeatureParaOut, &SunnyS5m03gMt9p012Ad5820CameraLensTiming, sizeof(AF_LENS_TIMING_STRUCT));
                     FeatureParaOutLen = sizeof(AF_LENS_TIMING_STRUCT);
			*pRealFeatureParaOutLen=sizeof(AF_LENS_TIMING_STRUCT);			
		break;		
		case LENS_FEATURE_SET_LENS_INFO:					
			SunnyS5m03gMt9p012Ad5820AociLensInit();
		break;
		case LENS_FEATURE_SET_LENS_STEP_CW:
			SunnyS5m03gMt9p012Ad5820LensAfStepCw(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue );
		break;
		case LENS_FEATURE_SET_LENS_STEP_CCW:
			SunnyS5m03gMt9p012Ad5820LensAfStepCcw(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;
		case LENS_FEATURE_SET_LENS_MOVE_TO:
			SunnyS5m03gMt9p012Ad5820LensAfMoveTo(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;			
		default:
		break;	
	}
	
	return ErrorCode;		
}

MM_ERROR_CODE_ENUM SunnyS5m03gMt9p012Ad5820LensControl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn, void *pParaOut, kal_uint32 ParaOutLen,
                                      kal_uint32 *pRealParaOutLen)
{		
	switch (ScenarioId)
	{

		default:
		    break;
	}
	return MM_ERROR_NONE;	
}

MM_ERROR_CODE_ENUM SunnyS5m03gMt9p012Ad5820LensClose(void)
{		
	SunnyS5m03gMt9p012Ad5820LensPowerOff();

	return MM_ERROR_NONE;		
}


/*************************************************************************
* FUNCTION
*	LensFuncMap
*
* DESCRIPTION
*	This function is to get current lens status
*
* PARAMETERS
*	NONE
*
* RETURNS
*	lens status
*
* GLOBALS AFFECTED
*
*************************************************************************/


LENS_FUNCTION_STRUCT SunnyS5m03gMt9p012Ad5820LensFuncMap=
{
    SunnyS5m03gMt9p012Ad5820LensOpen,		
    SunnyS5m03gMt9p012Ad5820LensFeatureControl,	
    SunnyS5m03gMt9p012Ad5820LensControl,		
    SunnyS5m03gMt9p012Ad5820LensClose		
};

MM_ERROR_CODE_ENUM SunnyS5m03gMt9p012Ad5820LensFuncInit(P_LENS_FUNCTION_STRUCT *pfFunc)
{
    *pfFunc=&SunnyS5m03gMt9p012Ad5820LensFuncMap;

    return MM_ERROR_NONE;
}


