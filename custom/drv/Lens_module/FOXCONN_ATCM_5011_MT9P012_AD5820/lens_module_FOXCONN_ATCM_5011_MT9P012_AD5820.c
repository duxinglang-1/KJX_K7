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
#include "lens_module_FOXCONN_ATCM_5011_MT9P012_AD5820.h"

#define FOXCON_ATCM_5011_DBG

kal_uint16 FoxconnAtcm5011Mt9p012Ad5820CurrPos;
kal_uint16 FoxconnAtcm5011Mt9p012Ad5820HomePos;
kal_uint16 FoxconnAtcm5011Mt9p012Ad5820MacroPos;

AF_LENS_TIMING_STRUCT FoxconnAtcm5011Mt9p012Ad5820CameraLensTiming={
	{2}, {2},
	{
		{16, 8}, {4, 8},
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00}
	}
};

void FoxconnAtcm5011Mt9p012Ad5820WriteLensReg(kal_uint16 MSB, kal_uint16 LSB)
{
 LensWriteCmosSensor(MSB, LSB);
}	/* write_cmos_sensor() */

/*************************************************************************
* FUNCTION
*************************************************************************/
void FoxconnAtcm5011Mt9p012Ad5820LensAfSetPara(kal_uint32 Thres)
{
	kal_uint16 RegValueH, RegValueL;
	RegValueH = 	(0x00|(Thres>>4));
	RegValueL =  ((Thres<<4) & 0xf0);
	FoxconnAtcm5011Mt9p012Ad5820WriteLensReg(RegValueH,RegValueL);
}


void FoxconnAtcm5011Mt9p012Ad5820SetStep(kal_uint32 Duty)
{
    if(Duty<FoxconnAtcm5011Mt9p012Ad5820MacroPos)
    {
        FoxconnAtcm5011Mt9p012Ad5820LensAfSetPara(Duty);
    }
    else
    {
        FoxconnAtcm5011Mt9p012Ad5820LensAfSetPara(FoxconnAtcm5011Mt9p012Ad5820MacroPos);
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
kal_int8 FoxconnAtcm5011Mt9p012Ad5820AociLensInit(void)
{
	/* init af status and pos */
	FoxconnAtcm5011Mt9p012Ad5820HomePos = pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_home_idx].pos;
	FoxconnAtcm5011Mt9p012Ad5820MacroPos= pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_macro_idx].pos;	
	FoxconnAtcm5011Mt9p012Ad5820CurrPos = FoxconnAtcm5011Mt9p012Ad5820HomePos;
	/* ... */
	return 1;
}	/* lens_init() */

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820LensPowerOn
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
void FoxconnAtcm5011Mt9p012Ad5820LensPowerOn(void)
{
	//lens_af_power_on(KAL_TRUE);
	kal_uint16 RegValueH, RegValueL;	
	
	LensAfPowerOn(IMAGE_SENSOR_MAIN,KAL_TRUE);
	CameraSccbOpen(CAMERA_SCCB_LENS, FOXCONN_ATCM_5011_MT9P012_AD5820_SCCB_SLAVE_ADDR, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 320);
	
	FoxconnAtcm5011Mt9p012Ad5820WriteLensReg(0,0); //PWDN = LOW and Home

	RegValueH = (0x00|(FoxconnAtcm5011Mt9p012Ad5820CurrPos>>4));
	RegValueL =  ((FoxconnAtcm5011Mt9p012Ad5820CurrPos<<4) & 0xf0);
	FoxconnAtcm5011Mt9p012Ad5820WriteLensReg(RegValueH,RegValueL);
	FoxconnAtcm5011Mt9p012Ad5820WriteLensReg(0,0); //PWDN = LOW and Home
	FoxconnAtcm5011Mt9p012Ad5820SetStep(FoxconnAtcm5011Mt9p012Ad5820CurrPos);
}

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820LensPowerOff
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
void FoxconnAtcm5011Mt9p012Ad5820LensPowerOff(void)
{
	kal_uint16 RegValueH, RegValueL;

	RegValueH = 	(0x80|(FoxconnAtcm5011Mt9p012Ad5820CurrPos>>4));
	RegValueL =  ((FoxconnAtcm5011Mt9p012Ad5820CurrPos<<4) & 0xf0);
	FoxconnAtcm5011Mt9p012Ad5820WriteLensReg(RegValueH,RegValueL);
	LensAfPowerOn(IMAGE_SENSOR_MAIN,KAL_FALSE);
	CameraSccbClose(CAMERA_SCCB_LENS);

}

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820LensStandBy
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
void FoxconnAtcm5011Mt9p012Ad5820LensStandBy(void)
{
}

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820GetLensId
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
void FoxconnAtcm5011Mt9p012Ad5820GetLensId(kal_uint32 *LensId)
{
	/* LENS_VCM_LEBRO_ID	*/
}	/* FoxconnAtcm5011Mt9p012Ad5820GetLensId() */

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820LensAfHomeCheck
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
kal_bool FoxconnAtcm5011Mt9p012Ad5820LensAfHomeCheck(void)
{
    if(FoxconnAtcm5011Mt9p012Ad5820CurrPos==FoxconnAtcm5011Mt9p012Ad5820HomePos)
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
*	FoxconnAtcm5011Mt9p012Ad5820GetLensAfCurrentPos
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
kal_uint32 FoxconnAtcm5011Mt9p012Ad5820GetLensAfCurrentPos(void)
{
  return FoxconnAtcm5011Mt9p012Ad5820CurrPos;
}

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820LensAfStepCw
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
void FoxconnAtcm5011Mt9p012Ad5820LensAfStepCw(kal_uint32 Number)
{
    if((FoxconnAtcm5011Mt9p012Ad5820CurrPos+Number)<FoxconnAtcm5011Mt9p012Ad5820MacroPos)
{
        FoxconnAtcm5011Mt9p012Ad5820CurrPos+=Number;
    }
	else
    {
        FoxconnAtcm5011Mt9p012Ad5820CurrPos = FoxconnAtcm5011Mt9p012Ad5820MacroPos;
    }
    FoxconnAtcm5011Mt9p012Ad5820SetStep(FoxconnAtcm5011Mt9p012Ad5820CurrPos);
}	/* lens_step_motor_step_cw() */

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820LensAfStepCcw
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
void FoxconnAtcm5011Mt9p012Ad5820LensAfStepCcw(kal_uint32 Number)
{
   if(FoxconnAtcm5011Mt9p012Ad5820CurrPos>=Number)
{
      FoxconnAtcm5011Mt9p012Ad5820CurrPos-=Number;
   }
	else
    {
	FoxconnAtcm5011Mt9p012Ad5820CurrPos = FoxconnAtcm5011Mt9p012Ad5820HomePos;
    }
   FoxconnAtcm5011Mt9p012Ad5820SetStep(FoxconnAtcm5011Mt9p012Ad5820CurrPos);
}	/* lens_step_motor_step_ccw() */

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820LensAfMoveTo
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
void FoxconnAtcm5011Mt9p012Ad5820LensAfMoveTo( kal_int32 TargetPos )
{	
    FoxconnAtcm5011Mt9p012Ad5820CurrPos = TargetPos;
    if( TargetPos > FoxconnAtcm5011Mt9p012Ad5820MacroPos )
    {
        FoxconnAtcm5011Mt9p012Ad5820CurrPos = FoxconnAtcm5011Mt9p012Ad5820MacroPos;
    }
    FoxconnAtcm5011Mt9p012Ad5820SetStep(FoxconnAtcm5011Mt9p012Ad5820CurrPos);
}

/*************************************************************************
* FUNCTION
*	FoxconnAtcm5011Mt9p012Ad5820GetAfLensStatus
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
LENS_AF_STATUS FoxconnAtcm5011Mt9p012Ad5820GetAfLensStatus( void )
{
	return AF_STATUS_READY;
}


MM_ERROR_CODE_ENUM FoxconnAtcm5011Mt9p012Ad5820LensOpen(void)
{	
    FoxconnAtcm5011Mt9p012Ad5820LensPowerOn();     
    return MM_ERROR_NONE;		
}



MM_ERROR_CODE_ENUM FoxconnAtcm5011Mt9p012Ad5820LensFeatureControl(kal_uint32 FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                                                                    kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{	
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

	
	switch (FeatureId)
	{
		case LENS_FEATURE_GET_LENS_ID:
			FoxconnAtcm5011Mt9p012Ad5820GetLensId(&(((P_LENS_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue));
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_CURRENT_POS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue=FoxconnAtcm5011Mt9p012Ad5820GetLensAfCurrentPos();
			*pRealFeatureParaOutLen=4;
		break;
		case LENS_FEATURE_GET_LENS_HOME_CHECK:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = FoxconnAtcm5011Mt9p012Ad5820LensAfHomeCheck();
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_STATUS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = FoxconnAtcm5011Mt9p012Ad5820GetAfLensStatus();
			*pRealFeatureParaOutLen=1;			
		break;				
		case LENS_FEATURE_GET_LENS_TIMING_INFO:
			kal_mem_cpy( (AF_LENS_TIMING_STRUCT *)pFeatureParaOut, &FoxconnAtcm5011Mt9p012Ad5820CameraLensTiming, sizeof(AF_LENS_TIMING_STRUCT));
                     FeatureParaOutLen = sizeof(AF_LENS_TIMING_STRUCT);
			*pRealFeatureParaOutLen=sizeof(AF_LENS_TIMING_STRUCT);			
		break;		
		case LENS_FEATURE_SET_LENS_INFO:					
			FoxconnAtcm5011Mt9p012Ad5820AociLensInit();
		break;
		case LENS_FEATURE_SET_LENS_STEP_CW:
			FoxconnAtcm5011Mt9p012Ad5820LensAfStepCw(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue );
		break;
		case LENS_FEATURE_SET_LENS_STEP_CCW:
			FoxconnAtcm5011Mt9p012Ad5820LensAfStepCcw(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;
		case LENS_FEATURE_SET_LENS_MOVE_TO:
			FoxconnAtcm5011Mt9p012Ad5820LensAfMoveTo(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;			
		default:
		break;	
	}
	
	return ErrorCode;		
}

MM_ERROR_CODE_ENUM FoxconnAtcm5011Mt9p012Ad5820LensControl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn, void *pParaOut, kal_uint32 ParaOutLen,
                                      kal_uint32 *pRealParaOutLen)
{		
	switch (ScenarioId)
	{

		default:
		    break;
	}
	return MM_ERROR_NONE;	
}

MM_ERROR_CODE_ENUM FoxconnAtcm5011Mt9p012Ad5820LensClose(void)
{		
	FoxconnAtcm5011Mt9p012Ad5820LensPowerOff();

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


LENS_FUNCTION_STRUCT FoxconnAtcm5011Mt9p012Ad5820LensFuncMap=
{
    FoxconnAtcm5011Mt9p012Ad5820LensOpen,		
    FoxconnAtcm5011Mt9p012Ad5820LensFeatureControl,	
    FoxconnAtcm5011Mt9p012Ad5820LensControl,		
    FoxconnAtcm5011Mt9p012Ad5820LensClose		
};

MM_ERROR_CODE_ENUM FoxconnAtcm5011Mt9p012Ad5820LensFuncInit(P_LENS_FUNCTION_STRUCT *pfFunc)
{
    *pfFunc=&FoxconnAtcm5011Mt9p012Ad5820LensFuncMap;

    return MM_ERROR_NONE;
}


