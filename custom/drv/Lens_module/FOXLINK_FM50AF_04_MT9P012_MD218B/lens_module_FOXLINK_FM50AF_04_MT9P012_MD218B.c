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
#include "lens_module_FOXLINK_FM50AF_04_MT9P012_MD218B.h"
	 
#define FOXLINK_FM50AF_DBG

	 kal_uint16 FoxlinkFm50af04Mt9p012Md218bCurrPos;
	 kal_uint16 FoxlinkFm50af04Mt9p012Md218bHomePos;
	 kal_uint16 FoxlinkFm50af04Mt9p012Md218bMacroPos;
	 
	 extern kal_uint32 drv_get_current_time(void);
	 extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);
	 
	 AF_LENS_TIMING_STRUCT FoxlinkFm50af04Mt9p012Md218bCameraLensTiming={
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
	 
	 void FoxlinkFm50af04Mt9p012Md218bWriteLensReg(kal_uint16 MSB, kal_uint16 LSB)
	 {
	  LensWriteCmosSensor(MSB, LSB);
		 
	 }	 /* write_cmos_sensor() */
	 
	 kal_uint32 FoxlinkFm50af04Mt9p012Md218bReadLensReg(kal_uint16 MSB)
	 {
		 
		 kal_uint16 GetByte;
		 GetByte=LensReadCmosSensor(MSB);
		 return GetByte;
	 
	 }	 /* read_cmos_sensor() */

	 /*************************************************************************
* FUNCTION
*************************************************************************/
void FoxlinkFm50af04Mt9p012Md218bLensAfSetPara(kal_uint32 Thres)
{
	kal_uint16 RegValueH, RegValueL;
	RegValueH = 	(0x00|(Thres>>4));
	RegValueL =  ((Thres<<4) & 0xf0);
	FoxlinkFm50af04Mt9p012Md218bWriteLensReg(RegValueH,RegValueL);
}
	 
void FoxlinkFm50af04Mt9p012Md218bSetStep(kal_uint32 Duty)
{
    if(Duty<FoxlinkFm50af04Mt9p012Md218bMacroPos)
    {
		FoxlinkFm50af04Mt9p012Md218bLensAfSetPara(Duty);
    }
    else
    {
        FoxlinkFm50af04Mt9p012Md218bLensAfSetPara(FoxlinkFm50af04Mt9p012Md218bMacroPos);
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
kal_int8 FoxlinkFm50af04Mt9p012Md218bAociLensInit(void)
{
	kal_uint16 RegValueH, RegValueL,lens_reg;
	/* init af status and pos */
	FoxlinkFm50af04Mt9p012Md218bHomePos = pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_home_idx].pos;
	FoxlinkFm50af04Mt9p012Md218bMacroPos= pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_macro_idx].pos;	
	FoxlinkFm50af04Mt9p012Md218bCurrPos = FoxlinkFm50af04Mt9p012Md218bHomePos;

	SunnyS5m03gMt9p012Ad5820WriteLensReg(0,0); //PWDN = LOW and Home
	lens_reg = SunnyS5m03gMt9p012Ad5820ReadLensReg();
	if (lens_reg != 0)
		return -1;
	
	RegValueH = (0x00|(FoxlinkFm50af04Mt9p012Md218bCurrPos>>4));
	RegValueL =  ((FoxlinkFm50af04Mt9p012Md218bCurrPos<<4) & 0xf0);
	SunnyS5m03gMt9p012Ad5820WriteLensReg(RegValueH,RegValueL);

	/* ... */
	return 1;
}	/* lens_init() */

/*************************************************************************
* FUNCTION
*	FoxlinkFm50af04Mt9p012Md218bLensPowerOn
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
void FoxlinkFm50af04Mt9p012Md218bLensPowerOn(void)
{
    //lens_af_power_on(KAL_TRUE);
    LensAfPowerOn(IMAGE_SENSOR_MAIN,KAL_TRUE);
    CameraSccbOpen(CAMERA_SCCB_LENS, FOXLINK_FM50AF_04_MT9P012_MD218B_SCCB_SLAVE_ADDR, CAMERA_SCCB_16BIT, CAMERA_SCCB_16BIT, FOXLINK_FM50AF_04_MT9P012_MD218B_SCCB_FAST_MODE_SPEED);

    kal_sleep_task(1);

    FoxlinkFm50af04Mt9p012Md218bWriteLensReg(0,0); //PWDN = LOW and Home
}

/*************************************************************************
* FUNCTION
*	FoxlinkFm50af04Mt9p012Md218bLensPowerOff
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
void FoxlinkFm50af04Mt9p012Md218bLensPowerOff(void)
{

	kal_uint16 reg_value_H, reg_value_L;
	FoxlinkFm50af04Mt9p012Md218bCurrPos = FoxlinkFm50af04Mt9p012Md218bHomePos;
	FoxlinkFm50af04Mt9p012Md218bSetStep(FoxlinkFm50af04Mt9p012Md218bCurrPos);	
	
	reg_value_H = 	(0x80|(FoxlinkFm50af04Mt9p012Md218bCurrPos>>4));
	reg_value_L =  ((FoxlinkFm50af04Mt9p012Md218bCurrPos<<4) & 0xF0);
	FoxlinkFm50af04Mt9p012Md218bWriteLensReg(reg_value_H,reg_value_L);
	LensAfPowerOn(IMAGE_SENSOR_MAIN,KAL_FALSE);
	CameraSccbClose(CAMERA_SCCB_LENS);

}


/*************************************************************************
* FUNCTION
*	FoxlinkFm50af04Mt9p012Md218bLensStandBy
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
void FoxlinkFm50af04Mt9p012Md218bLensStandBy(void)
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
void FoxlinkFm50af04Mt9p012Md218bGetLensId(kal_uint32 *LensId)
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
kal_bool FoxlinkFm50af04Mt9p012Md218bLensAfHomeCheck(void)
{
    if(FoxlinkFm50af04Mt9p012Md218bCurrPos==FoxlinkFm50af04Mt9p012Md218bHomePos)
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
*	FoxlinkFm50af04Mt9p012Md218bGetLensAfCurrentPos
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
kal_uint32 FoxlinkFm50af04Mt9p012Md218bGetLensAfCurrentPos(void)
{
  return FoxlinkFm50af04Mt9p012Md218bCurrPos;
}

/*************************************************************************
* FUNCTION
*	FoxlinkFm50af04Mt9p012Md218bLensAfStepCw
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
void FoxlinkFm50af04Mt9p012Md218bLensAfStepCw(kal_uint32 Number)
{
    if((FoxlinkFm50af04Mt9p012Md218bCurrPos+Number)<FoxlinkFm50af04Mt9p012Md218bMacroPos)
    {
        FoxlinkFm50af04Mt9p012Md218bCurrPos+=Number;
    }
	else
    {
        FoxlinkFm50af04Mt9p012Md218bCurrPos = FoxlinkFm50af04Mt9p012Md218bMacroPos;
    }
    FoxlinkFm50af04Mt9p012Md218bSetStep(FoxlinkFm50af04Mt9p012Md218bCurrPos);
}	/* lens_step_motor_step_cw() */

/*************************************************************************
* FUNCTION
*	FoxlinkFm50af04Mt9p012Md218bLensAfStepCcw
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
void FoxlinkFm50af04Mt9p012Md218bLensAfStepCcw(kal_uint32 Number)
{
   if(FoxlinkFm50af04Mt9p012Md218bCurrPos>=Number)
{
      FoxlinkFm50af04Mt9p012Md218bCurrPos-=Number;
   }
	else
    {
	FoxlinkFm50af04Mt9p012Md218bCurrPos = FoxlinkFm50af04Mt9p012Md218bHomePos;
    }
   FoxlinkFm50af04Mt9p012Md218bSetStep(FoxlinkFm50af04Mt9p012Md218bCurrPos);
}	/* lens_step_motor_step_ccw() */

/*************************************************************************
* FUNCTION
*	FoxlinkFm50af04Mt9p012Md218bLensAfMoveTo
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
void FoxlinkFm50af04Mt9p012Md218bLensAfMoveTo( kal_int32 TargetPos )
{
	/*
	kal_uint16 AfSlowStep=64,Hyper2InfinityTimes,i=1;
	
    if (FoxlinkFm50af04Mt9p012Md218bCurrPos>TargetPos)
	{
        if ((TargetPos==256)|(TargetPos==112))
    	{
            Hyper2InfinityTimes=(FoxlinkFm50af04Mt9p012Md218bCurrPos-TargetPos)/AfSlowStep;
	
            for(i=1;i<=Hyper2InfinityTimes;i++)
         	{
                FoxlinkFm50af04Mt9p012Md218bCurrPos=FoxlinkFm50af04Mt9p012Md218bCurrPos-AfSlowStep;
                FoxlinkFm50af04Mt9p012Md218bSetStep(FoxlinkFm50af04Mt9p012Md218bCurrPos);
         		kal_sleep_task(8);
         	}
    	}
	}
	*/
	FoxlinkFm50af04Mt9p012Md218bCurrPos = TargetPos;			
	if( TargetPos > FoxlinkFm50af04Mt9p012Md218bMacroPos )
		FoxlinkFm50af04Mt9p012Md218bCurrPos = FoxlinkFm50af04Mt9p012Md218bMacroPos;
	FOXLINK_FM50AF_04_MT9P012_MD218B_lset_step(FoxlinkFm50af04Mt9p012Md218bCurrPos);  

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
LENS_AF_STATUS FoxlinkFm50af04Mt9p012Md218bGetAfLensStatus( void )
{
	return AF_STATUS_READY;
}


MM_ERROR_CODE_ENUM FoxlinkFm50af04Mt9p012Md218bLensOpen(void)
{	
    FoxlinkFm50af04Mt9p012Md218bLensPowerOn();     
    return MM_ERROR_NONE;		
}



MM_ERROR_CODE_ENUM FoxlinkFm50af04Mt9p012Md218bLensFeatureControl(kal_uint32 FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                                                                    kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{	
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

	
	switch (FeatureId)
	{
		case LENS_FEATURE_GET_LENS_ID:
			FoxlinkFm50af04Mt9p012Md218bGetLensId(&(((P_LENS_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue));
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_CURRENT_POS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue= FoxlinkFm50af04Mt9p012Md218bGetLensAfCurrentPos();
			*pRealFeatureParaOutLen=4;
		break;
		case LENS_FEATURE_GET_LENS_HOME_CHECK:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = FoxlinkFm50af04Mt9p012Md218bLensAfHomeCheck();
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_STATUS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = FoxlinkFm50af04Mt9p012Md218bGetAfLensStatus();
			*pRealFeatureParaOutLen=1;			
		break;				
		case LENS_FEATURE_GET_LENS_TIMING_INFO:
			kal_mem_cpy( (AF_LENS_TIMING_STRUCT *)pFeatureParaOut, &FoxlinkFm50af04Mt9p012Md218bCameraLensTiming, sizeof(AF_LENS_TIMING_STRUCT));
             FeatureParaOutLen = sizeof(AF_LENS_TIMING_STRUCT);
			*pRealFeatureParaOutLen=sizeof(AF_LENS_TIMING_STRUCT);			
		break;		
		case LENS_FEATURE_SET_LENS_INFO:					
			FoxlinkFm50af04Mt9p012Md218bAociLensInit();
		break;
		case LENS_FEATURE_SET_LENS_STEP_CW:
			FoxlinkFm50af04Mt9p012Md218bLensAfStepCw(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue );
		break;
		case LENS_FEATURE_SET_LENS_STEP_CCW:
			FoxlinkFm50af04Mt9p012Md218bLensAfStepCcw(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;
		case LENS_FEATURE_SET_LENS_MOVE_TO:
			FoxlinkFm50af04Mt9p012Md218bLensAfMoveTo(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;			
		default:
		break;	
	}
	
	return ErrorCode;		
}

MM_ERROR_CODE_ENUM FoxlinkFm50af04Mt9p012Md218bLensControl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn, void *pParaOut, kal_uint32 ParaOutLen,
                                      kal_uint32 *pRealParaOutLen)
{		
	switch (ScenarioId)
	{

		default:
		    break;
	}
	return MM_ERROR_NONE;	
}

MM_ERROR_CODE_ENUM FoxlinkFm50af04Mt9p012Md218bLensClose(void)
{		
	FoxlinkFm50af04Mt9p012Md218bLensPowerOff();

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


LENS_FUNCTION_STRUCT FoxlinkFm50af04Mt9p012Md218bLensFuncMap=
{
    FoxlinkFm50af04Mt9p012Md218bLensOpen,		
    FoxlinkFm50af04Mt9p012Md218bLensFeatureControl,	
    FoxlinkFm50af04Mt9p012Md218bLensControl,		
    FoxlinkFm50af04Mt9p012Md218bLensClose		
};

MM_ERROR_CODE_ENUM FoxlinkFm50af04Mt9p012Md218bLensFuncInit(P_LENS_FUNCTION_STRUCT *pfFunc)
{
    *pfFunc=&FoxlinkFm50af04Mt9p012Md218bLensFuncMap;

    return MM_ERROR_NONE;
}


