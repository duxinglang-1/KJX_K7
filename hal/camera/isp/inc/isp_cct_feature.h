/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *   ISP_CCT_feature.h
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   Definition and declaration for CCT features
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CCT_FEATURE_H__
#define __CCT_FEATURE_H__

#include "Isp_hw_feature_def.h"
#if (defined(DRV_ISP_6238_SERIES)&&defined(ISP_SUPPORT))

#include "kal_release.h"
#include "Mm_comm_def.h"
#include "Cct_comm_def.h"
#include "Aaa_awb.h"
#include "Aaa_ae.h"

MM_ERROR_CODE_ENUM CctFeatureControl(kal_uint32 FeatureId, void *pIspParaIn, void *pIspParaOut);
MM_ERROR_CODE_ENUM CctOpRegRead(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpRegWrite(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpQuerySensor(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetScenarioPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetSensorIdType(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetSensorGroupCount(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetSensorGroupInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetSensorItemInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetSensorItemInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpLoadFromNvram(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSaveToNvram(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraDataSize(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCamera3A(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraDefect1(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraDefect2(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraDefectTbl(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctSetCameraDefect(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbActiveByIndex(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraShading1(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraShading2(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraPca(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
#if (defined(DRV_ISP_PCA_SUPPORT) && defined(__AUTO_SCENE_DETECT_SUPPORT__) )	  
MM_ERROR_CODE_ENUM CctOpGetCameraPca2(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
#endif
MM_ERROR_CODE_ENUM CctOpAeSetShutter(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetShutter(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetSensorPregain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetSensorPregain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetIspId(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpGetEngSensorPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpSetEngSensorPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpGetEngSensorGroupCount(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpGetEngSensorGroupPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpDevGetDscInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpDevAeGetInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpDevAeSetTableIdx(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeSetValue(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpDevAfSetPos(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAfOnOff(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetPeriodPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeSetPeriodPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpDevAeBypassFreeRun(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeSetSceneMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAfGetIsoGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAfSetIsoGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpDevRecoverIsoCapture(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpDevSetIsoCapture(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetIsoValue(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);															
MM_ERROR_CODE_ENUM CctOpAeSetIsoValue(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);																		
MM_ERROR_CODE_ENUM CctOpFlashFlashCharge(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct); 
MM_ERROR_CODE_ENUM CctOpFlashStrobe(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpFlashConfig(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetFlashType(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpFlashLinearityPreStrobe(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspFlashLightSetAePara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspFlashLightGetAePara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspFlashDurationLut(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpFlashGetLinearityResult(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpFlashGetFlashLevel(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);			
MM_ERROR_CODE_ENUM CctOpFlashSetFlashLevel(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);	
MM_ERROR_CODE_ENUM CctOpDevSetFlashAeTableIdx(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpDevGetFlashAeTableIdx(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeEnable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeDisable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeSetSceneMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeSetMeteringMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetCurrentExpoInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeApplyExpoInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeSelectBand(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetAutoExpoPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetIsoValueGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetGammaPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetGammaTable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetFlarePara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeUpdateAutoExpoPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeUpdateIsoValueGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeUpdateGammaPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeUpdateFlarePara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetHistogram(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetMeteringResult(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetMeteringModeSetting(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeUpdateMeteringModeSetting(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetWindowHistogram(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetSmoothModeSetting(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeUpdateSmoothModeSetting(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeEnablePreviewLog(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeDisablePreviewLog(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetPreviewExpoInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbEnablePrefGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbDisablePrefGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbEnableFastConv(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbDisableFastConv(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbEnable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbDisable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbEnableSmallBox(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbDisableSmallBox(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetWinWhiteCnt(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetLightMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbSetGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbSetPrefFactor(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetPrefFactor(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbEnableDynamicCcm(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbDisableDynamicCcm(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetCurrentCcm(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbEnableFlashSync(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbDisableFlashSync(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbApplyCameraPara2(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbUpdateCameraPara2(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetNvramCcm(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbSetNvramCcm(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetAwbPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetCcmPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbUpdateAwbPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbUpdateCcmPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetAwbStatus(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetCcmStatus(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbUpdateAwbStatus(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbUpdateCcmStatus(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbSetCurrentCcm(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);

MM_ERROR_CODE_ENUM CctOpDefectCal(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetShadingPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetShadingPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspEnableDynamicBypass(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspDisableDynamicBypass(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);

MM_ERROR_CODE_ENUM CctOpSetShadingOnOff(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetShadingOnOff(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetCaptureRawBit(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetCapturePreviewSize(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetIspRawCaptureSize(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetSceneMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetMeteringMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetBand(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeSetGammaBypass(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetGammaBypassFlag(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetTuningIndex(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetTuningIndex(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspGetAeTotalGain(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspGetDynamicBypassModeOnOff(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspGetCamcoderInfo(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetDefectOnOff(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAutoDefectEnable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAutoDefectDisable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIsDynamicLscSupport(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetPcaTable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetPcaTable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetPcaPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetPcaPara(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpCheckPcaSupport(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpCheckPca2Support(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetPcaTableIdx(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetPcaTableIdx(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetCcmMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCcmMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetShadingTable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetShadingTable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspGetTuningParas(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctIspUpdateCameraParaFromReg(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIspSetTuningParas(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetGammaParas(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeUpdateGammaParas(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAeGetWindowHistogramData(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbGetAwbParas(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbUpdateAwbParas(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAfGetParas(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAfSetParas(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM ShadingCal(CAL_CCT_BUFFER_STRUCT	*pFrameBuffer);
//MM_ERROR_CODE_ENUM CctOpShadingCal(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpShadingVerify(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpDefectVerify(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpSetAfTestMode(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);	
//MM_ERROR_CODE_ENUM CctOpGetAfLog(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpIsSupported(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
//MM_ERROR_CODE_ENUM CctOpResetDefect(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetShadingTableV3(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetShadingTableV3(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpIsDynamicLSCSupport(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpAwbCaliEnable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpSetLightSource(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCameraParaBuf(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetShadingBuf(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetDefectBuf(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CctOpGetCamera3ABuf(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CDTSetBinningModeEnable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);
MM_ERROR_CODE_ENUM CDTSetBinningModeDisable(CAL_CCT_FEATURE_CTRL_STRUCT *pFeatureStruct);

/*******************************************************************/
/* cct api - ae */
void AeCctGetCurrentExpInfo(CAL_CCT_AE_CURRENT_EXPO_INFO_STRUCT *pAeCurrentExpo);
void AeCctApplyCurrentExpInfo(const CAL_CCT_AE_APPLY_EXPO_INFO_STRUCT *pAeCurrentExpo);
void AeCctGetAutoExpoPara(CAL_CCT_AE_EXPO_SETTING_STRUCT *pAeExpoPara);
void AeCctGetIsoValueGain(CAL_CCT_AE_ISO_LUT_STRUCT *pAeIsoPara);
void AeCctGetGammaPara(CAL_CCT_AE_GAMMA_SETTING_STRUCT *pAeGammaPara);
void AeCctGetFlarePara(CAL_CCT_AE_FLARE_SETTING_STRUCT *pAeFlarePara);
void AeCctUpdateAutoExpoPara(const CAL_CCT_AE_EXPO_SETTING_STRUCT *pAeExpoPara);
void AeCctUpdateIsoValueGain(const CAL_CCT_AE_ISO_LUT_STRUCT *pAeIsoPara);
void AeCctUpdateGammaPara(const CAL_CCT_AE_GAMMA_SETTING_STRUCT *pAeGammaPara);
void AeCctUpdateFlarePara(const CAL_CCT_AE_FLARE_SETTING_STRUCT *pAeFlarePara);
void AeGetFlareHistogram(kal_uint32 *pCount, kal_uint32 *pHistogram);
void AeCctGetMeteringResult(CAL_CCT_AE_CURRENT_METERING_RESULT_STRUCT *pAeMeteringResult);
void AeCctGetMeteringModeSetting(CAL_CCT_AE_METERING_SETTING_STRUCT *pAeMeteringSetting);
void AeCctUpdateMeteringModeSetting(const CAL_CCT_AE_METERING_SETTING_STRUCT *pAeMeteringSetting);
void AeCctGetWindowHistogram(kal_uint32 *pWindowPixel, kal_uint32 *pWindow, kal_uint32 *pHistogram);
void AeCctGetSmoothModeSetting(kal_uint8 Mode, aeSmoothModeStruct*pAeSmoothSetting);
void AeCctUpdateSmoothModeSetting(kal_uint8 Mode, const aeSmoothModeStruct *pAeSmoothSetting);
void AeCctEnablePreviewLog (kal_bool EnableFlag);
void AeCctGetPreviewExpoInfo(CAL_CCT_AE_OUTPUT_CURRENT_AE_INFO_STRUCT *pAeInfo);
void AeCctGetGammaTable(CAL_CCT_AE_GAMMA_TABLE_STRUCT *pAeGammaPara);
void AeCctConfigCaptureSetting(void);

/*******************************************************************/
/* cct api - awb */
CAMERA_COLOR_TEMP_INFO_ENUM AwbCctGetCtInfo2Lsc(void);
void AwbCctSetLightSource(CCT_LIGHT_SOURCE_ENUM LightSrc);
CCT_LIGHT_SOURCE_ENUM AwbCctGetLightSource(void);
void AwbCctSetAwbCalibration(kal_bool Enable);
kal_bool AwbCctGetAwbCalibration(void);
void AwbCctPrefGainEn(kal_bool Enable);
void AwbCctFastConvergeEn(kal_bool Enable);
void AwbCctAutoRunEn(kal_bool Enable);
void AwbCctSmallBoxEn(kal_uint32 Light, kal_bool Enable);
kal_uint32 *AwbCctGetWindowCntPointer(void);
kal_uint32 AwbCctGetLightMode(void);
CAL_CCT_AWB_GAIN_STRUCT *AwbCctGetAwbGain(void);
void AwbCctSetAwbGain(kal_uint16 RGain, kal_uint16 GGain, kal_uint16 BGain );
void AwbCctSetPreferenceFactor(CAL_CCT_AWB_PREF_FACTOR_STRUCT *pCctAwbPreference);
CAL_CCT_AWB_PREF_FACTOR_STRUCT *AwbCctGetPreferenceFactor(void);


void AwbCctDynamicCcmEn(kal_bool Enable);
CAL_CCT_CCM_STRUCT *AwbCctGetCurrentCcm(void);
void AwbCctSetCurrentCcm(CAL_CCT_CCM_STRUCT cctCCMFactor);

void AwbCctFlashSyncEn(kal_bool enable);
CAL_CCT_CCM_STRUCT *AwbCctGetNvramCcm(kal_uint8 Mode);
void AwbCctSetNvramCcm(kal_uint8 mode, CAL_CCT_CCM_STRUCT CCM);
AWB_PARA_STRUCT *AwbCctGetAwbPara(void);
CCM_PARA_STRUCT *AwbCctGetCcmPara(void);
void AwbCctUpdataAwbPara(AWB_PARA_STRUCT *Awb); 
void AwbCctUpdataCcmPara(CCM_PARA_STRUCT *Ccm);
void AwbCctGetAwbStatus(CAL_CCT_AWB_STATUS_STRUCT *pAwbStatus);
void AwbCctGetCcmStatus(CAL_CCT_CCM_STATUS_STRUCT *pCcmStatus);
void AwbCctUpdateAwbStatus(CAL_CCT_AWB_STATUS_STRUCT *pAwbStatus);
void AwbCctUpdateCcmStatus(CAL_CCT_CCM_STATUS_STRUCT *pCcmStatus);
void AwbCctSetCcmMode(kal_uint8 Mode);
void AwbCctGetCcmMode(CCM_MODE_ENUM *Mode);
/*******************************************************************/

#endif //(defined(DRV_ISP_6238_SERIES)&&defined(ISP_SUPPORT))

#endif 
