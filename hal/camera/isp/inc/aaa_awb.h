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
 *  aaa_awb.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for AWB driver.
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __AAA_AWB_H__
#define __AAA_AWB_H__

#include "drv_features.h"
#include "isp_hw_feature_def.h"
#include "cct_comm_def.h"

//#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6238_SERIES))
//#if (defined(RAW_MAIN_CAMERA))
//#include "isp_if.h"
#include "kal_release.h"
#include "aaa_process.h"
#include "aaa_nvram.h"  // SC NV
#include "sensor_comm_def.h" //SC NV

#define    MAX_START_NO    (20)
#define    MAX_SMOOTH_NO    (20)
#define    WB_UNIT_GAIN    (128)
#define    WB_MAX_GAIN    (511)

#define    AWB_PAXEL_SIZE    (8)
#define    FEW_WHITE_PAXEL_RATIO    (200)


/*************************************************************************************/
/*****************************   AWB_PARA_V2.h    **************************************/
typedef enum
{
    WB_BOX_FULL_A = 0x0,
    WB_BOX_FULL_T = 0x1,
    WB_BOX_FULL_C = 0x2,
    WB_BOX_FULL_D = 0x3,
    WB_BOX_FULL_H = 0x4,
    WB_BOX_SUB_A = 0x5,
    WB_BOX_SUB_C = 0x6,
    WB_BOX_SUB_LOW_CT_D = 0x7,
    WB_BOX_SUB_MID_CT_D = 0x8,
    WB_BOX_SUB_HIGH_CT_D = 0x9,
    WB_BOX_FULL_FLASH = 0xA,
    WB_BOX_SIZE = 0xB
}WB_BOX_DEF_ENUM;
//T_WB_BOX_DEF;

typedef enum
{
    USE_BOX_TL84 = 0x0,
    USE_BOX_SMALL_A = 0x1,
    USE_BOX_FULL_A = 0x2
}WB_ALIGHT_METHOD_ENUM;
//T_ALIGHT_METHOD;

/*typedef enum
{
    awbMixAT,
    awbMixAC,
    awbMixTC,
    awbMixATC,
    awbMixAD,
    awbMixTD,
    awbMixATD,
    awbMixCD,
    awbMixACD,
    awbMixTCD,
    awbMixATCD,
    AWB_MIXLIGHT_NUM
}T_AwbMixLightType;
*/

typedef enum
{
    AWB_MIX_AT,
    AWB_MIX_AC,
    AWB_MIX_TC,
    AWB_MIX_ATC,
    AWB_MIX_AD,
    AWB_MIX_TD,
    AWB_MIX_ATD,
    AWB_MIX_CD,
    AWB_MIX_ACD,
    AWB_MIX_TCD,
    AWB_MIX_ATCD,
    AWB_MIXLIGHT_NUM
}WB_MIXLIGHT_TYPE_ENUM;


typedef struct
{
    kal_uint8   AwbStartSmFrameNum; /*must be not larger than 20*/
    kal_bool    AwbMixedToDEn;
    kal_uint8   AwbMixedToDType; /*WB_BOX_FULL_D, WB_BOX_SUB_LOW_CT_D, WB_BOX_SUB_MID_CT_D, WB_BOX_SUB_HIGH_CT_D*/
    kal_uint8   AwbFastToIndoorMaxEvThr;
    kal_uint8   AwbSlowToIndoorMaxEvThr;
    kal_bool    AwbLimitMaxGainEn;
    kal_uint8   AwbAuxiliaryLockDayEvThr; //lightmode be day & ev larger than awbCloudyLockDayEvThr
    kal_uint8   AwbAuxiliaryLockDayFrameThr;//& continous more than awbCloudyLockDayFrameThr frame
    kal_uint8   AwbDayPreferenceEvThr;//ev threshold for apply preference gain in daylight
    kal_int8    AwbEvOffset;  //-25 to +25
    kal_uint16  AwbMixPreferWeight[AWB_MIXLIGHT_NUM];
    kal_uint32  AwbLightBoxLowEv;
    kal_uint32  AwbLightBoxHighEv;
    kal_uint32  AwbPureLightBoxProbThr;
    kal_uint32  AwbBoxSwitchLightEvDiff;
} AWB_OPERATION_PARA_STRUCT, *P_AWB_OPERATION_PARA_STRUCT;

#if 0 /* SC NV */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0   /* SC NV */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0 /* SC NV */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/**********************************************************************************************/


typedef enum
{
	WB_START_STATE,
	WB_KEEP_STATE,
	WB_CHANGE_STATE,
	WB_FINETUNE_STATE,
	WB_EXIT_STATE
}AWB_STATE_MACHINE_ENUM;
//T_AwbStateMachine;

typedef enum
{
	BOX_NORMAL = 0x0,
	BOX_ALL_ZERO = 0x1,
	BOX_FEW_WHITE_POINT = 0x2
}AWB_BOX_STATUS_ENUM;
//T_AwbBoxStatus;

/*
typedef enum {
    CAM_WB_CLOUD,
    CAM_WB_DAYLIGHT,
    CAM_WB_INCANDESCENT,
    CAM_WB_FLUORESCENT,
    CAM_WB_TUNGSTEN,
    CAM_WB_FLASH,
    CAM_WB_USER_MANUAL,
    CAM_WB_AUTO
}T_AwbManualMode;
*/

typedef enum
{
    WB_OP_AUTO,
    WB_OP_MANUAL
}AWB_OP_MODE;
//T_AwbOpMode;

typedef enum
{
    MWB_FIX_GAIN,
    MWB_FIX_WINDOW,
    MWB_FIX_METHOD_SIZE
}MWB_METHOD_ENUM;
//T_MwbMethod;

typedef enum
{
    AWB_FLASH_PROC,
    AWB_MANUAL_PROC,
    AWB_AUTO_PROC,
    AWB_NONE_PROC
}AWB_PROC_TYPE_ENUM;
//T_AwbProcType;

typedef enum
{
    WB_TUNGSTEN = 0x0,
    WB_INCANDESCENT = 0x1,
    WB_FLUORESCENT = 0x2,
    WB_DAYLIGHT = 0x7,
    WB_CLOUDY = 0x8,
    WB_STROBE = 0xA
}AWB_MANUAL_WINDOW_ENUM;
//T_AwbManualWindow;

typedef enum
{
    WB_LIGHTMODE_PURE_A = 0x0001,
    WB_LIGHTMODE_PURE_T = 0x0010,
    WB_LIGHTMODE_MIX_A_T = 0x0011,
    WB_LIGHTMODE_PURE_C = 0x0100,
    WB_LIGHTMODE_MIX_A_C = 0x0101,
    WB_LIGHTMODE_MIX_T_C = 0x0110,
    WB_LIGHTMODE_MIX_A_T_C = 0x0111,
    WB_LIGHTMODE_PURE_D = 0x1000,
    WB_LIGHTMODE_MIX_A_D = 0x1001,
    WB_LIGHTMODE_MIX_T_D = 0x1010,
    WB_LIGHTMODE_MIX_A_T_D = 0x1011,
    WB_LIGHTMODE_MIX_C_D = 0x1100,
    WB_LIGHTMODE_MIX_A_C_D = 0x1101,
    WB_LIGHTMODE_MIX_T_C_D = 0x1110,
    WB_LIGHTMODE_MIX_A_T_C_D = 0x1111
}AWB_LIGHT_MODE_ENUM;
//T_AwbLightMode;


typedef enum
{
    WB_BOX_A = 0x0,
    WB_BOX_CW = 0x1,
    WB_BOX_D = 0x3
}AWB_BOX_NO_NUM;
//T_AwbBoxNo;


typedef struct
{
    kal_uint32 TarRGain;
    kal_uint32 TarGGain;
    kal_uint32 TarBGain;
    kal_uint32 MaxAbsDeltaGain;
    kal_int32 DeltaRGain;
    kal_int32 DeltaGGain;
    kal_int32 DeltaBGain;
    kal_int32 AdjustRGain;
    kal_int32 AdjustGGain;
    kal_int32 AdjustBGain;
}AWB_ADJUSTMENT_GAIN_STRUCT;


typedef struct
{
    kal_uint32 TarRGain;
    kal_uint32 TarGGain;
    kal_uint32 TarBGain;
    kal_uint32 MaxAbsDeltaGain;
    kal_int32 DeltaRGain;
    kal_int32 DeltaGGain;
    kal_int32 DeltaBGain;
}AWB_PROCESS_GAIN_STRUCT;


typedef struct
{
	kal_uint16 GainR;//R channel gain
	kal_uint16 GainG;//Gr channel gain
	kal_uint16 GainB;//B channel gain
	kal_uint16 GainH;//Gb channel gain
}AWB_HW_GAIN_STRUCT;
//awbHwGainStruct;


typedef struct
{
    kal_uint8 M11;
    kal_uint8 M12;
    kal_uint8 M13;
    kal_uint8 M21;
    kal_uint8 M22;
    kal_uint8 M23;
    kal_uint8 M31;
    kal_uint8 M32;
    kal_uint8 M33;
}AWB_CCM_STRUCT;
//awb_ccm_struct;

extern kal_bool AwbEnableFlag,AwbEnableFlagBackup;
extern kal_bool AwbFlashFlag;
extern kal_uint8 AwbOpMode;//0:auto, 1:manual
extern kal_uint8 AwbManualType;
extern kal_uint8 AwbMwbMethod;

extern kal_uint16 AwbMaxRGain,AwbMaxGGain,AwbMaxBGain;
extern kal_uint8 CctFlashMode;
extern kal_uint32 AwbHwRGain,AwbHwGrGain,AwbHwBGain,AwbHwGbGain;
extern kal_uint32 AwbMinWhitePaxelThr;

/*nvram & customized parameter, declared in Aaa_awb_core.c */
extern kal_uint32 awbThreFast,awbThreMid;
extern kal_uint32 awbSpeedFast,awbSpeedMid,awbSpeedSlow;
extern kal_uint32 awbChangeFrameThr;
extern kal_uint32 awbStableRange;
extern kal_uint32 awbFineTuneGainThr;
extern kal_uint32 awbFineTuneFrameThr;
extern kal_uint32 awbKeepFrameThr;
extern kal_uint32 awbSmFrameNum;
extern kal_uint32 awbChangeStateGainThr;
extern kal_uint32 awbStartFrameNum;

extern kal_uint32 awbStartFrameCnt,awbChangeFrameCnt;
extern kal_uint8  awbWbState,awbPreWbState;
extern kal_uint32 awbLightMode;
extern kal_uint8  awbPoolCnt;
extern kal_uint32 awbSmPoolCnt;
extern kal_uint32 awbQueueRGain[],awbQueueGGain[],awbQueueBGain[];
extern kal_uint32 awbSmQueueRGain[],awbSmQueueGGain[],awbSmQueueBGain[];
extern kal_uint32 awbHistBin1,awbHistBin2;
extern kal_uint32 awbCapTarRGain,awbCapTarGGain,awbCapTarBGain;
extern kal_bool   awbStableFlag;
extern kal_uint8  awbCCMMode;
extern kal_uint32 awbCnt[],awbSumR[],awbSumG[],awbSumB[];
extern kal_uint32 awbPaxelCnt,awbPaxelSumR,awbPaxelSumG,awbPaxelSumB;
extern kal_uint32 awbHistBin1,awbHistBin2;
extern kal_uint32 awbSameHistCnt;
extern kal_uint32 awbFlashRGain,awbFlashGGain,awbFlashBGain;
extern AWB_OPERATION_PARA_STRUCT  AwbOperData;

void AwbMain(void);
void AwbInit(void);
void AwbInitHw(void);
void AwbInitSw(void);
void AwbCcmInitSw(void);
void AwbApplyCcm(kal_uint8 Mode);
void AwbConfigWin(kal_uint16 Width, kal_uint16 Height);
void AwbConfigColorWin(void);
AWB_OPERATION_PARA_STRUCT *get_camera_awb_operation_data(void);
void AwbInitPara(void);
void AwbCheckOperationPara(void);
void AwbExit(void);
void AwbCleanGainBuffer(void);
void AwbSetEnable(kal_bool Flag);
kal_bool AwbIsEnable(void);
void AwbSetFlashModeEn(kal_bool FlashEn);
void AwbSetMode(kal_uint8 Mode);
kal_uint8 AwbGetMode(void);
void AwbSetState(kal_uint8 State);
kal_uint8 AwbGetState(void);
kal_bool AwbGetResult(void);
void AwbUpdateHw(void);
void AwbSetGain(void);
void AwbResetGain(void);
void AwbSetCaptureGain(kal_uint8 Index);
void AwbSetFlashGain(void);
void AwbCaptureStop(void);
void AwbSetManualMethod(kal_uint8 Method) ;
void AwbInitNvramPara(void);

void AwbGetTargetGain(kal_uint32* AwbRGain, kal_uint32* AwbGGain, kal_uint32* AwbBGain);
kal_bool AwbGetStableFlag(void);
void AwbGetRefD65Gain(kal_uint32* AwbRGain, kal_uint32* AwbGGain, kal_uint32* AwbBGain);
void AwbGetRefCwfGain(kal_uint32* AwbRGain, kal_uint32* AwbGGain, kal_uint32* AwbBGain);
void AwbGetRefT84Gain(kal_uint32* AwbRGain, kal_uint32* AwbGGain, kal_uint32* AwbBGain);
void AwbGetRefAlitGain(kal_uint32* AwbRGain, kal_uint32* AwbGGain, kal_uint32* AwbBGain);


void AwbSetMainProcType(AWB_PROC_TYPE_ENUM Type);
AWB_PROC_TYPE_ENUM AwbGetMainProcType(void);
void AwbSetMainProcTypeBak(AWB_PROC_TYPE_ENUM Type);
AWB_PROC_TYPE_ENUM AwbGetMainProcTypeBak(void);
AWB_CCM_STRUCT *AwbGetCCMSetting(void);
void AwbFindGainMax(void);

/*core*/
//void Exif_Update_MTK_para_struct_AWB(exif_MTK_camera_para_struct* para);
void AwbExifUpdateMtkParaStruct(kal_uint32* pPara, kal_uint32 ParaSize);
void AwbChangeLightMode(kal_uint32 OriLightMode, kal_uint32 NewLightMode);
kal_bool AwbGetStatistics(void);
void awbFlashProc(void);

void AwbDynamicCcmProc(kal_uint32 TarRGain, kal_uint32 TarGGain, kal_uint32 TarBGain);
void AwbApplyDynamicCcm(void);
void AwbSetStartStateEndFlag(kal_uint8 Flag);
kal_uint8 AwbGetStartStateEndFlag(void);
void awbSetCCMChangeModeFlag(kal_uint8 Flag);
kal_uint8 AwbGetCcmChangeModeFlag(void) ;
void awbSetCCMMode(kal_uint8 Mode);
kal_uint8 awbGetCCMMode(void);
void AwbCalCcmInitCnt(void);
void AwbInitCcmMode(void);
void AwbResetPrivateVariable(void);
extern void awbSaveLog(char *BufFilename);
extern void FlashAWBSaveLog(char *BufFilename);
extern void AwbSetFastConvergeEnable(kal_uint8 Setting);
extern kal_uint8 AwbGetFastConvergeEnable(void);
extern void AwbSetActualFlashFlag(kal_bool Flag);
extern kal_bool AwbGetActualFlashFlag(void);
extern void AwbBackupStatus(void);
extern kal_bool AwbRestoreStatus(void);
extern void AwbInitOperationPara(IMAGE_SENSOR_INDEX_ENUM SensorIdx,AWB_OPERATION_PARA_STRUCT *oper_data); // SC NV
extern void IspLoad3AToAwb(void);
/*******************************************************************/
// interface for dynamic lsc table
typedef enum
{
	CAMERA_COLOR_TEMP_LO,
	CAMERA_COLOR_TEMP_MD,
	CAMERA_COLOR_TEMP_HI
}CAMERA_COLOR_TEMP_INFO_ENUM;


typedef enum
{
    WB_TUNGSTEN_LSC     = CAMERA_COLOR_TEMP_LO,
    WB_INCANDESCENT_LSC = CAMERA_COLOR_TEMP_LO,
    WB_FLUORESCENT_LSC  = CAMERA_COLOR_TEMP_MD,
    WB_DAYLIGHT_LSC     = CAMERA_COLOR_TEMP_HI,
    WB_CLOUDY_LSC       = CAMERA_COLOR_TEMP_HI,
    WB_STROBE_LSC       = CAMERA_COLOR_TEMP_MD
}AWB_MANUAL_MODE_LSC_TBL_ENUM;


typedef enum
{
    WB_LM_PURE_A_LSC    = CAMERA_COLOR_TEMP_LO,
    WB_LM_PURE_T_LSC    = CAMERA_COLOR_TEMP_LO,
    WB_LM_MIX_A_T_LSC   = CAMERA_COLOR_TEMP_LO,
    WB_LM_PURE_C_LSC    = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_A_C_LSC   = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_T_C_LSC   = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_A_T_C_LSC = CAMERA_COLOR_TEMP_MD,
    WB_LM_PURE_D_LSC    = CAMERA_COLOR_TEMP_HI,
    WB_LM_MIX_A_D_LSC   = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_T_D_LSC   = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_A_T_D_LSC = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_C_D_LSC   = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_A_C_D_LSC = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_T_C_D_LSC = CAMERA_COLOR_TEMP_MD,
    WB_LM_MIX_A_T_C_D_LSC = CAMERA_COLOR_TEMP_MD
}AWB_AUTO_MODE_LSC_TBL_ENUM;


extern CAMERA_COLOR_TEMP_INFO_ENUM AwbGetCtInfo2Lsc(void);
extern CAMERA_COLOR_TEMP_INFO_ENUM AwbCctGetCtInfo2Lsc(void);
extern kal_bool AwbCCTGetAwbCalibration(void);

typedef enum
{
    WB_FLASH_UNIFORM=0x0,
    WB_FLASH_MOST_DARK=0x1,
    WB_FLASH_MOST_BRIGHT=0x2,
    WB_FLASH_VERY_DARK=0x4,
    WB_FLASH_TYPE_NO
}AWB_FLASH_TYPE_ENUM;


#define PURE_FLASH_LUM_THR (4) /*8 bit luminance*/
#define MIX_FLASH_LUM_THR (8) /*8 bit luminance*/
#define DARK_WIN_LUM_THR (4) /*8 bit luminance*/
#define DARK_WIN_NUM_THR (20) /*total 25 windows*/

#define AWB_EM_VIEW_LOG_TIME 2000   // in ms

/* engineer mode interface */
kal_uint32 AwbEmbedMtkInfo(kal_uint32 *pInfo); // api in camera_sec
kal_bool AwbSetEm(AAA_EM_IN_PARA_STRUCT *in_para, AAA_EM_OUT_PARA_STRUCT *out_para);
#endif
//#endif
