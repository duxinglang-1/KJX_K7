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


kal_uint16 SunnyQ5m04bMt9p015Bh6412gulCurrPos;
kal_uint16 SunnyQ5m04bMt9p015Bh6412gulHomePos;
kal_uint16 SunnyQ5m04bMt9p015Bh6412gulMacroPos;

AF_LENS_TIMING_STRUCT SunnyQ5m04bMt9p015Bh6412gulCameraLensTiming={
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


void SunnyQ5m04bMt9p015Bh6412gulWriteLensReg(kal_uint8 MSB, kal_uint8 LSB)
{
	LensWriteCmosSensor(MSB,LSB<<8|0x00);
}	/* write_cmos_sensor() */

/*************************************************************************
* FUNCTION
*************************************************************************/
void SunnyQ5m04bMt9p015Bh6412gulLensAfSetPara(kal_uint32 thres)
{
		kal_uint16 reg_value_H, reg_value_L;
		reg_value_H = 	(0xC0|(thres>>8));
		reg_value_L =  (thres & 0xff);
		SunnyQ5m04bMt9p015Bh6412gulWriteLensReg(reg_value_H,reg_value_L);
}


void SunnyQ5m04bMt9p015Bh6412gulSetStep(kal_uint32 duty)
{
	if(duty<SunnyQ5m04bMt9p015Bh6412gulMacroPos){
			SunnyQ5m04bMt9p015Bh6412gulLensAfSetPara(duty);
	}else{
			SunnyQ5m04bMt9p015Bh6412gulLensAfSetPara(SunnyQ5m04bMt9p015Bh6412gulMacroPos);
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
kal_int8 SunnyQ5m04bMt9p015Bh6412gulLensInit(void)
{
	/* init af status and pos */
	SunnyQ5m04bMt9p015Bh6412gulHomePos = pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_home_idx].pos;
	SunnyQ5m04bMt9p015Bh6412gulMacroPos= pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_macro_idx].pos;	
	SunnyQ5m04bMt9p015Bh6412gulCurrPos = SunnyQ5m04bMt9p015Bh6412gulHomePos;

	/* Load module calibration data if existed */
	SunnyQ5m04bMt9p015Bh6412gulWriteLensReg(0xC0,0); //PWDN = LOW and Home
	SunnyQ5m04bMt9p015Bh6412gulSetStep(SunnyQ5m04bMt9p015Bh6412gulCurrPos);
	/* ... */
	return 1;
}	/* lens_init() */

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulLensPowerOn
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
void SunnyQ5m04bMt9p015Bh6412gulLensPowerOn(void)
{
	LensAfPowerOn(IMAGE_SENSOR_MAIN,KAL_TRUE);
	CameraSccbOpen(CAMERA_SCCB_LENS, BH6412GUL_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_16BIT, 400);

}

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulLensPowerOff
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
void SunnyQ5m04bMt9p015Bh6412gulLensPowerOff(void)
{
	kal_uint16 reg_value_H, reg_value_L;
	SunnyQ5m04bMt9p015Bh6412gulCurrPos = SunnyQ5m04bMt9p015Bh6412gulHomePos;
	SunnyQ5m04bMt9p015Bh6412gulSetStep(SunnyQ5m04bMt9p015Bh6412gulCurrPos);

	reg_value_H = 	(0x00|(SunnyQ5m04bMt9p015Bh6412gulCurrPos>>8));
	reg_value_L =  (SunnyQ5m04bMt9p015Bh6412gulCurrPos & 0xff);
	SunnyQ5m04bMt9p015Bh6412gulWriteLensReg(reg_value_H,reg_value_L);
	LensAfPowerOn(IMAGE_SENSOR_MAIN,KAL_FALSE);
	CameraSccbClose(CAMERA_SCCB_LENS);
}

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulLensStandBy
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
void SunnyQ5m04bMt9p015Bh6412gulLensStandBy(void)
{
}

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulGetLensId
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
void SunnyQ5m04bMt9p015Bh6412gulGetLensId(kal_uint32 *lens_id)
{
	/* LENS_VCM_LEBRO_ID	*/
}	/* SunnyQ5m04bMt9p015Bh6412gulGetLensId() */

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulLensAfHomeCheck
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
kal_uint8 SunnyQ5m04bMt9p015Bh6412gulLensAfHomeCheck(void)
{
	if(SunnyQ5m04bMt9p015Bh6412gulCurrPos==SunnyQ5m04bMt9p015Bh6412gulHomePos)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulGetLensAfCurrentPos
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
kal_uint32 SunnyQ5m04bMt9p015Bh6412gulGetLensAfCurrentPos(void)
{
  return SunnyQ5m04bMt9p015Bh6412gulCurrPos;
}

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulLensAfStepCw
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
void SunnyQ5m04bMt9p015Bh6412gulLensAfStepCw(kal_uint32 number)
{
   if((SunnyQ5m04bMt9p015Bh6412gulCurrPos+number)<SunnyQ5m04bMt9p015Bh6412gulMacroPos)
      SunnyQ5m04bMt9p015Bh6412gulCurrPos+=number;
	else
		SunnyQ5m04bMt9p015Bh6412gulCurrPos = SunnyQ5m04bMt9p015Bh6412gulMacroPos;
   SunnyQ5m04bMt9p015Bh6412gulSetStep(SunnyQ5m04bMt9p015Bh6412gulCurrPos);
}	/* lens_step_motor_step_cw() */

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulLensAfStepCcw
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
void SunnyQ5m04bMt9p015Bh6412gulLensAfStepCcw(kal_uint32 number)
{
   if(SunnyQ5m04bMt9p015Bh6412gulCurrPos>=number)
      SunnyQ5m04bMt9p015Bh6412gulCurrPos-=number;
	else
		SunnyQ5m04bMt9p015Bh6412gulCurrPos = SunnyQ5m04bMt9p015Bh6412gulHomePos;
   SunnyQ5m04bMt9p015Bh6412gulSetStep(SunnyQ5m04bMt9p015Bh6412gulCurrPos);
}	/* lens_step_motor_step_ccw() */

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulLensAfMoveTo
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
void SunnyQ5m04bMt9p015Bh6412gulLensAfMoveTo( kal_int32 target_pos )
{
	SunnyQ5m04bMt9p015Bh6412gulCurrPos = target_pos;
	if( target_pos > SunnyQ5m04bMt9p015Bh6412gulMacroPos )
		SunnyQ5m04bMt9p015Bh6412gulCurrPos = SunnyQ5m04bMt9p015Bh6412gulMacroPos;
	SunnyQ5m04bMt9p015Bh6412gulSetStep(SunnyQ5m04bMt9p015Bh6412gulCurrPos);
}

/*************************************************************************
* FUNCTION
*	SunnyQ5m04bMt9p015Bh6412gulGetAfLensStatus
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
kal_uint8 SunnyQ5m04bMt9p015Bh6412gulGetAfLensStatus( void )
{
	return AF_STATUS_READY;
}

MM_ERROR_CODE_ENUM SunnyQ5m04bMt9p015Bh6412gulLensOpen(void)
{	
    SunnyQ5m04bMt9p015Bh6412gulLensPowerOn();     
    return MM_ERROR_NONE;		
}



MM_ERROR_CODE_ENUM SunnyQ5m04bMt9p015Bh6412gulLensFeatureControl(kal_uint32 FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                                                                    kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{	
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

	
	switch (FeatureId)
	{
		case LENS_FEATURE_GET_LENS_ID:
			SunnyQ5m04bMt9p015Bh6412gulGetLensId(&(((P_LENS_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue));
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_CURRENT_POS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue=SunnyQ5m04bMt9p015Bh6412gulGetLensAfCurrentPos();
			*pRealFeatureParaOutLen=4;
		break;
		case LENS_FEATURE_GET_LENS_HOME_CHECK:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = SunnyQ5m04bMt9p015Bh6412gulLensAfHomeCheck();
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_STATUS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = SunnyQ5m04bMt9p015Bh6412gulGetAfLensStatus();
			*pRealFeatureParaOutLen=1;			
		break;				
		case LENS_FEATURE_GET_LENS_TIMING_INFO:
			kal_mem_cpy( (AF_LENS_TIMING_STRUCT *)pFeatureParaOut, &SunnyQ5m04bMt9p015Bh6412gulCameraLensTiming, sizeof(AF_LENS_TIMING_STRUCT));
                     FeatureParaOutLen = sizeof(AF_LENS_TIMING_STRUCT);
			*pRealFeatureParaOutLen=sizeof(AF_LENS_TIMING_STRUCT);			
		break;		
		case LENS_FEATURE_SET_LENS_INFO:					
			SunnyQ5m04bMt9p015Bh6412gulLensInit();
		break;
		case LENS_FEATURE_SET_LENS_STEP_CW:
			SunnyQ5m04bMt9p015Bh6412gulLensAfStepCw(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue );
		break;
		case LENS_FEATURE_SET_LENS_STEP_CCW:
			SunnyQ5m04bMt9p015Bh6412gulLensAfStepCcw(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;
		case LENS_FEATURE_SET_LENS_MOVE_TO:
			SunnyQ5m04bMt9p015Bh6412gulLensAfMoveTo(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;			
		default:
		break;	
	}
	
	return ErrorCode;		
}

MM_ERROR_CODE_ENUM SunnyQ5m04bMt9p015Bh6412gulLensControl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn, void *pParaOut, kal_uint32 ParaOutLen,
                                      kal_uint32 *pRealParaOutLen)
{		
	switch (ScenarioId)
	{

		default:
		    break;
	}
	return MM_ERROR_NONE;	
}

MM_ERROR_CODE_ENUM SunnyQ5m04bMt9p015Bh6412gulLensClose(void)
{		
	SunnyQ5m04bMt9p015Bh6412gulLensPowerOff();

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


LENS_FUNCTION_STRUCT SunnyQ5m04bMt9p015Bh6412gulLensFuncMap=
{
    SunnyQ5m04bMt9p015Bh6412gulLensOpen,		
    SunnyQ5m04bMt9p015Bh6412gulLensFeatureControl,	
    SunnyQ5m04bMt9p015Bh6412gulLensControl,		
    SunnyQ5m04bMt9p015Bh6412gulLensClose		
};

MM_ERROR_CODE_ENUM SunnyQ5m04bMt9p015Bh6412gulLensFuncInit(P_LENS_FUNCTION_STRUCT *pfFunc)
{
    *pfFunc=&SunnyQ5m04bMt9p015Bh6412gulLensFuncMap;

    return MM_ERROR_NONE;
}



