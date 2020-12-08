/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  aaa_ae.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   This file is intends for AE Interface.
 *
 * Author:
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __AAA_AE_H__
#define __AAA_AE_H__

#include "kal_release.h"
#include "exif.h"
#include "aaa_process.h"
#include "isp_comm_def.h"
#include "sensor_comm_def.h"
#include "cct_comm_def.h"
#include "aaa_nvram.h"

#define AE_WIND_ASSERT_ENABLE 0
#define AE_FAST_EXPO_APPLY 1

/* global definition */
#define ISP_AE_ISP_GAIN_BASE 0x40
#define ISP_AE_ISP_GAIN_SHIFT 6
#define ISP_AE_ISP_GAIN_MAX 0xFF
#define ISP_AE_WIND_REG_NO 20
#define ISP_AE_WIND_AF_REG_NO 5
#define ISP_AE_HIST_FLARE_REG_NO 10
#define ISP_AE_HIST_CCM_REG_NO 64
#define ISP_AE_WIND_SIZE_SCALE 10
#define ISP_AE_HISTOGRAM_H_SCALE 16
#define ISP_AE_HISTOGRAM_H_SCALE_SHIFT 4
#define ISP_AE_HISTOGRAM_V_SCALE 8
#define ISP_AE_HISTOGRAM_V_SCALE_SHIFT 3
#define ISP_AE_HISTOGRAM_COUNT_SCALE 48
#define ISP_AE_HISTOGRAM_MAX_OFFSET 511
#define ISP_RAW_WINDOW_SCALE 16
#define ISP_RAW_WINDOW_REG_NO 4
#define ISP_AE_WIND_COUNT_SHIFT 2
#define ISP_AE_FLARE_HIST_H_SHIFT 2
#define ISP_AE_FLARE_HIST_V_SHIFT 1
#define ISP_AE_FLARE_HIST_NUM 3
#define ISP_AE_WIND_REG_CAL_NO 5
#define ISP_HISTOGRAM_MAX_VALUE 255
/* Ev compensation */
#define ONE_STEP    1
#define TWO_STEP    2
#define THREE_STEP    3
#define FOUR_STEP   4

/* local definition */
#define DEFAULT_TARGET  90
#define DEFAULT_EV_COMP_STEP  9
#define DEFAULT_EV_COM  4
#define DEFAULT_SHUTTER 300
#define DEFAULT_FAST_ENABLE KAL_FALSE
#define DEFAULT_AE_INDEX  40

/* ae metering definition */
#define AE_MAX_WIND_NO 25
#define AE_MAX_AF_WIND_NO 5
#define AE_MAX_FLARE_HIST_NO 10
#define AE_MAX_CCM_HIST_NO 64
#define AE_FLARE_HIST_STEP 2
#define AE_CCM_HIST_STEP 4

/* unit gain definition */
#define HISTOGRAM_COMP_UNIT_GAIN 256
#define FLARE_UNIT_GAIN 128
#define FLARE_UNIT_GAIN_SHIFT 7
#define FLARE_MAX_GAIN 255

#define GAIN_COMP_UNIT_GAIN 128
#define GAIN_COMP_UNIT_GAIN_SHIFT 7
#define GAIN_COMP_MAX_GAIN 255

#define RAW_GAIN_UNIT_GAIN 128

/* max input value definition */
#define AE_MIN_VALUE 1
#define AE_MAX_VALUE 255
#define RAW_MAX_VALUE 1023
#define FLARE_OFFSET_RATIO 4
#define FLARE_OFFSET_RATIO_SHIFT 2
#define OB_BINNING_RATIO 4
#define OB_BINNING_SHIFT 2

/* new */

/* ae state count */
#define CAM_AE_STATE_DO_NOTHING 0x0
#define CAM_AE_STATE_CAL_CYCLE 0x1
#define CAM_AE_STATE_SHUTTER_CYCLE 0x2
#define CAM_AE_STATE_SENSOR_GAIN_CYCLE 0x4
#define CAM_AE_STATE_ISP_GAIN_CYCLE 0x8

#define GAMMA_STEP_NO 20
#define AE_TOTAL_GAMMA_NO 5

#define AE_EV_COMP_SHIFT 7
#define AE_EV_COMP_UNIT_GAIN 128
#define EV_LUT_RATIO_BASE 256
#define AE_EV_COMP_STEP 5

/* gamma enhance gain */
#define AE_GAMMA1_SAT_M 131
#define AE_GAMMA1_SAT_N 128
#define AE_GAMMA2_SAT_M 135
#define AE_GAMMA2_SAT_N 128
#define AE_GAMMA3_SAT_M 139
#define AE_GAMMA3_SAT_N 128
#define AE_GAMMA4_SAT_M 141
#define AE_GAMMA4_SAT_N 128

enum
{
    CAM_AE_MAIN_LISR_HISR=0,
    CAM_AE_MAIN_TASK,
    CAM_AE_MAIN_MODE_NO
};

enum
{
    CAM_AE_MAIN_NORMAL = 0,
    CAM_AE_MAIN_WAIT_STABLE_FRAME,
    CAM_AE_MAIN_DEVICE_BYPASS_MODE,
    CAM_AE_MAIN_NO_OF_CONTEXT_MODE
};

enum
{
    CAM_AE_CAL_WAIT_CAL=0,
    CAM_AE_CAL_END_EXPO,
    CAM_AE_CAL_ISP_GAIN_READY,
    CAM_AE_CAL_SENSOR_GAIN_READY,
    CAM_AE_CAL_SHUTTER_READY,
    CAM_AE_CAL_BUSY,
    CAM_AE_CAL_MODE_NO
};

enum
{
    AE_BYPASS_DISABLE=0,
    AE_BYPASS_EXPOSURE_UPDATE,
    AE_BYPASS_EXPOSURE_READY,
    AE_BYPASS_EXPOSURE_DO,
    AE_BYPASS_EXPOSURE_END,
    AE_BYPASS_DISPLAY_MODE_NO
};

enum
{
    AE_BRACKET_0 =0,
    AE_BRACKET_1,
    AE_BRACKET_2,
    AE_BRACKET_MODE_NO
};

enum
{
    CAM_AE_BINNING_ACC=0,
    CAM_AE_BINNING_AVG,
    CAM_AE_BINNING_MODE_NO
};

enum
{
    AE_RESTORE_SEQUENCT=0,
    AE_RESTORE_ONE_TIME,
    AE_RESTORE_MODE_NUM
};

/* old */
#if 0
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

/* ae new */
typedef struct
{
    kal_uint8 DscMode;
    kal_bool  VideoMode;
} AE_CUSTOM_INFO_STRUCT, *P_AE_CUSTOM_INFO_STRUCT;

typedef struct
{
    kal_uint16 AeExposureWindowStartX;
    kal_uint16 AeExposureWindowStartY;
    kal_uint16 AeExposureWindowWidth;
    kal_uint16 AeExposureWindowHeight;
    kal_uint16 AeResultWindowStartX;
    kal_uint16 AeResultWindowStartY;
    kal_uint16 AeResultWindowWidth;
    kal_uint16 AeResultWindowHeight;
} AE_WINDOW_HISTOGRAM_STRUCT, *P_AE_WINDOW_HISTOGRAM_STRUCT;

typedef struct
{
    /* new */
    kal_uint8 AeFirstFrameCount;
    kal_uint8 AeWaitFrameCount;
    kal_uint8 AeEndFrameCount;
    kal_uint8 AeWaitCountStartFlag;
    /* period count */
    kal_uint8 AeCount;
    /* offset when AE lut changed */
    kal_uint8 AeRawOb;
    /* preview set */
    kal_uint8 AePreviewIdx;
    kal_uint16 AePreviewShutter;
    kal_uint16 AePreviewSensorGain;
    kal_uint8 AePreviewIspGain;
    kal_uint8 AePreviewGammaNo;
    kal_uint8 AePreviewFlareOffset;
    /* capture set */
    kal_uint8 AeCaptureIdx;
    kal_uint16 AeCaptureShutter;
    kal_uint16 AeCaptureSensorGain;
    kal_uint8 AeCaptureIspGain;
    kal_uint8 AeCaptureGammaNo;
    kal_uint8 AeCaptureFlareOffset;
    /* bypass flag  index */
    kal_uint8 AeBypassFlag;
    kal_uint8 AeBypassIdx;
    kal_uint16 AeBypassShutter;
    kal_uint16 AeBypassSensorGain;
    kal_uint8 AeBypassIspGain;
    /* common buffer */
    kal_uint8 AeCalCompleteFlag;
    kal_uint8 AeCallbackDisableFlag;
    /* table offset */
    kal_int16 AeLutOffset;
    /* ae callback ptr */
    void (*pfAeHisrCallback) (kal_uint32 return_code);
    /* check flag */
    kal_bool AeFastEnabled;
    kal_bool AeFisrtInitFlag;
    kal_bool AeCctRecordEnableFlag;
    kal_uint8 AeUniformScene;
    kal_uint8 AeFastMode;
    /* ev comp */
    kal_uint8 AeEvCompDev;
    kal_uint16 AeEvCompGainM;
    kal_uint16 AeEvCompGainCaptureM;
    /* binning capture mode */
    kal_uint8 AeCaptureBinningMode;
    /* ev limiter */
    kal_uint8 AeCaptureEvLimitEnable;
    kal_uint8 AeCaptureLastIdx;
    kal_uint8 AeCaptureLastOriIdx;
    /* new for ASD check */
    kal_bool    AeIsBacklitScene;
    kal_int8    AeFaceEnhanceEv;
} AE_APPLY_EXPO_STRUCT, *P_AE_APPLY_EXPO_STRUCT;

typedef struct
{
    /* common */
    kal_uint8 AeShutterDelay;
    kal_uint8 AeSensorGainDelay;
    kal_uint8 AeIspGainDelay;
    kal_uint8 AeCalDelay;
    kal_uint8 AePeriodNo;
    kal_uint8 AeWaitStableCycle;
    kal_uint16 AeCaptureShutterCompensteMaxGain;
    kal_uint8 AeCaptureShutterCompensateEnable;
    kal_uint8 AeCaptureDelayFrame;
    kal_uint8 AeBracketEvStep;
    kal_uint8 AeVideoMeteringMode;
}AE_CAMERA_OPERATION_PARA_STRUCT, *P_AE_CAMERA_OPERATION_PARA_STRUCT;

typedef struct
{
    kal_uint32 AeSmoothMode;
} AE_CAMERA_OPER_PARA_CUSTOM_MODE_STRUCT, *P_AE_CAMERA_OPER_PARA_CUSTOM_MODE_STRUCT;

typedef struct
{
    kal_uint8 AeSelectSceneMode;
    kal_uint8 AeSelectMeteringMode;
    kal_uint8 AeSelectEvCompNo;
    kal_bool  AeBracketEnable;
    kal_uint8 AeBracketLevel;
    kal_bool AeSelectCaptureBinningEnable;
    kal_uint8 AeCaptureEffect;
    void (*pfAeHisrCallback) (kal_uint32 return_code);
} AE_METERING_MMI_STRUCT, *P_AE_METERING_MMI_STRUCT;

typedef struct
{
    kal_uint16  AeIndex;
    kal_uint16  AeShutter;
    kal_uint16  AeSensorGain;
    kal_uint16  AeIspGain;
    kal_uint8   AeIspPreviewGammaNo;
    kal_uint8   AeIspPreviewFlareOffset;
    kal_uint8   AeIspCaptureGammaNo;
    kal_uint8   AeIspCaptureFlareOffset;
    kal_uint8   AeUniformScene;
    kal_uint8   AeFastMode;
    kal_uint8   AeEvCompDev;
    kal_uint16  AeEvCompGainM;
    kal_bool    AeIsBacklitScene;   /* new for ASD */
    kal_int8    AeFaceEnhanceEv;
} AE_EXPOSURE_RESULT_STRUCT, *P_AE_EXPOSURE_RESULT_STRUCT;

/* for CCT read out current AE exposure */
#if 0 // move to cct_comm_def.h
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
#if 0 // move to aaa_flash_v2.h
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
/* exif for preview para */
typedef struct
{
    kal_uint16  DzRatio;
    kal_uint32  SensorClk;
    kal_uint16  PixelNo;
    kal_uint16  CaptureExpoLines;
    kal_uint32  CaptureExpoTimeM;
    kal_uint32  CaptureExpoTimeN;
} EXIF_PREVIEW_PARA_INFO_STRUCT, *P_EXIF_PREVIEW_PARA_INFO_STRUCT;

/* object or face para */
typedef struct
{
    kal_uint8 ObjNo;
    kal_uint8 ObjLum;
}AE_OBJ_DATA_STRUCT, *P_AE_OBJ_DATA_STRUCT;

/* old extern */
extern const AE_EXPOSURE_LUT_STRUCT *AE_LUT;
extern const kal_uint8 *IRIS_LUT;
const AE_EXPOSURE_LUT_STRUCT *get_ae_lut(AE_LUT_INFO_STRUCT info);
const kal_uint8 *get_iris_lut(AE_LUT_INFO_STRUCT info);

/* extern variable */
extern kal_uint32 AeHistFlareBuffer[ISP_AE_HIST_FLARE_REG_NO];
extern kal_uint32 AeWindBuffer[AE_MAX_WIND_NO];
extern kal_uint32 AeWindBufferPre[AE_MAX_WIND_NO];
extern kal_uint32 AeWindowPixelCountBuffer;
extern kal_uint32 AeHistFlareBuffer[ISP_AE_HIST_FLARE_REG_NO];
extern kal_uint32 AeHistCcmBuffer[ISP_AE_HIST_CCM_REG_NO];
extern AE_WINDOW_HISTOGRAM_STRUCT AeStatisticsWindow;
extern AE_METERING_MMI_STRUCT AeMeteringMmi;
extern AE_CAMERA_OPER_PARA_CUSTOM_MODE_STRUCT AeCameraOperModeData;
extern kal_uint32 AeHistCcmCount;
extern kal_uint32 AeHistFlareCount;
extern kal_uint8 AeGamma[AE_TOTAL_GAMMA_NO][GAMMA_STEP_NO];
extern const kal_uint8 AeGammaIndex[GAMMA_STEP_NO];
extern AE_LUT_INFO_STRUCT lut_info;
extern AE_CAMERA_OPERATION_PARA_STRUCT AeApplyPeriodSetting;
extern kal_uint32 AeWindBufferAvgHistoryLast;
extern kal_uint32 AeWindBufferAvgHistoryCurrent;
extern kal_uint32 AeWindBufferAvgHistoryNew;
extern kal_uint32 AeWindBufferCwmHistoryLast;
extern kal_uint32 AeWindBufferCwmHistoryCurrent;
extern kal_uint32 AeWindBufferCwmHistoryNew;
extern kal_uint32 AeWindBufferAvgCompLast;
extern kal_uint32 AeWindBufferAvgCompCurrent;
extern kal_uint32 AeWindBufferCwmCompLast;
extern kal_uint32 AeWindBufferCwmCompCurrent;
extern kal_uint32 AeFrameIdx;//frame index
extern AE_APPLY_EXPO_STRUCT AeApplyBuffer;

/* Init function */
kal_uint8 AeInit(void);
kal_uint8 AeInitPara(void);
kal_uint8 AeConfigCustomPara(void);
/* main process */
kal_uint8 AeMain(kal_uint8 mode);
kal_uint8 AePreviewStop(void);
kal_uint8 AePreviewStable(void);
/* control function */
void AeSetEnable(kal_bool AeFlag);
kal_bool AeIsEnable(void);
void AeSelectBand(kal_uint8 AeBand);
kal_uint8 AeGetBand(void);
void AeSetFastConvergeEnable(kal_bool FastFlag);
kal_bool AeGetFastConvergeEnable(void);
void AeSetBypassModeEnable(kal_bool EnableFlag);
void AeSetBypassIdx(kal_uint8 BypassIdx);
kal_uint8 AeGetBypassIdx(void);
void AeSetBypassMode(kal_uint8 mode);
kal_bool AeIsBypasIdxExposureEnd(void);
void AeBypassStable(kal_bool en);
kal_uint8 AeSetWaitFrameStart(void);
kal_bool AeIsWaitFrameEnd(void);
kal_bool AeIsWaitFrameAwbStart(void);
kal_uint8 AeSetSceneMode(kal_uint8 SceneMode);
kal_uint8 AeGetSceneMode(void);
kal_uint8 AeSetMeteringMode(kal_uint8 mode);
kal_uint8 AeGetMeteringMode(void);
kal_uint8 AeSetBinningEnable(kal_bool EnableFlag);
kal_bool AeGetBinningEnable(void);
kal_bool AeIsSettingChange(void);
void AeBackupStatus(void);
kal_bool AeRestoreStatus(kal_uint8 mode);
void AeSetVideoFrameRate(kal_uint16 FrameRate);
/* common routine */
kal_uint8 AeGetStatistic(void);
kal_bool AeIsConverge(void);
kal_uint16 AeGetBandingBaseShutter(void);
void AeSetIspPregain(kal_uint8 gain);
kal_uint8 AeGetIspPregain(void);
void AeSetSensorGain(kal_uint16 gain);
kal_uint16 AeGetSensorGain(void);
kal_uint16 AeGetSensorGainLast(void);
void AeSetIspFlareOffset(kal_uint32 FlareOffset, kal_uint32 FlareGain);
void AeSetIspFlareGainOffset(kal_uint32 FlareOffset, kal_uint32 RawOb,
                              kal_uint32 CompGain, kal_bool ForceUpdateFlag);
void AeSetIspFlareGain(kal_uint32 FlareGain);
kal_uint8 AeGetIspGammaNo(void);
void AeSetIspGammaNo(kal_uint8 GammaNo);
kal_uint8 AeGetIspFlareGain(void);
kal_uint8 AeGetIspFlareGainComp(void);
kal_uint8 AeGetIspFlareOffset(void);
kal_uint32 AeGetTotalGain(void);
kal_uint32 AeGetIsoValue(kal_uint32 SensorGain, kal_uint8 IspGain);
kal_uint32 AeGetCaptureIsoValue(void);
kal_uint32 AeGetPreviewIsoValue(void);
kal_uint8 AeGetAeExpIdx(void);
void AeSetAeExpIdx(kal_uint8 idx);
kal_uint8 AeSetEvComp(kal_uint8 level);
kal_int8 AeGetEvComp(void);
kal_uint8 AeGetExpoValue(void);
void AeSetExpoValue(kal_uint16 value);
kal_uint8 AeGetTotalEvLevel(void);
void AeSetShutter(kal_uint16 lines);
kal_uint16 AeGetShutter(void);
kal_uint16 AeGetShutterLast(void);
kal_uint32 AeCalExifISOSpeed(void);
/* custom interface */
kal_uint8 AeGetEnvIdx(void);
kal_uint32 AeGetLumInfo(void);
void AeSetLumInfo(kal_uint32 value);
kal_uint32 AeGetAeApplyExpIdx(void);
kal_uint8 AeGetAeApplyCompExpIdx(void);
kal_int32 AeCalClippingDelatEv(kal_int32 DeltaIdx);

/* api in media_sec */
kal_uint8 aeProc(AE_EXPOSURE_RESULT_STRUCT *pAeResultBuffer);
void aeUpdateCalIspGain(kal_uint32 IspGain);
kal_uint8 aeCalCenterWeightEnvIdx(void);
kal_bool aeCalDynamicMeteringIsUniform(void);
kal_uint8 aeCalCctGammaMean(void);
kal_uint8 aeCalLogClear(void);
kal_uint8 aeCalParaUpate(void);
kal_int32 aeCalDeltaEv(kal_uint32 gain_m, kal_uint32 gain_n, kal_int32 Ev_idx);
kal_uint8 aeCalUpdateWindBufferCwm(void);
kal_uint32 aeCalEvGainNum(kal_int32 DeltaIdx);
void aeSaveLog(char *buf_filename);
/********************/

kal_uint8 AeSetCurrentExpoInfoMeteringEv(kal_int32 DevIdx);
kal_uint8 AeGetCurrentExpoInfo(AE_OUTPUT_CURRENT_AE_INFO_STRUCT *pAeInfo);

kal_uint8 AeCaptureStop(void);
/* Ae state count for hisr apply */
kal_uint32 AeGetCurrentAeStateCount(void);
/* self init for test */
kal_uint8 AeSelfInitWindNvram(void);

void AeSetModePara(kal_uint8 SceneMode, kal_bool VideoMode, AE_CAMERA_OPER_PARA_CUSTOM_MODE_STRUCT *pAeOperModeData);
/* awb api */
kal_uint8 AeGetCenterWeightEnvIdx(void);
kal_bool AeMeteringIsUniform(void);
kal_uint8 AeCalAwbHistRatio(kal_uint32 HigPos, kal_uint8 LowPos, kal_uint8 *pHighRatio, kal_uint8 *pLowRatio);
kal_uint8 AeCalAwbMaxMeanEv(void);
kal_uint8 AeCalAwbOverMeanCount(kal_uint8 mean);
kal_uint32 AeCalAwbTotalHistCount(void);
kal_uint8 AeCalAwbHistCount(kal_uint8 size, kal_uint32 *pResult);
kal_uint32 AeCalAwbHistAboveEvCount(kal_uint8 EvIdx);

kal_uint32 AeGetAeApplyPeriod(void);
kal_uint8 AeGetLoopLog(void);
kal_uint8 AeGetRawOb(void);
kal_uint8 AeGetCaptureFlareGain(void);
kal_uint8 AeGetCaptureIdx(void);
AE_APPLY_EXPO_STRUCT *AeGetApplyBuffer(void);
kal_uint8 AeApplyPreviewExpoIdx(void);

kal_uint32 AeCalEvGainDenom(void);
kal_uint8 AeGetGammaMeanInfo(void);
void AeSetGammaMeanInfo(kal_uint8 value);
kal_uint8 AeGetMeteringRuleInfo(void);
void AeSetMeteringRuleInfo(kal_uint8 value);
kal_bool AeGetGammaBypassFlag(void);
void AeSetGammaBypass(kal_bool flag);
kal_uint8 AeGetIspCaptureFlareOffset(void);
kal_uint8 AeGetIspCaptureGammaNo(void);

/* aaa process */
kal_uint8 AeConfigWin(kal_uint16 GrabW, kal_uint16 GrabH, kal_uint16 ResultStartX, kal_uint16 ResultStartY,
                        kal_uint16 ResultW, kal_uint16 ResultH);
kal_bool AeUpdateWin(kal_uint16 GrabW, kal_uint16 GrabH, kal_uint16 ResultStartX, kal_uint16 ResultStartY,
                        kal_uint16 ResultW, kal_uint16 ResultH);
kal_uint8 AeConfigCaptureCompensate(kal_bool AeBraketingEnable, kal_uint8 ExpoBracketLevel,
                        kal_bool BinningEnable, kal_uint8 ImageEffect);
kal_uint8 AeApplyCaptureExpoIdx(void);
kal_uint8 AeGetIspPreviewFlareOffset(void);
kal_uint8 AeGetIspPreviewGammaNo(void);
kal_uint8 AeUpdateExpoLut(void);
void AeSetParaChange(void);
kal_bool AeReadClearParaChange(void);
kal_uint8 AeCalUpdateWindBufferAvg(void);
kal_uint8 AeCopyPreviewExpoToCaptureExpo(void);

kal_uint8 AeGetVideoMeteringMode(void);
kal_uint8 AeGetBinningMode(void);
AE_OBJ_DATA_STRUCT *AeGetObjData(void); /* new for object or face interface */
void AeExifUpdateMtkParaStruct(kal_uint32 *pPara, kal_uint32 ParaSize);

#if (defined(EXIF_SUPPORT))
void ExifUpdatePreviewPara(void);

void ExifSetCaptureShutter(kal_uint16 lines);
#endif

/* engineer mode interface */
kal_uint32 AeEmbedMtkInfo(kal_uint32 *pInfo); // api in camera_sec
kal_bool AeSetEm(AAA_EM_IN_PARA_STRUCT *pInPara, AAA_EM_OUT_PARA_STRUCT *pOutPara); // api in camera_sec
/***************************/

void flashAeSaveLog(char *buf_filename);

/* new interface for ASD */
kal_bool AeIsStable(void);
kal_bool AeIsBacklit(void);
kal_int8 AeGetFaceEnhanceEv(void);

/****************AAA_AE_PARA_H*************************/
#define BASEGAIN 0x40
#define BASEGAIN_SHIFT 6
#define GAMMA_FAST_LUT_SHIFT 2
//#define AE_TOTAL_GAMMA_NO 5
//#define GAMMA_STEP_NO 20
#define MAX_FLARE_OFFSET 20

/* tuning param. for AE v3 */
typedef struct
{
    kal_uint8 target_mean;
    kal_uint8 init_expo_idx;
    /* capture flare offset cal */
    kal_uint8 flare_fix_flag; 
    kal_uint8 flare_fix_offset;
    kal_uint8 flare_search_dn_ratio;
    kal_int8  flare_min_offset;
    /* preview & video gamma no */
    kal_uint8 preview_gamma_no;
    kal_uint8 preview_flare_offset;
    /* ev to seperate indoor & outdoor */
    kal_uint8 indoor_outdoor_ev;
    /* highlight suppress para. */
    kal_uint8 highlight_ratio;
    kal_uint8 highlight_threshold;
    kal_uint8 reserve_3;
    /* shadow stretch para. */
    kal_uint8 shadow_ratio;
    kal_uint8 shadow_threshold;
    kal_uint8 shadow_weight;
    /* brightness stretch para. */
    kal_uint8 brightness_ratio;
    kal_uint8 brightness_threshold_indoor;
    kal_uint8 brightness_threshold_outdoor;
    /* max central mean bound */
    kal_uint8 max_central_mean_indoor;
    kal_uint8 max_central_mean_outdoor;
    /* fast gamma lut for gamma mean */
    kal_uint8 gamma_lut[AE_TOTAL_GAMMA_NO][GAMMA_FAST_LUT_NO];
    kal_uint8 reserve;/* padding for keeping the same size */
    kal_uint8 reserve_2;/* version number */
}aeMeteringCommV3Struct;

/* ISO priority */
/*
typedef struct
{
    kal_uint16  IsoGain[MAX_ISO_LUT_NO];
    kal_uint16  IsoValue[MAX_ISO_LUT_NO];
}aeIsoLutStruct;
*/

/* cct */
#if 0   // move to cct_comm_def.h
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
/* other file API */
/* isp comm */
nvram_ae_para_struct *AeGetPara(void);
void AeSetMeteringCommSet(const aeMeteringCommStruct *pCamAddr);
void AeGetMeteringCommSet(aeMeteringCommStruct *pCamAddr);
void AeSetSmoothModeSet(const aeSmoothModeStruct *pCamAddr, kal_uint8 mode);
void AeGetSmoothModeSet(aeSmoothModeStruct *pCamAddr, kal_uint8 mode);
void AeSetIsoInfo(const aeIsoLutStruct *pCamAddr);
void AeGetIsoInfo(aeIsoLutStruct *pCamAddr);
/* old api */
void ae_on_off(kal_bool flag);
kal_uint8 ae_get_stepperev(void);
void ae_select_stepperev(kal_uint8 step);
kal_uint8 ae_get_totalevlevel(void);
kal_uint8 ae_set_ev(kal_int8 level);
void ae_set_expovalue(kal_uint8 target);
kal_int8 ae_get_ev_level(void);
kal_uint8 ae_get_expovalue(void);
void ae_set_ini_shutter(kal_uint16 shutter);
kal_uint16 ae_get_ini_shutter(void);
void ae_set_shutter(kal_uint16 lines);
kal_uint16 ae_get_current_shutter(void);
void ae_awb_main(void);
/* cct api */
void AeCctGetCurrentExpInfo(AE_CCT_CURRENT_EXPO_INFO_STRUCT *pAeCurrentExpo);
void AeCctApplyCurrentExpInfo(const AE_CCT_APPLY_EXPO_INFO_STRUCT *pAeCurrentExpo);
void AeCctGetAutoExpoPara(AE_CCT_EXPO_SETTING_STRUCT *pAeExpoPara);
void AeCctGetIsoValueGain(CAL_CCT_AE_ISO_LUT_STRUCT *pAeIsoPara);
void AeCctGetGammaPara(AE_GAMMA_SETTING_STRUCT *pAeGammaPara);
void AeCctGetFlarePara(AE_FLARE_SETTING_STRUCT *pAeFlarePara);
void AeCctUpdateAutoExpoPara(const AE_CCT_EXPO_SETTING_STRUCT *pAeExpoPara);
void AeCctUpdateIsoValueGain(const CAL_CCT_AE_ISO_LUT_STRUCT *pAeIsoPara);
void AeCctUpdateGammaPara(const AE_GAMMA_SETTING_STRUCT *pAeGammaPara);
void AeCctUpdateFlarePara(const AE_FLARE_SETTING_STRUCT *pAeFlarePara);
void AeGetFlareHistogram(kal_uint32 *pCount, kal_uint32 *pHistogram);
void AeCctGetMeteringResult(AE_CCT_CURRENT_METERING_RESULT_STRUCT *pAeMeteringResult);
void AeCctGetMeteringModeSetting(AE_CCT_METERING_SETTING_STRUCT *pAeMeteringSetting);
void AeCctUpdateMeteringModeSetting(const AE_CCT_METERING_SETTING_STRUCT *pAeMeteringSetting);
void AeCctGetWindowHistogram(kal_uint32 *pWindowPixel, kal_uint32 *pWindow, kal_uint32 *pHistogram);
void AeCctGetSmoothModeSetting(kal_uint8 Mode, aeSmoothModeStruct *pAeSmoothSetting);
void AeCctUpdateSmoothModeSetting(kal_uint8 Mode, const aeSmoothModeStruct *pAeSmoothSetting);
void AeCctEnablePreviewLog(kal_bool EnableFlag);
void AeCctGetPreviewExpoInfo(AE_OUTPUT_CURRENT_AE_INFO_STRUCT *pAeInfo);
void AeCctGetGammaTable(AE_GAMMA_TABLE_STRUCT *pAeGammaPara);
void AeCctConfigCaptureSetting(void);
/* move from isp_device_v2.h */
kal_uint8 AeCctSetAeIdx(AE_LUT_INFO_STRUCT AeLutInfo, kal_uint8 Idx);
kal_uint8 AeCctBypassFreerunProcess(P_AE_CCT_BYPASS_FREERUN_STRUCT pFreerunPara, P_AE_CCT_BYPASS_FREERUN_RESULT_STRUCT pFreerunResult);
kal_bool AeCctGetIsoGain(kal_uint16 Gain[3]);
kal_bool AeCctSetIsoGain(const kal_uint16 Gain[3]);
kal_bool AeCctGetIsoValue(kal_uint16 Value[3]);
kal_bool AeCctSetIsoValue(const kal_uint16 Value[3]);
kal_bool AeCctRestoreIsoCapture(void);
kal_bool AeCctSetIsoCapture(kal_uint8 Select);
/***********************************************/

#endif /* __AAA_AE_H__ */
