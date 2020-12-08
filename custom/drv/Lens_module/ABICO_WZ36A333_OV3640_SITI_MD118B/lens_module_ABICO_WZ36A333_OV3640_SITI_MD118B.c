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
 *
 * Filename:
 * ---------
 *   lens_module.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   A Lens module device driver control interface
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "lens_module_ABICO_WZ36A333_OV3640_SITI_MD118B.h"

// AF Actuator driver's I2C read/write ID

kal_uint16 AbicoWz36a333Ov3640SitiMd118bCurrPos;
kal_uint16 AbicoWz36a333Ov3640SitiMd118bHomePos;
kal_uint16 AbicoWz36a333Ov3640SitiMd118bMacroPos;


AF_LENS_TIMING_STRUCT AbicoWz36a333Ov3640SitiMd118bCameraLensTiming={
	{2}, {2},
	{
		{16, 1312}, {4, 656},
		{0x00, 0x00}, {0x00, 0x00}, 
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00}, 
		{0x00, 0x00}, {0x00, 0x00}, 
		{0x00, 0x00}, {0x00, 0x00}
	}
};

/*************************************************************************
* FUNCTION
*************************************************************************/
void AbicoWz36a333Ov3640SitiMd118bLensAFSetPara(const kal_uint8 iPos)
{
    kal_uint16 iValue;

    ASSERT(iPos < 256);
    
    iValue = iPos << 6;
    LensWriteCmosSensor(iValue>>8, iValue&0xff);
}   /*  Lens_AF_Set_Para    */

void AbicoWz36a333Ov3640SitiMd118bSetStep(kal_uint8 iPos)
{
    if (iPos <= AbicoWz36a333Ov3640SitiMd118bMacroPos) {
        AbicoWz36a333Ov3640SitiMd118bLensAFSetPara(iPos);
    }else{
        AbicoWz36a333Ov3640SitiMd118bLensAFSetPara(AbicoWz36a333Ov3640SitiMd118bMacroPos);
    }
}

/*************************************************************************
* FUNCTION
*	AF_Lens_Init
*
* DESCRIPTION
*	This function initialize the VCM comtrol IO
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
kal_int8 AbicoWz36a333Ov3640SitiMd118bAFLensInit(void)
{		
	/* init af status and pos */
	AbicoWz36a333Ov3640SitiMd118bHomePos = pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_home_idx].pos;
	AbicoWz36a333Ov3640SitiMd118bHomePos= pCamera3A->AF.table_info[0].table_step[pCamera3A->AF.table_info[0].table_range.af_macro_idx].pos;	
	AbicoWz36a333Ov3640SitiMd118bCurrPos = AbicoWz36a333Ov3640SitiMd118bHomePos;			
	/* Load module calibration data if existed */
	/* ... */
	return 1;
}	/* lens_init() */

/*************************************************************************
* FUNCTION
*	AF_Lens_PowerOn
*
* DESCRIPTION
*	This function is to turn on VCM AF lens power.
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
void AbicoWz36a333Ov3640SitiMd118bAFLensPowerOn(void)
{
    // power on AF lens module
	LensAfPowerOn(CAL_CAMERA_SOURCE_MAIN,KAL_TRUE);
	
	CameraSccbOpen(CAMERA_SCCB_LENS, SITI_11_MD118B_WRITE_ID, CAMERA_SCCB_8BIT, CAMERA_SCCB_8BIT, 320);

    #ifdef AF_LENS_TEST
    {
        {
            kal_uint16 iValue, iPos;

            for (iPos = 0; iPos < 256; iPos++) {
                iValue = iPos << 6;
                LensWriteCmosSensor(iValue);
                iValue = LensReadCmosSensor();
                if (iValue != (kal_uint16)(iPos << 6)) {
                    return;
                }
            }
        }
        AbicoWz36a333Ov3640SitiMd118bSetStep(0);
    }
    #endif

    AbicoWz36a333Ov3640SitiMd118bSetStep(AbicoWz36a333Ov3640SitiMd118bCurrPos);
}   /*  AF_Lens_PowerOn   */

/*************************************************************************
* FUNCTION
*	AF_Lens_PowerOff
*
* DESCRIPTION
*	This function is to turn off VCF AF lens power.
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
void AbicoWz36a333Ov3640SitiMd118bAFLensPowerOff(void)
{
    kal_uint16 iValue;
    AbicoWz36a333Ov3640SitiMd118bCurrPos = AbicoWz36a333Ov3640SitiMd118bHomePos;

    iValue = 0x8000 | (AbicoWz36a333Ov3640SitiMd118bCurrPos << 6);    // power down AF driver IC
    LensWriteCmosSensor(iValue>>8,iValue&0xff);
	LensAfPowerOn(CAL_CAMERA_SOURCE_MAIN,KAL_FALSE);
	CameraSccbClose(CAMERA_SCCB_LENS);
}   /*  AF_Lens_PowerOff  */

/*************************************************************************
* FUNCTION
*	AF_Lens_Standby
*
* DESCRIPTION
*	This function is to let VCM AF lens stand by.
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
void AbicoWz36a333Ov3640SitiMd118bAFLensStandby(void)
{
}   /*  AF_Lens_Standby */

/*************************************************************************
* FUNCTION
*	AF_Get_Lens_ID
*
* DESCRIPTION
*	This function return the VCM ID
*
* PARAMETERS
*	*lens_id : address pointer of VCM ID
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void AbicoWz36a333Ov3640SitiMd118bAFGetLensID(kal_uint32 *LensId)
{
}	/* AF_Get_Lens_ID() */

/*************************************************************************
* FUNCTION
*	AF_Lens_Home_Check
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
kal_uint8 AbicoWz36a333Ov3640SitiMd118bAFLensHomeCheck(void)
{
    return  AbicoWz36a333Ov3640SitiMd118bCurrPos == AbicoWz36a333Ov3640SitiMd118bHomePos;
}   /*  AF_Lens_Home_Check  */

/*************************************************************************
* FUNCTION
*	AF_Get_Lens_Current_Position
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
kal_uint32 AbicoWz36a333Ov3640SitiMd118bAFGetLensCurrentPosition(void)
{
    return AbicoWz36a333Ov3640SitiMd118bCurrPos;
}   /*  AF_Get_Lens_Current_Position    */

/*************************************************************************
* FUNCTION
*	AF_Lens_Step_CW
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
void AbicoWz36a333Ov3640SitiMd118bAFLensStepCW(kal_uint32 iNum)
{
    if ((AbicoWz36a333Ov3640SitiMd118bCurrPos + iNum) < AbicoWz36a333Ov3640SitiMd118bMacroPos) {
      AbicoWz36a333Ov3640SitiMd118bCurrPos += iNum;
    }else {
        AbicoWz36a333Ov3640SitiMd118bCurrPos = AbicoWz36a333Ov3640SitiMd118bMacroPos;
    }

    AbicoWz36a333Ov3640SitiMd118bSetStep(AbicoWz36a333Ov3640SitiMd118bCurrPos);
}   /*  AF_Lens_Step_CW()   */

/*************************************************************************
* FUNCTION
*	AF_Lens_Step_CCW
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
void AbicoWz36a333Ov3640SitiMd118bAFLensStepCCW(kal_uint32 iNum)
{
    if (AbicoWz36a333Ov3640SitiMd118bCurrPos >= iNum) {
        AbicoWz36a333Ov3640SitiMd118bCurrPos -= iNum;
	}else {
        AbicoWz36a333Ov3640SitiMd118bCurrPos = AbicoWz36a333Ov3640SitiMd118bHomePos;
    }

   AbicoWz36a333Ov3640SitiMd118bSetStep(AbicoWz36a333Ov3640SitiMd118bCurrPos);
}   /*  AF_Lens_Step_CCW    */

/*************************************************************************
* FUNCTION
*	AF_Lens_MoveTo
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
void AbicoWz36a333Ov3640SitiMd118bAFLensMoveTo(kal_int32 iTarget_Pos)
{
    AbicoWz36a333Ov3640SitiMd118bCurrPos = iTarget_Pos;

    if (iTarget_Pos >= AbicoWz36a333Ov3640SitiMd118bMacroPos) {
		AbicoWz36a333Ov3640SitiMd118bCurrPos = AbicoWz36a333Ov3640SitiMd118bMacroPos;
    }

    AbicoWz36a333Ov3640SitiMd118bSetStep(AbicoWz36a333Ov3640SitiMd118bCurrPos);
}   /*  AF_Lens_MoveTo  */

/*************************************************************************
* FUNCTION
*	AF_Get_Lens_Status
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
kal_uint8 AbicoWz36a333Ov3640SitiMd118bAFGetLensStatus(void)
{
    return AF_STATUS_READY;
}   /*  AF_Get_Lens_Status  */

/*************************************************************************
* FUNCTION
*	AbicoWz36a333Ov3640SitiMd118bGetAfLensStatus
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
LENS_AF_STATUS AbicoWz36a333Ov3640SitiMd118bGetAfLensStatus( void )
{
	return AF_STATUS_READY;
}


MM_ERROR_CODE_ENUM AbicoWz36a333Ov3640SitiMd118bLensOpen(void)
{	
    AbicoWz36a333Ov3640SitiMd118bAFLensPowerOn();     
    return MM_ERROR_NONE;		
}



MM_ERROR_CODE_ENUM AbicoWz36a333Ov3640SitiMd118bLensFeatureControl(kal_uint32 FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                                                                    kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{	
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

	
	switch (FeatureId)
	{
		case LENS_FEATURE_GET_LENS_ID:
			AbicoWz36a333Ov3640SitiMd118bAFGetLensID(&(((P_LENS_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue));
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_CURRENT_POS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue=AbicoWz36a333Ov3640SitiMd118bAFGetLensCurrentPosition();
			*pRealFeatureParaOutLen=4;
		break;
		case LENS_FEATURE_GET_LENS_HOME_CHECK:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = AbicoWz36a333Ov3640SitiMd118bAFLensHomeCheck();
			*pRealFeatureParaOutLen=1;			
		break;			
		case LENS_FEATURE_GET_LENS_STATUS:
			((P_LENS_COMM_DATA_STRUCT )pFeatureParaOut)->FeatureValue = AbicoWz36a333Ov3640SitiMd118bGetAfLensStatus();
			*pRealFeatureParaOutLen=1;			
		break;				
		case LENS_FEATURE_GET_LENS_TIMING_INFO:
			kal_mem_cpy( (AF_LENS_TIMING_STRUCT *)pFeatureParaOut, &AbicoWz36a333Ov3640SitiMd118bCameraLensTiming, sizeof(AF_LENS_TIMING_STRUCT));
                     FeatureParaOutLen = sizeof(AF_LENS_TIMING_STRUCT);
			*pRealFeatureParaOutLen=sizeof(AF_LENS_TIMING_STRUCT);			
		break;		
		case LENS_FEATURE_SET_LENS_INFO:					
			AbicoWz36a333Ov3640SitiMd118bAFLensInit();
		break;
		case LENS_FEATURE_SET_LENS_STEP_CW:
			AbicoWz36a333Ov3640SitiMd118bAFLensStepCW(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue );
		break;
		case LENS_FEATURE_SET_LENS_STEP_CCW:
			AbicoWz36a333Ov3640SitiMd118bAFLensStepCCW(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;
		case LENS_FEATURE_SET_LENS_MOVE_TO:
			AbicoWz36a333Ov3640SitiMd118bAFLensMoveTo(((P_LENS_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
		break;			
		default:
		break;	
	}
	
	return ErrorCode;		
}

MM_ERROR_CODE_ENUM AbicoWz36a333Ov3640SitiMd118bLensControl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn, void *pParaOut, kal_uint32 ParaOutLen,
                                      kal_uint32 *pRealParaOutLen)
{		
	switch (ScenarioId)
	{

		default:
		    break;
	}
	return MM_ERROR_NONE;	
}

MM_ERROR_CODE_ENUM AbicoWz36a333Ov3640SitiMd118bLensClose(void)
{		
	AbicoWz36a333Ov3640SitiMd118bAFLensPowerOff();

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


LENS_FUNCTION_STRUCT AbicoWz36a333Ov3640SitiMd118bLensFuncMap=
{
    AbicoWz36a333Ov3640SitiMd118bLensOpen,		
    AbicoWz36a333Ov3640SitiMd118bLensFeatureControl,	
    AbicoWz36a333Ov3640SitiMd118bLensControl,		
    AbicoWz36a333Ov3640SitiMd118bLensClose		
};

MM_ERROR_CODE_ENUM AbicoWz36a333Ov3640SitiMd118bLensFuncInit(P_LENS_FUNCTION_STRUCT *pfFunc)
{
    *pfFunc=&AbicoWz36a333Ov3640SitiMd118bLensFuncMap;

    return MM_ERROR_NONE;
}

